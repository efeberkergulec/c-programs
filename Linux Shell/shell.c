/*******************************\
 * CMPE 382: OPERATING SYSTEMS *
 * PROJECT: 1				   *
 * AUTHOR: Efe Berk ERGULEC	   *
\*******************************/ 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h> 
#define NUM_THREADS 25

// Scans my string and founds occurence of a character.
int scan_string(char *string, char param) {
	int c = 0;
	int res = 0;
	while(string[c] != '\0') {
		int i = (int) string[c];
		if(i == (int) param) {
			res++;
		}
		c++;
	}
	
	return res;
}

// Thread commands executes there
void *execute_command(void *vargp) {
	char *command = (char *) vargp;
	int i = system(command);
	if (i == -1) {
		printf("There isn't any command called %s\n", command);
	}
	
	pthread_exit(NULL);
}

// Function that sends threads to pthread.
// It also seperates threads from processes. 
void send_to_threads(char *process) {
	pthread_t threads[NUM_THREADS];
	int thrnum = scan_string(process, ';');
	int exit_cond = 0;
	int rc;
	char *ptr = strtok(process, ";");
	char **thread_arr = (char **)malloc((thrnum++ + 1) * sizeof(char *));

	int i = 0;
	while(ptr != NULL){
		thread_arr[i] = (char *)malloc(100 * sizeof(char));
		strcpy(thread_arr[i], ptr);
		// printf("Thread %d = %s\n", i + 1, thread_arr[i]);
		if(!strcmp(thread_arr[i], "quit"))	exit_cond = 1;
		ptr = strtok(NULL, ";");
		i++;
	}
	
	for(int i = 0; i < thrnum; i++) {
		rc = pthread_create(&threads[i], NULL, execute_command, (void *)thread_arr[i]);
		pthread_join(threads[i], NULL);
		if (rc) {
            printf("ERROR; return code from pthread_create() is %d\n", rc);
            exit(-1);
       }
	}

	if(exit_cond)	exit(0);
}

// Seperates line to processes.
void seperate_processes(char *line) {
	int cols = scan_string(line, '|');
	char *ptr = strtok(line, "|");
	char **process_arr = (char **)malloc((cols++ + 1) * sizeof(char *));

	int i = 0;
	while(ptr != NULL){
		process_arr[i] = (char *)malloc(100 * sizeof(char));
		strcpy(process_arr[i], ptr);
		// printf("Process %d = %s\n", i + 1, process_arr[i]);
		ptr = strtok(NULL, "|");
		i++;
	}	

	for(int i = 0; i < cols; i++) {
		if (process_arr[i] != NULL) {
			send_to_threads(process_arr[i]);
		}
	}
}

// Main function.
int main(int argc, char *argv[]) {
	char input[255];
	FILE* batch;

	system("clear");

	printf("/-----------------------------------------------\\\n");
	printf("|            Welcome to my terminal!            |\n");
	printf("\\-----------------------------------------------/\n");

	// BATCH MODE: Allows multiple file entry.
	if(argv[1] != NULL) {
		int a = 1;
		while(argv[a] != NULL) {
			int b = 1;
			char buff[512];
			batch = fopen(argv[a], "r");
			while(fgets(buff, sizeof(buff), batch) != NULL) {
				printf("Line %d for File %d: %s", b, a, buff);
				send_to_threads(buff);
				printf("\n");
				b++;
			}
			printf("********** END OF FILE %d **********\n", a);
			a++;
			fclose(batch);
		}
		
	}
	// INTERACTIVE MODE: Our classic mode.
	else {
		while(1) {
			printf("prompt> ");
			gets(input);
			seperate_processes(input);
		}
		system("clear");
	}
	return 0;
}

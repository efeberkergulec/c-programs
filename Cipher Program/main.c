#include <stdio.h>
#include "CipherMethods.h"
#define TRACE_ORG_DEC (str1,str2) strcmp(str1,str2)
int main(void)
{
	char text[500];
	char passcode[8] = "cmpe252";
	char *new_text;
	char *return_text;
	char isWanted;
	char pText[8];
	int choose;

	printf("**You are about to enter a very secret cryptography**\n**service called CMPE252 C-Secret-Coded System**\nEnter your text:\n");
	scanf("%[^\n]s",text);
	printf("%s\n",text);
	printf("*********************\n 1> Ceaser Cipher\n 2> Vigenere Cipher\n*********************\nPlease enter a cipher type:\n");
	scanf("%d",&choose);

	if(choose == 1)
	{
		new_text = encryptCaesar(text);
		system("clear");
		
		printf("In order to see the encrypted message, enter your passcode:\n");
		scanf("%s",pText);
		if(strcmp(passcode,pText) != 0)
		{
			for(int i = 1;i <= 2; i++)
			{
				printf("Wrong passcode. Enter again:\n");
				scanf("%s",pText);
				if(strcmp(passcode,pText) == 0)
				break;	
			}
			if(strcmp(passcode,pText) != 0)
			{
				printf("Number of allowed attempts has been reached without succesfull entry!\nYour IP has been blocked by our us. Good luck!!\n");
				exit(1);
			}
		}
		printf("Cipher:");
		printf("%s\n",new_text);
		printf("\nWould you like to convert the cipher to original text?(Y/N)\n");
		scanf(" %c",&isWanted);
	
		if(isWanted == 'Y' || isWanted == 'y')
		{
			return_text = decryptCaesar(new_text);
			printf("%s\n",return_text);
			if(strcmp(text,return_text) == 0)
				puts("Original text and the decrypted text match.");
		}
	}
	else if(choose == 2)
        {       
                new_text = encryptVigenere(text);
                system("clear");
        	
                printf("In order to see the encrypted message, enter your passcode:\n");
                scanf("%s",pText);
                if(strcmp(passcode,pText) != 0)
                {
                        for(int i = 1;i <= 2; i++)
                        {
                                printf("Wrong passcode. Enter again:\n");
                                scanf("%s",pText);
                                if(strcmp(passcode,pText) == 0)
                                break;  
                        }
                        if(strcmp(passcode,pText) != 0)
                        {
                                printf("Number of allowed attempts has been reached without succesfull entry!\nYour IP has been blocked by our us. Good luck!!\n");
                                exit(1);
                        }
                }
		printf("\n");
		printf("Cipher:");
                printf("%s\n",new_text);
                printf("\nWould you like to convert the cipher to original text?(Y/N)\n");
                scanf(" %c",&isWanted);

                if(isWanted == 'Y' || isWanted == 'y')
                {
                        return_text = decryptVigenere(new_text);
                        printf("%s\n",return_text);
                        if(strcmp(text,return_text) == 0)
                                puts("Original text and the decrypted text match.");
                }
        }
	return 0;
}

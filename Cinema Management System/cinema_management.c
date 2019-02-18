#include <stdio.h>
#include <stdlib.h>
#define STRLEN 20
#define SHORTS 5

typedef struct{
    int film_id;
    char name[STRLEN];
    char format[SHORTS];
    char date[STRLEN];
    char time[STRLEN];
    int price;
    int capacity;
}filmData;

void menu(void);
void convertTextFile(FILE *fPtr);
void addRecord(FILE *fPtr);
void deleteRecord(FILE *fPtr);
void sellTicket(FILE *fPtr);
void showRecords(FILE *fPtr);

int input;

int main(void)
{
    while(1)
    {
        menu();
    }

}

void menu(void)
{
    filmData films[100];
    FILE *inp;
    inp = fopen("film.bin","rb");

    printf("\nCINEMA MANAGEMENT SYSTEM\n");
    printf("1 - add a new film\n");
    printf("2 - remove film\n");
    printf("3 - Sell Ticket\n");
    printf("4 - print list of film\n");
    printf("5 - save as txt file\n");
    printf("6 - end program\n");
    printf("\nENTER A CHOICE =>");
    scanf("%d",&input);
    printf("\n");
    
    switch(input)
        {
        case 1:
            addRecord(inp);
            break;
        case 2:
            deleteRecord(inp);
            break;
        case 3:
            sellTicket(inp);
            break;
        case 4:
            showRecords(inp);
            break;
        case 5:
            convertTextFile(inp);
            break;
        case 6:
            exit(0);
        default:
            printf("Wrong input!");
            break;
        }
}

void convertTextFile(FILE *fPtr)
{
    filmData film;
    FILE *outp;
    outp = fopen("film.txt","w+");
    
    for(int i = 0; i < 100; i++)
    {
        
        fread(&film,sizeof(filmData),1,fPtr);
        if(film.film_id != 0)
        {
            //fwrite(outp,"%d %s %s %s %s %d %d\n",film.film_id,film.name,film.format,film.date,film.time,film.price,film.capacity);
        }
    }
}

void addRecord(FILE *fPtr)
{
    filmData film;
    
    printf("\nEnter id to create a new record:\n");
    scanf("%d",&film.film_id);
    printf("Film Name:\n");
    scanf("%s",film.name);
    printf("Format:\n");
    scanf("%s",film.format);
    printf("Show Date:\n");
    scanf("%s",film.date);
    printf("Show Time:\n");
    scanf("%s",film.time);
    printf("Price");
    scanf("%d",&film.price);
    printf("Seating Capacity: *n");
    scanf("%d",&film.capacity);
    

}
void deleteRecord(FILE *fPtr)
{
    
}

void sellTicket(FILE *fPtr)
{
    int capacity, dh;
    filmData film;
    printf("Enter id to update capacity of film\n");
    scanf("%d",&capacity);
    fseek(fPtr,(capacity - 1) * sizeof(filmData), SEEK_SET);
    printf("ID No   Film Name   Format    Show Date   Show Time     Price  Capacity\n");
    fwrite(&film,sizeof(filmData),1,fPtr);
    printf("How many tickets is sold: \n");
    
}

void showRecords(FILE *fPtr)
{
    filmData film;
    printf("ID No   Film Name   Format    Show Date   Show Time     Price  Capacity\n");
    
    for(int i = 0; i < 100; i++)
    {
        
        fread(&film,sizeof(filmData),1,fPtr);
        if(film.film_id != 0)
        {
            printf("%d %s %s %s %s %d %d\n",film.film_id,film.name,film.format,film.date,film.time,film.price,film.capacity);
        }
    }
    
    printf("\n******************************************\n");
}

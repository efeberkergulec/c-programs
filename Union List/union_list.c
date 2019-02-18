#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <ctype.h>

/**
 Given two arrays of pointers to strings which contains name and surname as in the format of "name,surname",
	1 . find the union strings of two given name&surname list and print them.
	2 . separate the strings according to "," caharacter and print the names and surnames in format of "Surname Name".
**/

void unionlist(char* a1[], char* a2[], int size1, int size2)
{
    char *unionset[9];
    int c = 0;
    for(int i = 0; i < 7; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            if(strcmp(a1[i],a2[j])!=0)
            {
                unionset[c] = a1[i];
                c++;
            }
        }
    }

    for(int i = 0; i < size2; i++)
    {
        unionset[c+size2] = a2[i];
    }

    printf("Union of array of pointers to strings Name&Surname\n");
    printf("--------------------------------------------------\n");

    for(int count = 0; count < 9;count++)
    {
        printf("Name&Surname %d : %s\n",(count+1),unionset[count]);
    }
    printf("\nSurname&Name");
    printf("------------");

    for(int count = 0; count < 9;count++)
    {
        printf("Surname&Name %d : %s\n",(count+1),unionset[count]);
    }
}


int main(void)
{
    char p1[] = "zoe,lang";
    char p2[] = "sam,rodriguez";
    char p3[] = "jack,alonso";
    char p4[] = "david,studi";
    char p5[] = "denzel,feldman";
    char p6[] = "james,bale";
    char p7[] = "james,willis";
    char p8[] = "michael,loaf";
    char p9[] = "dustin,vin";

	char group1[] = {p1,p4,p9,p3,p2,p8,p5};
	char group2[] = {p9,p5,p1,p6,p7};

    unionlist(group1,group2,7,5);

    return 0;
}

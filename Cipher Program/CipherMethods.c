#include "CipherMethods.h"

char *encryptCaesar(const char *org_text)
{
	int len =strlen(org_text);
	char c;
	char *new_text = (char *)malloc(len * sizeof(char));
	for(int i = 0; i < len; i++)
	{
        	c = org_text[i];
		if(c >= 'a' && c <= 'z')
		{
            		c = c + CAESAR_SHIFT;
            		if(c > 'z')
			{
                		c = c - 'z' + 'a' - 1;
            		}
           		 new_text[i] = c;
        	}
        	else if(c >= 'A' && c <= 'Z')
		{
            		c = c + CAESAR_SHIFT;
            		if(c > 'Z')
			{
                		c = c - 'Z' + 'A' - 1;
            		}       
            		new_text[i] = c;
        	}
		else if(c == ' ')
                        new_text[i] = c	;
    	}
	return new_text;
}

char *decryptCaesar(const char *cip_text)
{
	int len =strlen(cip_text);
	char c;
	char *new_text = (char *)malloc(len * sizeof(char));
        for(int i = 0; i < len; i++)
	{
        	c = cip_text[i];
		if(c >= 'a' && c <= 'z')
		{
            		c = c - CAESAR_SHIFT;
            		if(c < 'a')
			{
                		c = c + 'z' - 'a' + 1;
            		}
            		new_text[i] = c;
        	}
        	else if(c >= 'A' && c <= 'Z')
		{
            		c = c - CAESAR_SHIFT;
            		if(c < 'A')
			{
                		c = c + 'Z' - 'A' + 1;
            		}
            		new_text[i] = c;
        	}
		else if(c == ' ')
                        new_text[i] = c;
    	}
	return new_text;
}

extern char *encryptVigenere(const char *org_text)
{
	char key[]="CMPE";
	int len =strlen(org_text);
        char c;
        char *new_text = (char *)malloc(len * sizeof(char));
	char *keylen = (char *)malloc(len * sizeof(char));
	
	for(int i = 0;i < strlen(key); i++)
		keylen[i] = key[i];

	for(int i = strlen(key);i < len; i++)
                keylen[i] = key[i % 4];	

        for(int i = 0; i < len; i++)
        {
                c = org_text[i];
                if(c >= 'a' && c <= 'z')
                {
                        c = (c + keylen[i]) % NUMBER_OF_LETTERS + 'a';
                        if(c > 'z')
                        {
                                c = c - 'z' + 'a' - 1;
                        }
                         new_text[i] = c;
                }
                else if(c >= 'A' && c <= 'Z')
                {
                        c = (c + keylen[i]) % NUMBER_OF_LETTERS + 'A';
                        if(c > 'Z')
			{
				c = c - 'Z' + 'A' - 1;
                        }
                        new_text[i] = c;
                }
		else if(c == ' ')
			new_text[i] = c;
        }
        return new_text;
}

extern char *decryptVigenere(const char *cip_text)
{
	char key[]="CMPE";
        int len =strlen(cip_text);
        char c;
        char *new_text = (char *)malloc(len * sizeof(char));
        char *keylen = (char *)malloc(len * sizeof(char));

        for(int i = 0;i < strlen(key); i++)
                keylen[i] = key[i];

        for(int i = strlen(key);i < len; i++)
                keylen[i] = key[i % 4];

        for(int i = 0; i < len; i++)
        {
                c = cip_text[i];
                if(c >= 'a' && c <= 'z')
                {
                        c = (c - key[i % 4] + NUMBER_OF_LETTERS) % NUMBER_OF_LETTERS + 'a';
                        if(c > 'z')
                        {
                                c = c - 'z' + 'a' - 1;
                        }
                         new_text[i] = c;
                }
                else if(c >= 'A' && c <= 'Z')
                {
                        c = (c - key[i % 4] + NUMBER_OF_LETTERS) % NUMBER_OF_LETTERS + 'A';
                        if(c > 'Z')
                        {
                                c = c - 'Z' + 'A' - 1;
			}
                        new_text[i] = c;
                }
		else if(c == ' ')
                        new_text[i] = c;
        }
        return new_text;
}


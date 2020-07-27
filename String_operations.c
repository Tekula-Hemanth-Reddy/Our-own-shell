#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>



void search(char string[])
{
	char ch;
	int i;
	printf("\nenter element to be searched");
	scanf("%c",&ch);
	for(i=0;string[i]!='\0';i++)
	{
		if(ch==string[i])
		{
			printf("\npresent");
			break;
		}
	}
	if(string[i]=='\0')
	{
		printf("\nnot present");
	}
}

void sort(char string[])
{
	char chTemp;
	int i,j;
	for(i=0; string[i]!='\0'; i++)
    {
        for(j=0; string[i]!='\0'; j++)
        {
            if(string[j]>string[j+1])
            {
                chTemp = string[j];
                string[j] = string[j+1];
                string[j+1] = chTemp;
            }
        }
    }
    for(i=0; string[i]!='\0'; i++)
    {
    	printf("%c",string[i]);
    }
}

void reverse(char string[])
{
	int i,j;
	for(i=0; string[i]!='\0'; i++)
    {
    }
    char array[i];
    j=i-1;
    for(i=0; j>=0; i++,j--)
    {
    	array[i]=string[j];
    }
    array[i]='\0';
    for(i=0; array[i]!='\0'; i++)
    {
    	printf("%c",array[i]);
    }
}

void frequency(char string[])
{
	int i,c=0;
	char ch;
	printf("\nenter element ");
	scanf("%c",&ch);
	for(i=0;string[i]!='\0';i++)
	{
		if(ch==string[i])
		{
			c=c+1;
		}
	}
	printf("\nfrequency of %c is %d",ch,c);
}

void String_Operations(char *ch)
{
	char string[1000];
	printf("enter a String");
	gets(string);
	if(strcmp(ch,"search"))
	{
		search(string);
	}
	else if(strcmp(ch,"sort"))
	{
		sort(string);
	}
	else if(strcmp(ch,"length"))
	{
		printf("string length %d",strlen(string));
	}
	else if(strcmp(ch,"reverse"))
	{
		reverse(string);
	}
	else if(strcmp(ch,"frequency"))
	{
		frequency(string);
	}
}

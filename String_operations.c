#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

// String operations such as length,reverse,sort,search,frequency

void search(char string[])
{
	char ch,ch1;
	int i;
	printf("\nenter element to be searched");
	scanf("%c",&ch1);
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
   	char temp;
   int i,j;
   int n = strlen(string);
   printf("String before sorting - %s \n", string);

   for (i = 0; i < n-1; i++) {
      for (j = i+1; j < n; j++) {
         if (string[i] > string[j]) {
            temp = string[i];
            string[i] = string[j];
            string[j] = temp;
         }
      }
    }
	printf("String after sorting - %s \n", string);

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
	char ch,ch1;
	printf("\nenter element ");
	scanf("%c",&ch1);
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

void String_Operations(char ch[])
{
	char string[1000];
	printf("enter a String");
	scanf("%s",string);
	if(strcmp(ch,"sea")==0)
	{
		search(string);
	}
	else if(strcmp(ch,"srt")==0)
	{
		sort(string);
	}
	else if(strcmp(ch,"len")==0)
	{
		printf("string length %d",strlen(string));
	}
	else if(strcmp(ch,"rev")==0)
	{
		reverse(string);
	}
	else if(strcmp(ch,"fre")==0)
	{
		frequency(string);
	}
}

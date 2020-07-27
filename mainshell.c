#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<readline/readline.h>
#include<limits.h>
#include <unistd.h>
#include <dirent.h>
#define clear() printf("\033[H\033[J")

#include "String_operations.c"
#include "arithemeticoperations.c"
#include "Basic_Operations.c"
#include "arrayoperations.c"

void init_shell() 
{ 
    printf("\n\n\n\n\t\t\t****************************************************************************************************"); 
    printf("\n\n\n\t\t\t\t\t\t   ****Aditya's Hemanth's SHELL****"); 
   char* username = getenv("USER"); 
    printf("\n\n\nUSER is: @%s", username); 
    printf("\n"); 
    sleep(05);  
} 
void HelpFunction()
{
	printf("\n clc		: Clears the command prompt");
	printf("\n ls		: List all the files present in the Directory");
	printf("\n cd		: To change the directory");
	printf("\n cwd      	: Current Working Directory");
	printf("\n mkdir    	: To create a Directory");
	printf("\n ari		: Arithematic Operations");
	printf("\n string		: String Operations");
	printf("\n basic		: Basic Operations");
	printf("\n array		: Array Operations");
	printf("\n color 		: Formatting the Text to different colors");
	printf("\n exit		: Exit from the command prompt\n");			
}
void checkfun(char *str)
{
	if(strcmp(str,"help")==0)
	{
		HelpFunction();
	}
	else if(strcmp(str,"clc")==0)
	{
		clear();
	}
	else if(strcmp(str,"string")== 0)
	{
		char iistr[20];
		printf("\n len		: Length of the String");
		printf("\n srt		: Sort the String");
		printf("\n sea		: Search the given Character in String");
		printf("\n rev		: Reverse the String");
		printf("\n fre		: Frequency of a Charecter\n");
		printf(" back		: No required function\n");
		printf(">>>");
		scanf("%s",iistr);
		if((strcmp(iistr,"len")==0) || (strcmp(iistr,"srt")==0) || (strcmp(iistr,"sea")==0) || (strcmp(iistr,"rev")==0) || (strcmp(iistr,"fre")==0))
		{
			String_Operations(iistr);
		}
		else if(strcmp(iistr,"back")== 0){}
		else
		{
			checkfun(iistr);
		}
		printf("\n");
	}
	else if(strcmp(str,"basic")== 0)
	{
		char iistr[20];
		printf("\n fact		: Factorial of a number");
		printf("\n pow		: Power of a number");
		printf("\n sqr		: Square of a number");
		printf("\n sqrt		: Square Root of a number");
		printf("\n gcd		: GCD of any given numbers");
		printf("\n lcm		: LCM of any given numbers");
		printf("\n gre		: Greatest of any given numbers");
		printf("\n sml		: Smallest of any given numbers");
		printf("\n nat		: Nature of the number (even or odd)\n");
		printf(" back		: No required function\n");
		printf(">>>");
		scanf("%s",iistr);
		if((strcmp(iistr,"fact")==0) || (strcmp(iistr,"pow")==0) || (strcmp(iistr,"sqr")==0) || (strcmp(iistr,"sqrt")==0) || (strcmp(iistr,"gcd")==0) || (strcmp(iistr,"lcm")==0) || (strcmp(iistr,"gre")==0) || (strcmp(iistr,"nat")==0) || (strcmp(iistr,"sml")==0))
		{
			Basic_Operations(iistr);
		}
		else if(strcmp(iistr,"back")== 0){}
		else
		{
			checkfun(iistr);
		}
		printf("\n");
	}
	else if(strcmp(str,"ari")== 0)
	{
		char iistr[20];
		printf("\n add		: Add two numbers");
		printf("\n sub		: Subtract two numbers");
		printf("\n mul		: Multiply two numbers");
		printf("\n div		: Divide two numbers\n");
		printf(" back		: No required function\n");
		printf(">>>");	
		scanf("%s",iistr);
		if((strcmp(iistr,"add")==0) || (strcmp(iistr,"sub")==0) || (strcmp(iistr,"mul")==0) || (strcmp(iistr,"div")==0))
		{
			Arithemeticfunctions(iistr);
		}
		else if(strcmp(iistr,"back")== 0){}
		else
		{
			checkfun(iistr);
		}		
	}
	else if(strcmp(str,"array")==0)
	{
		char iistr[20];
		printf("\n asum		: Sum of the given Numbers");
		printf("\n asrt		: Sort the given Numbers");
		printf("\n asea		: Search the given Number");
		printf("\n afre		: Frequency of a Number");
		printf("\n amax		: Maximum of the given Numbers");
		printf("\n amin		: Minimum of the given Numbers\n");
		printf(" back		: No required function\n");
		printf(">>>");
		scanf("%s",iistr);
		printf("\n");
		if((strcmp(iistr,"asum")==0) || (strcmp(iistr,"asrt")==0) || (strcmp(iistr,"asea")==0) || (strcmp(iistr,"afre")==0) || (strcmp(iistr,"amax")==0) || (strcmp(iistr,"amin")==0))
		{
			Array_Functions(iistr);
		}
		else if(strcmp(iistr,"back")== 0){}
		else
		{
			checkfun(iistr);
		}	
	}
	else if(strcmp(str,"exit")==0)
	{
		exit(0);
	}
	else if(strcmp(str,"cwd")==0)
	{
		char cwd1[PATH_MAX];
	
		if (getcwd(cwd1, sizeof(cwd1)) != NULL) 
		{
				printf("Current working dir: %s\n", cwd1);
		} 
		else 
		{
				perror("getcwd() error");
		}
	}
	else if(strcmp(str,"ls")==0)
	{
		DIR *d;
		struct dirent *dir;
		d = opendir(".");
		if (d)
		{
			while ((dir = readdir(d)) != NULL)
			{
				printf("%s\n", dir->d_name);
			}
			closedir(d);
		}
	}
	else if(strcmp(str,"cd")==0)
	{
		char iistr[50];
		char cwd1[PATH_MAX];
		if (getcwd(cwd1, sizeof(cwd1)) != NULL){}
		else 
		{
				perror("getcwd() error");
		}
		printf("Enter the destination folder");
		scanf("%s",iistr);
		if(strcmp(iistr,"..")==0)
		{
			chdir("..");
		}
		else
		{
			strcat(cwd1,"//");
			chdir(strcat(cwd1,iistr));
		}
	}
	else if(strcmp(str,"mkdir")==0)
	{
		int check; 
		char dirname[50];
		printf("Enter the Directory name:-\n");
		scanf("%s",dirname);
		check = mkdir(dirname); 
		if (!check) 
			printf("Directory created\n"); 
		else 
		{ 
			printf("Unable to create directory\n"); 			 
		}
	}
	else if(strcmp(str,"color")==0)
	{
		printf("\n red		: Red");
		printf("\n gre		: Green");
		printf("\n blu		: Blue");
		printf("\n yel		: Yellow");
		printf("\n whi		: White");
		printf("\n brd		: BoldRed");
		printf("\n mag		: Magneta");
		printf("\n cya		: Cyan\n");
		char iistr[20];
		printf(" back		: No desired color\n");
		printf(">>>");
		scanf("%s",iistr);
		if(strcmp(iistr,"red")==0)
		{
			printf("\033[0;31m");
		}
		else if(strcmp(iistr,"blu")==0)
		{
			printf("\033[0;34m");
		}
		else if(strcmp(iistr,"yel")==0)
		{
			printf("\033[0;33m");
		}
		else if(strcmp(iistr,"cya")==0)
		{
			printf("\033[0;36m");
		}
		else if(strcmp(iistr,"brd")==0)
		{
			printf("\033[1;31m");
		}else if(strcmp(iistr,"mag")==0)
		{
			printf("\033[0;35m");
		}else if(strcmp(iistr,"gre")==0)
		{
			printf("\033[0;32m");
		}else if(strcmp(iistr,"whi")==0)
		{
			printf("\033[0m");
		}
		else if(strcmp(iistr,"back")==0){}
		else
		{
			checkfun(iistr);
		}
	}
	else
	{
		printf("\n Please Enter a Valid Command\n");
	}
}
int input(char *str) 
{ 
    char* buf;  
    buf = readline(">>>"); 
    if (strlen(buf) != 0) { 
        strcpy(str, buf); 
		checkfun(str);
        return 0; 
    } else { 
        return 1; 
    } 
}
int main()
{
	clear();	
	init_shell();
	char inpstr[1000];
	while(1)
	{
		input(inpstr);
	}
	return 0;
}


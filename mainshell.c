#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<readline/readline.h>

#include "String_operations.c"
#include "Page_Replacement.c"
#include "arithemeticoperations.c"
#include "CPU_Scheduling.c"
#include "Basic_Operations.c"
#include "arrayoperations.c"

void init_shell() 
{ 
    
    printf("\n\n\n\n******************"
        "************************"); 
    printf("\n\n\n\t****Aditya's Hemanth's SHELL****"); 
   char* username = getenv("USER"); 
    printf("\n\n\nUSER is: @%s", username); 
    printf("\n"); 
    sleep(10); 
   
} 

int input(char *str) 
{ 
    char* buf; 
  
    buf = readline("$"); 
    if (strlen(buf) != 0) { 
        add_history(buf); 
        strcpy(str, buf); 
		//checkfun(str);
        return 0; 
    } else { 
        return 1; 
    } 
}



int main()
{
	
	//need to intialise the shell
	init_shell();
	
	//after the intialising of the shell the user gives the command
	
	char inpstr[1000];
	
	
	while(1)
	{
		input(inpstr);
	}
	return 0;
}


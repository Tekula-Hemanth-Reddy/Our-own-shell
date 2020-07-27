#include<stdio.h>

//do it

void division(double a,double b)
{
	printf("Quotient is %lf Remainder is %lf\n",a/b,a%b);
}
void multiplication(double a,double b)
{
	printf("Product is %lf\n",a*b);
}

void addition(double a,double b)
{
	printf("Sum is %lf\n",a+b);
}
void substraction(double a,double b)
{
	printf("Difference is %lf\n",a-b);
}

void modulo(double a,double b)
{
	printf("Modulo is %lf\n",a%b);
}

void Arithemeticfunctions(char *str)
{
	double a;
	double b;
	
	printf("Enter the First Number\n");
	scanf("%ld",&a);
	
	printf("Enter the Second Number\n");
	scanf("%ld",&b);
	
	
	if((strcmp(str,"add"))==0)
	{
		addition(a,b);
	}
	
	else if((strcmp(str,"subtract"))==0)
	{
		substraction(a,b);
	}
	
	else if((strcmp(str,"multiply"))==0)
	{
		multiplication(a,b);
	}
	
	else if((strcmp(str,"divide"))==0)
	{
		division(a,b);
	}
	
	else if((strcmp(str,"modulo"))==0)
	{
		modulo(a,b);
	}
	
	
	
}
	


#include<stdio.h>
#include<math.h>

//for Arithemetic operations like Addition,Substraction,Division,Multiplication

void division(double a,double b)
{
	printf("Quotient is %lf \n",a/b);
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

void Arithemeticfunctions(char str[])
{
	double a;
	double b;
	
	printf("Enter the First Number\n");
	scanf("%lf",&a);
	
	printf("Enter the Second Number\n");
	scanf("%lf",&b);
	
	
	if((strcmp(str,"add"))==0)
	{
		addition(a,b);
	}
	
	else if((strcmp(str,"sub"))==0)
	{
		substraction(a,b);
	}
	
	else if((strcmp(str,"mul"))==0)
	{
		multiplication(a,b);
	}
	
	else if((strcmp(str,"div"))==0)
	{
		division(a,b);
	}
	
}
	


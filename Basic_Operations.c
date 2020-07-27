#include<stdio.h>
#include<math.h>

void factorial()
{
	int n,i,p=1;
	printf("\n enter number");
	scanf("%d",&n);
	for(i=0;i<=n;i++)
	{
		p=p*i;
	}
	printf("\n factorial of %d is %d",n,p);
	
}

void power()
{
	int b,e,i,r=1;
	printf("\n enter base : ");
	scanf("%d",&b);
	printf("\n enter power : ");
	scanf("%d",&e);
	for(i=0;i<e;i++)
	{
		r=r*b;
	}
	printf("%d^%d = %d",b,e,r);
}

void square()
{
	int n,i;
	printf("\n enter element : ");
	scanf("%d",&n);
	i=n*n;
	printf("square of %d is %d",n,i);
	
}

void squareroot()
{
	int n;
	float i;
	printf("\n enter element : ");
	scanf("%d",&n);
	i=sqrt(n);
	printf("square of %d is %f",n,i);
	
}

void gcd()
{
	int n,i;
	int j;
    int minimum;
    int GCD;
    int temp;
	printf("\n enter no.of elements : ");
	scanf("%d",&n);
	int array[n];
	for(i=0;i<n;i++)
	{
		printf("enter element %d",(i+1));
		scanf("%d",&array[i]);
		if(i==0)
		{
			minimum=array[0];
		}
		else
		{
			if(minimum>array[i])
			{
				minimum=array[i];
			}
		}
		
	}

    for (i=1; i < minimum/2; i++)
    {
        for (j = 0; j < n;j++)
        {
            GCD = 2*i;
            temp = ((array[j])/(GCD));
            int check = temp%1;
            if (check == 0)
                break;
        }
    }

    printf("\nThe Greates Common Devisor is: %d", GCD);

	
}

void lcm()
{
	int n,i;
	int j;
    int maximum;
    int LCM;
    int temp;
	printf("\n enter no.of elements : ");
	scanf("%d",&n);
	int array[n];
	for(i=0;i<n;i++)
	{
		printf("enter element %d",(i+1));
		scanf("%d",&array[i]);
		if(i==0)
		{
			maximum=array[0];
		}
		else
		{
			if(maximum<array[i])
			{
				maximum=array[i];
			}
		}
		
	}

	LCM=maximum;
    while(1)
    {
        for (j = 0; j < n;j++)
        {
            if(LCM%array[i]!=0)
            {
            	break;
			}
        }
        if(j==n)
        {
        	break;
		}
		LCM=LCM+1;
    }

    printf("\nThe Least Common Multiple is: %d", LCM);

	
}

void evenodd()
{
	int n;
	printf("\n enter element : ");
	scanf("%d",&n);
	if(n%2==0)
	{
		printf("\n%d is even",n);
	}
	else
	{
		printf("\n%d is odd",n);
	}
	
}


void greater()
{
	int first,second;
	printf("\n enter first element : ");
	scanf("%d",&first);
	printf("\n enter second element : ");
	scanf("%d",&second);
	if(first>second)
	{
		printf("\n Yes %d is greater than %d",first,second);
	}
	else
	{
		printf("\n No %d is not greater than %d",first,second);
	}
}

void smaller()
{
	int first,second;
	printf("\n enter first element : ");
	scanf("%d",&first);
	printf("\n enter second element : ");
	scanf("%d",&second);
	if(first<second)
	{
		printf("\n Yes %d is smaller than %d",first,second);
	}
	else
	{
		printf("\n No %d is not smaller than %d",first,second);
	}
}

void Basic_Operations(char *str)
{
	if(strcmp(str,"factorial")==0)
	{
		factorial();
	}
	else if((strcmp(str,"power"))==0)
	{
		power();
	}
	else if((strcmp(str,"square"))==0)
	{
		square();
	}
	else if((strcmp(str,"squareroot"))==0)
	{
		squareroot();
	}
	else if((strcmp(str,"gcd"))==0)
	{
		gcd();
	}
	else if((strcmp(str,"lcm"))==0)
	{
		lcm();
	}
	else if((strcmp(str,"evenodd"))==0)
	{
		evenodd();
	}
	else if((strcmp(str,"greater"))==0)
	{
		greater();
	}
	else if((strcmp(str,"smaller"))==0)
	{
		smaller();
	}
}

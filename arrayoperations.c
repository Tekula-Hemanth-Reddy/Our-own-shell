#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

// for operations on array such as minimum,maximum,sort,find..

void sumofarrayelements(int *arr,int n)
{
	int i;
	int sum=0;
	for(i=0;i<n;i++)
	{
		sum=sum+arr[i];
	}
	
	printf("The sum of array elements is %d\n",sum);
}

void maxofarrayelements(int *arr,int n)
{
	int i;
	int max=arr[0];
	for(i=1;i<n;i++)
	{
		if(max < arr[i])
		{
			max=arr[i];
		}
	}
	
	printf("The maximum of array elements is %d\n",max);
}

void minofarrayelements(int *arr,int n)
{
	int i;
	int min=arr[0];
	for(i=1;i<n;i++)
	{
		if(min > arr[i])
		{
			min=arr[i];
		}
	}
	
	printf("The minimum of array elements is %d\n",min);
}


void search_array_element_linearsearch(int *arr,int n,int search_element)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(arr[i]==search_element)
		{
			printf("Element Found");
			break;
		}
	}
	if(i==n)
	{
		printf("Element Not Found");
	}
}

int comp(const void *a,const void *b)
{
	int x=*(int *)a;
	int y=*(int *)b;
	return x > y;
}


void sort_of_elements(int *arr,int n)
{
	
	qsort(arr,n,sizeof(int),comp);
	
	int i;
	printf("Printing the elements in the sorted Order\n");
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}

void frequency_of_an_element(int *arr,int n,int ele_req)
{
	int i;
	int count=0;
	for(i=0;i<n;i++)
	{
		if(arr[i]==ele_req)
		{
			count++;
		}
	}
	printf("The frequency of %d is %d",ele_req,count);
}

void Array_Functions(char str[])
{
	
	printf("Enter the number of elements of the Array");
	int n,i;
	scanf("%d",&n);
	
	int *arr=(int *)malloc(n * sizeof(int));
	printf("Enter the %d elements",n);
	
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	
		
	
	if((strcmp(str,"asum"))==0)
	{
		sumofarrayelements(arr,n);	
	}

	
	else if((strcmp(str,"asea"))==0)
	{
		printf("Enter the element that you wanted to search\n");
		int ele;
		scanf("%d",&ele);
		
		search_array_element_linearsearch(arr,n,ele);
	}
	
	else if((strcmp(str,"amin"))==0)
	{
		minofarrayelements(arr,n);
	}
	
	else if((strcmp(str,"amax"))==0)
	{
		maxofarrayelements(arr,n);
	}
	
	else if((strcmp(str,"asrt"))==0)
	{
		sort_of_elements(arr,n);
	}
	
	else if((strcmp(str,"afre"))==0)
	{
		printf("Enter the element that you wanted to search\n");
		int ele;
		scanf("%d",&ele);
		
		frequency_of_an_element(arr,n,ele);
		
	}
	
}
	
	
		
		








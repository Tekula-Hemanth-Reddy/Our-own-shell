	
	#include<stdio.h>

	void optimal()
	{
		int no_of_frames,no_of_pages,i,faults=0;
		int pages[no_of_pages];
		int frames[no_of_frames];
		int temp[no_of_frames];
		int j,k,flag3;
		int flag1,flag2,max,pos;
	    printf("Enter number of frames: ");
	    scanf("%d", &no_of_frames);
	
	    printf("Enter number of pages: ");
	    scanf("%d", &no_of_pages);
	
	    printf("Enter page reference string: ");
	    for(i = 0; i < no_of_pages; ++i){
	        scanf("%d", &pages[i]);
	    }
	
	    for(i = 0; i < no_of_frames; ++i){
	        frames[i] = -1;
	    }
	    for(i = 0; i < no_of_pages; ++i){
	        flag1 = flag2 = 0;
	
	        for(j = 0; j < no_of_frames; ++j){
	            if(frames[j] == pages[i]){
	                   flag1 = flag2 = 1;
	                   break;
	               }
	        }
	        if(flag1 == 0){
	            for(j = 0; j < no_of_frames; ++j){
	                if(frames[j] == -1){
	                    faults++;
	                    frames[j] = pages[i];
	                    flag2 = 1;
	                    break;
	                }
	            }
	        }
	
	        if(flag2 == 0){
	                flag3 =0;
	
	            for(j = 0; j < no_of_frames; ++j){
	                temp[j] = -1;
	
	                for(k = i + 1; k < no_of_pages; ++k){
	                        if(frames[j] == pages[k]){
	                                temp[j] = k;
	                                break;
	                        }
	                }
	            }
	
	            for(j = 0; j < no_of_frames; ++j){
	                if(temp[j] == -1){
	                        pos = j;
	                        flag3 = 1;
	                        break;
	                }
	            }
	
	            if(flag3 ==0){
	                max = temp[0];
	                pos = 0;
	
	                for(j = 1; j < no_of_frames; ++j){
	                        if(temp[j] > max){
	                                max = temp[j];
	                                pos = j;
	                        }
	                }
	            }
	
	                        frames[pos] = pages[i];
	                        faults++;
	        }
	
	        printf("\n");
	
	        for(j = 0; j < no_of_frames; ++j){
	            printf("%d\t", frames[j]);
	        }
	    }
	
	    printf("\n\nTotal Page Faults = %d", faults);
	}
	
	
	void lru()
	{
	        int k=0,n,f[10],p,s,ch,temp[10],t,a[100],i,j,count=0;
	        printf("\nEnter no. of Frames :");
	        scanf("%d",&n);
	        for(i=0;i<n;i++)
	        f[i]=-1;
	        printf("\nEnter no. of Pages:");
	        scanf("%d",&p);
	        printf("\nEnter Pages :");
	        for(i=0;i<p;i++)
	        scanf("%d",&a[i]);
	        for(i=0;i<p;i++)
	        {
	        for(j=0;j<n;j++)
	        if(f[j]==a[i])
	        goto one;
	        for(j=0;j<n;j++)
	        if(f[j]==-1)
	        {
	            f[j]=a[i];
	            count++;
	            break;
	        }
	        if(j==n)
	        {
	                for(t=0;t<n;t++)
	                temp[t]=0;
	                for(k=i-1;k>0;k--)
	                {
	                        for(s=0;s<n;s++)
	                        if(f[s]==a[k]) {
	                        temp[s]=1;      break;}
	                        ch=0;
	                        for(s=0;s<n;s++)
	                        if(temp[s]==0)ch++;
	                        if(ch==1) break;
	                }
	                for(k=0;k<n;k++)
	                if(temp[k]==0)
	                f[k]=a[i];
	              count++;
	              if(k==n) k=0;
	        }
	one:
	        for(j=0;j<n;j++)
	        printf("%3d",f[j]);
	        printf("\n");
	        }
	        printf("\nNo of Page Faults :%d",count);
	
	}
	
	void fifo()
	{
	        int k=0,n,f[10],p,a[100],i,j,count=0;
	
	        printf("\nEnter no. of Frames :");
	        scanf("%d",&n);
	        for(i=0;i<n;i++)
	        f[i]=-1;
	        printf("\nEnter no. of Pages:");
	        scanf("%d",&p);
	        printf("\nEnter Pages :");
	        for(i=0;i<p;i++)
	        scanf("%d",&a[i]);
	        for(i=0;i<p;i++)
	        {
	        for(j=0;j<n;j++)
	        if(f[j]==a[i])
	        goto one;
	        for(j=0;j<n;j++)
	        if(f[j]==-1)
	        {
	            f[j]=a[i];
	            count++;
	            break;
	        }
	        if(j==n)
	        {
	              f[k++]=a[i];
	              count++;
	              if(k==n) k=0;
	        }
	one:
	        for(j=0;j<n;j++)
	        printf("%3d",f[j]);
	        printf("\n");
	        }
	        printf("\nNo of Page Faults :%d",count);
	
	}

void Page_Replacement(char *str)
{		
	if((strcmp(str,"fifo"))==0)
	{
		fifo();
	}
	
	else if((strcmp(str,"lru"))==0)
	{
		lru();
	}
	
	else if((strcmp(str,"optimal"))==0)
	{
		optimal();
	}
	
}

#include<stdio.h>


	void fcfs() 
	{
		int at[10];
		int bt[10];
		int comp[6],wt[5],tat[5];
		int i;
	
		float awt=0,att=0;
		int n;
		clrscr();
		printf("Enter no of process: ");
		scanf("%d",&n);
	
		printf("arrival time of process: ");
		for ( i=1; i<=n;i++)
		scanf("%d",&at[i]);
	
		printf("burst time of process: ");
		for ( i=1; i<=n;i++)
		scanf("%d",&bt[i]);
	
		comp[0]=0;
	
		for(i=1;i<=n;i++)
			comp[i]=comp[i-1]+bt[i];
	
	
		for(i=1;i<=n;i++) {
			wt[i]=comp[i]-at[i]-bt[i];
			tat[i]=wt[i]+bt[i];
			awt=awt+wt[i];
			att=att+tat[i];
		}
		printf("\nJob\t AT\t BT\t CT\t WT\t TAT\n");
		printf("----\t ----\t ----\t ----\t ----\t ----\n");
		for(i=0;i<n;i++) {
			printf("\nP%d\t %3d\t %3d",i+1,at[i+1],bt[i+1]);
			printf("\t %3d\t %3d\t %3d\n",comp[i+1],wt[i+1],tat[i+1]);
		}
		awt=(float)awt/n;
		att=(float)att/n;
		printf("\nThe average waiting time is: %f\n",awt);
		printf("The average turn around time is: %f\n",att);
	}
	
	void sjf()
	{
        int n,i,j,k,pno[10],awt=0,att=0,ct[10],wt[10],cp[10],b[10];

        printf("\nEnter Number of processes :");
        scanf("%d",&n);
        printf("\nEnter the Burst time of processes :");
        for(i=1;i<=n;i++)
        {
        scanf("%d",&b[i]);
        pno[i]=i;
        }
        ct[0]=0;
        b[0]=0;
        for(i=1;i<=n;i++)
        for(j=1;j<=n-1;j++)
                if(b[j]>b[j+1])
                {
                b[j+1]=(b[j]+b[j+1])-(b[j]=b[j+1]);
                pno[j+1]=(pno[j]+pno[j+1])-(pno[j]=pno[j+1]);
                }
        printf("\nProcessno\tBurst time\n");
        for(i=1;i<=n;i++)
        printf("%d\t\t%d\n",pno[i],b[i]);
        for(i=1;i<=n;i++)
        {
        ct[i]=ct[i-1]+b[i];
        wt[i]=ct[i-1];
        awt=awt+wt[i];
        att=att+ct[i];
        }
        printf("\nProcess no\twaiting time\tturnaround time\n");
        for(i=1;i<=n;i++)
        printf("\n\t%d\t\t%d\t%d",pno[i],wt[i],ct[i]);
        printf("\nAverage waiting time :%f",(float)awt/n);
        printf("\nAverage Turnaround time :%f",(float)att/n);
	}	

	void rr()
	{
		int b1[10],n,i,j=0,k,pno[10],ts,time=0,awt=0;
		int att=0,cnt,ct[10],wt[10],cp[10],b[10],p1[40],t[40];
		printf("\nEnter Number of processes :");
		scanf("%d",&n);
		printf("\nEnter the Burst time of processes :");
		for(i=1;i<=n;i++)
		{
		scanf("%d",&b[i]);
		pno[i]=i;
		b1[i]=b[i];
		}
		printf("\nEnter the time slice :");
		scanf("%d",&ts);
		ct[0]=0;
		b[0]=0;
		while(1)
		{
			for(i=1;i<=n;i++)
			{
			if(b1[i]==0) continue;
			else if(b1[i]>ts)
			{
				b1[i]=b1[i]-ts;
				p1[j]=i;
				time=time+ts;
				t[j++]=time;
			}
			else
			{
				ct[i]=time+b1[i];
				p1[j]=i;
				t[j++]=time+b1[i];
				time=time+b1[i];
				b1[i]=0;
			}
			}
			cnt=0;
			for(i=1;i<=n;i++)
			if(b1[i]==0)
			cnt++;
			if(cnt==n)
			break;
		}
		printf("\nProcessno:\t");
		for(i=0;i<j;i++)
		printf("%4d",p1[i]);
		printf("\nTime :\t\t");
		for(i=0;i<j;i++)
		printf("%4d",t[i]);
		for(i=1;i<=n;i++)
		{
		wt[i]=ct[i]-b[i];
		awt=awt+wt[i];
		att=att+ct[i];
		}
		printf("\nProcess no\twaiting time\tturnaround time\n");
		for(i=1;i<=n;i++)
		printf("\n\t%d\t\t%d\t%d",pno[i],wt[i],ct[i]);
		printf("\nAverage waiting time :%f",(float)awt/n);
		printf("\nAverage Turnaround time :%f",(float)att/n);
		
	}

	void priority()
	{
		int n,i,pos,j,temp,total=0,avg_wt,avg_tat;
		int bt[n],pr[n],p[n],wt[n],tat[n];
	    printf("Enter Total Number of Process:");
	    scanf("%d",&n);
	
	    printf("\nEnter Burst Time and Priority\n");
	    for(i=0;i<n;i++)
	    {
	        printf("\nP[%d]\n",i+1);
	        printf("Burst Time:");
	        scanf("%d",&bt[i]);
	        printf("Priority:");
	        scanf("%d",&pr[i]);
	        p[i]=i+1;
	    }
	
	    for(i=0;i<n;i++)
	    {
	        pos=i;
	        for(j=i+1;j<n;j++)
	        {
	            if(pr[j]<pr[pos])
	                pos=j;
	        }
	
	        temp=pr[i];
	        pr[i]=pr[pos];
	        pr[pos]=temp;
	
	        temp=bt[i];
	        bt[i]=bt[pos];
	        bt[pos]=temp;
	
	        temp=p[i];
	        p[i]=p[pos];
	        p[pos]=temp;
	    }
	
	    wt[0]=0;
	
	
	    for(i=1;i<n;i++)
	    {
	        wt[i]=0;
	        for(j=0;j<i;j++)
	            wt[i]+=bt[j];
	
	        total+=wt[i];
	    }
	
	    avg_wt=total/n;
	    total=0;
	
	    printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
	    for(i=0;i<n;i++)
	    {
	        tat[i]=bt[i]+wt[i];
	        total+=tat[i];
	        printf("\nP[%d]\t\t  %d\t\t    %d\t\t\t%d",p[i],bt[i],wt[i],tat[i]);
	    }
	
	    avg_tat=total/n;
	    printf("\n\nAverage Waiting Time=%d",avg_wt);
	    printf("\nAverage Turnaround Time=%d\n",avg_tat);
	}

	void multilevel()
	{
		int p[20],bt[20], su[20], wt[20],tat[20],i, k, n, temp;
		float wtavg, tatavg;
		
		printf("Enter the number of processes --- ");
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			p[i] = i;
			printf("Enter the Burst Time of Process %d --- ", i);
			scanf("%d",&bt[i]);
		}
		for(i=0;i<n;i++)
		{	
			for(k=i+1;k<n;k++)
			{		
				if(su[i] > su[k])
				{
					temp=p[i];
					p[i]=p[k];
					p[k]=temp;
					temp=bt[i];
					bt[i]=bt[k];
					bt[k]=temp;
					temp=su[i];
					su[i]=su[k];
					su[k]=temp;
				}
			}
		}
		wtavg = wt[0] = 0;
		tatavg = tat[0] = bt[0];
		for(i=1;i<n;i++)
		{
			wt[i] = wt[i-1] + bt[i-1];
			tat[i] = tat[i-1] + bt[i];
			wtavg = wtavg + wt[i];
			tatavg = tatavg + tat[i];
		}
		
		printf("\nPROCESS\t\t SYSTEM/USER PROCESS \tBURST TIME\tWAITING TIME\tTURNAROUND TIME");
		for(i=0;i<n;i++)
			printf("\n%d \t\t %d \t\t %d \t\t %d \t\t %d ",p[i],su[i],bt[i],wt[i],tat[i]);
		printf("\nAverage Waiting Time is --- %f",wtavg/n);
		printf("\nAverage Turnaround Time is --- %f",tatavg/n);
	}

void CPU_Scheduling(char *str)
{		
	if((strcmp(str,"fcfs"))==0)
	{
		fcfs();
	}
	
	else if((strcmp(str,"sjf"))==0)
	{
		sjf();
	}
	
	else if((strcmp(str,"rr"))==0)
	{
		rr();
	}
	
	else if((strcmp(str,"priority"))==0)
	{
		priority();
	}
	
	else if((strcmp(str,"multilevel"))==0)
	{
		multilevel();
	}
	
	
	
}

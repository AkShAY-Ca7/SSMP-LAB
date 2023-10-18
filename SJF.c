#include<stdio.h>

struct process{
	int p,bt,ct,tat,wt;
};

void main()
{
	int sumtat=0,sumwt=0,n,i,j;
	printf("Enter the number of process: ");
	scanf("%d",&n);
	struct process p[n];
	printf("Enter the burst time of each process :\n");
	for(i=0;i<n;i++)
	{
		p[i].p=i+1;
		printf("Enter the burst time of process P%d :",p[i].p);
		scanf("%d",&p[i].bt);
	}
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(p[j].bt>p[j+1].bt)
			{
				struct process temp=p[j];
				p[j]=p[j+1];
				p[j+1]=temp;
			}
		}
	}
	//gantt chart
	printf("\nGantt Chart");
	printf("\n--------------------------------\n");
	for(i=0;i<n;i++)
	{
		printf("|P%d\t",p[i].p);
		if(i==0)
		{
			p[i].ct=p[i].bt;
		}
		else
		{
			p[i].ct=p[i].bt+p[i-1].ct;
		}
		p[i].tat=p[i].ct;
		p[i].wt=p[i].tat-p[i].bt;
	}
	printf("|\n--------------------------------\n0");
	for(i=0;i<n;i++)
	{
		printf("\t%d",p[i].ct);
		sumtat+=p[i].tat;
		sumwt+=p[i].wt;
	}
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(p[j].p>p[j+1].p)
			{
				struct process temp=p[j];
				p[j]=p[j+1];
				p[j+1]=temp;
			}
		}
	}
	
	printf("\n\nProcess\tBT\tTAT\tWT\n");
	for(i=0;i<n;i++)
	{
		printf("P%d\t%d\t%d\t%d\n",p[i].p,p[i].bt,p[i].tat,p[i].wt);
	}
	printf("\nTotal turn around time = %d",sumtat);
	printf("\nTotal waiting time = %d",sumwt);
	printf("\nAvg TAT = %.2f",(float)sumtat/n);
	printf("\nAvg WT = %.2f\n",(float)sumwt/n);
}

#include<stdio.h>
#include<stdlib.h>

struct process
{
    int p,bt,rt,tat,wt,ct;
};

int main()
{
    int n,slice,i,j,currt=0,sumtat=0,sumwt=0,sumbt=0,k=0;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    printf("Enter the Time Slice: ");
    scanf("%d",&slice);
    struct process p[n];
    for(i=0;i<n;i++)
    {
        p[i].p=i+1;
        printf("Enter the burst time of process P%d: ",p[i].p);
        scanf("%d",&p[i].bt);
        p[i].rt=p[i].bt;
        sumbt+=p[i].bt;
    }
    int flag=0;
    int arr[sumbt];
    printf("Gantt Chart: \n");
    printf("-------------------------------------------------\n");
    while(flag!=n)
    {
        for(i=0;i<n;i++)
        {
        	if(p[i].rt>0)
        	{
                	if(p[i].rt>slice)
               		{
                    		p[i].rt-=slice;
                    		currt+=slice;
                    		arr[k++]=currt;
                    		printf("|P%d\t",p[i].p);
                	}
                	else if(p[i].rt<=slice)
                	{
                    		currt+=p[i].rt;
                    		arr[k++]=currt;
                   		printf("|P%d\t",p[i].p);
                    		p[i].rt=0;
                    		p[i].ct=currt;
                   		p[i].tat=p[i].ct;
                    		p[i].wt=p[i].tat-p[i].bt;
                    		flag+=1;
                	}
                }
        }
    }
    printf("|\n-------------------------------------------------");
    printf("\n0\t");
    for(i=0;i<k;i++)
    {
    	printf("%d\t",arr[i]);
    }
    
    printf("\n\nProcess\tBT\tTAT\tWT\n");
    for(i=0;i<n;i++)
    {
        printf("P%d\t%d\t%d\t%d\n",p[i].p,p[i].bt,p[i].tat,p[i].wt);
        sumtat+=p[i].tat;
        sumwt+=p[i].wt;
    }
    printf("Total Turn Around time : %.2f\n",(float)sumtat);
    printf("Total Waiting time : %.2f\n",(float)sumwt);
    printf("Average Turnaround Time: %.2f\n",(float)sumtat/n);
    printf("Average Waiting Time: %.2f\n",(float)sumwt/n);
    return 0;
}


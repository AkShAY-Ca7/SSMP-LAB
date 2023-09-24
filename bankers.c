#include<stdio.h>
#include<stdlib.h>
//bankers
struct process{
	int alloc[20],need[20],max[20],done;
};

void main()
{
	printf("Enter the number of processes : ");
	int num;
	scanf("%d",&num);
	printf("Enter the number of resources : ");
	int res;
	scanf("%d",&res);
	
	struct process p[num];
	int i,j;
	for(i=0;i<num;i++)
	{
		p[i].done=0;
		printf("Enter the max resources needed for process %d : ",i+1);
		for(j=0;j<res;j++)
		{
			scanf("%d",&p[i].max[j]);
		}
		printf("Enter the alloc resources needed for process %d : ",i+1);
		for(j=0;j<res;j++)
		{
			scanf("%d",&p[i].alloc[j]);
		}
		for(j=0;j<res;j++)
		{
			p[i].need[j]=p[i].max[j]-p[i].alloc[j];
		}
	}
	printf("Enter the available resources : ");
	int avail[res];
	for(j=0;j<res;j++)
	{
		scanf("%d",&avail[j]);
	}
	
	printf("\n\tAllocation\tMax\tNeed\n"); 
	for(i=0;i<num;i++)
	{
		printf("P%d\t",i);
		for(j=0;j<res;j++)
		{
			printf("%d ",p[i].alloc[j]);
		}
		printf("\t\t");
		for(j=0;j<res;j++)
		{
			printf("%d ",p[i].max[j]);
		}
		printf("\t");
		for(j=0;j<res;j++)
		{
			printf("%d ",p[i].need[j]);
		}
		printf("\n");
	}
	printf("\n");
	
	int arr[20];
	int k=0;
	int count=0;
	while(count<num)
	{
		for(i=0;i<num;i++)
		{
			int less=0;
			for(j=0;j<res;j++)
			{
				if(p[i].need[j]<=avail[j])
				{
					less++;				
				}
			}
			if(p[i].done==0 && less==res)
			{
				for(j=0;j<res;j++)
				{
					avail[j]+=p[i].alloc[j];
				}
				p[i].done=1;
				arr[k++]=i+1;
				count++;
			}
		}
	}
	for(i=0;i<num;i++)
	{
		if(p[i].done!=1)
		{
			printf("safe sequence does not exist !\n ");
			exit(0);
		}
	}
	printf("Safe sequence exist :\n< ");
	for(k=0;k<num;k++)
	{
		printf("P%d ",arr[k]);
	}
	printf(">\n");
	
}

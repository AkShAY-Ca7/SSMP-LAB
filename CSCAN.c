#include<stdio.h>
#include<stdlib.h>

void main()
{
	int head,n,sum=0,dist,i,j,position,max;
	printf("Enter the max number of cylinders : ");
	scanf("%d",&max);
	printf("Enter the position of the head : ");
	scanf("%d",&head);
	printf("Enter the number of requests : ");
	scanf("%d",&n);
	int req[n];
	printf("Enter the request string :\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&req[i]);
	}
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(req[j]>req[j+1])
			{
				int temp=req[j];
				req[j]=req[j+1];
				req[j+1]=temp;
			}
		}
	}
	
	
	for(i=0;i<n;i++)
	{
		if(head<req[i])
		{
			position=i;
			break;
		}
	}
	
	for(i=position;i<n;i++)
	{
		dist=req[i]-head;
		sum+=dist;
		printf("head movement from cylinder %d to %d is %d\n",head,req[i],dist);
		head=req[i];
	}
	
	dist=max-1-head;
	sum+=dist;
	printf("head movement from cylinder %d to %d is %d\n",head,max-1,dist);
	dist=max-1;
	sum+=dist;
	printf("head movement from cylinder %d to %d is %d\n",max-1,0,dist);
	head=0;
	
	for(i=0;i<position;i++)
	{
		dist=req[i]-head;
		sum+=dist;
		printf("head movement from cylinder %d to %d is %d\n",head,req[i],dist);
		head=req[i];
	}
	printf("Total head movement :  %d\n",sum);
}

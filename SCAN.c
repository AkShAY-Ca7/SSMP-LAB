#include<stdio.h>
#include<stdlib.h>

void main()
{
	int head,n,sum=0,dist,i,j,position;
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
	
	for(i=position-1;i>=0;i--)
	{
		dist=head-req[i];
		sum+=dist;
		printf("head movement from cylinder %d to %d is %d\n",head,req[i],dist);
		head=req[i];
	}
	
	dist=head;
	sum+=dist;
	printf("head movement from cylinder %d to %d is %d\n",head,0,dist);
	head=0;
	
	for(i=position;i<n;i++)
	{
		dist=req[i]-head;
		sum+=dist;
		printf("head movement from cylinder %d to %d is %d\n",head,req[i],dist);
		head=req[i];
	}
	printf("Total head movement :  %d\n",sum);
}

#include<stdio.h>
#include<stdlib.h>

void main()
{
	int head,n,sum=0,dist,i;
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
		dist=abs(head-req[i]);
		sum+=dist;
		printf("Head movement from cylinder %d to %d is %d\n",head,req[i],dist);
		head=req[i];
	}
	printf("Total head movement :  %d\n",sum);
}

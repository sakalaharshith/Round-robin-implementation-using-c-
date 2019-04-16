#include<stdio.h>
main()
{
	int a[100]={1,3,5,2,4},arr[100],burst[100],i,j,min,a1,quantum,time,tat=0,wt=0,temp[10],x,counter=0;
	int endt=2,starts=3,ends=4,t,e,g,k;
	char c[5];
	arr[0]=1;
	burst[0]=6;
	arr[1]=2;
	burst[1]=5;
	arr[2]=6;
	burst[2]=3;
	arr[3]=3;
	burst[3]=2;
	arr[4]=5;
	burst[4]=5;
	printf("do you want to add process");
	scanf("%s",&c);
	t=strcmp("yes",c);
	if(t==0)
	{
		printf("do you want to add teacher process\n");
		scanf("%s",&c);
		int d=strcmp("yes",c);
		if(d==0)
		{
			e=ends;
			ends=ends+1;
			while(e>=starts)
			{
				g=e+1;
				a[g]=a[e];
				arr[g]=arr[e];
				burst[g]=burst[e];
				e=e-1;
			}
		  k=a[endt]+2;
		  a[starts]=k;
		  burst[starts]=6;
		  arr[starts]=8;
		  starts=starts+1;	
		}
		printf("do you want to add student process\n");
		scanf("%s",&c);
		int f=strcmp("yes",c);
		if(f==0)
		{
			int n;
			n=a[ends]+2;
			ends=ends+1;
			a[ends]=n;
			burst[ends]=5;
			arr[ends]=9;
		
		}
		
	}

	for(i=0;i<=ends;i++)
	{
	printf("id is %d  and burst time %d and arrival time %d\n",a[i],burst[i],arr[i]);
		
	}
	
	printf("  \n   ");
	for(i=0;i<ends;i++)
	{
		min=i;
		for(j=i+1;j<=ends;j++)
		{
			if(arr[min]>arr[j])
			{
				min=j;
			}
		}
		a1=arr[i];
		arr[i]=arr[min];
		arr[min]=a1;
		a1=burst[i];
		burst[i]=burst[min];
		burst[min]=a1;
		a1=a[i];
		a[i]=a[min];
		a[min]=a1;
		
	}
	for(i=0;i<=ends;i++)
	{
	printf("id is %d  and burst time %d and arrival time %d\n",a[i],burst[i],arr[i]);
	temp[i]=burst[i];	
	}
	x=ends+1;
	
	printf("enter time quantum");
	scanf("%d",&quantum);
	printf("\n process id\t\tbursttime\tturnaroundtime\twaitingtime\n");
	for(time=0,i=0;x!=0;)
	{
		if((temp[i]<=quantum) && temp[i]>0)
		{
		time=time+temp[i];
		temp[i]=0;
		counter=1;	
		}
		else if(temp[i]>0)
		{
			temp[i]=temp[i]-quantum;
			time=time+quantum;
		}
		if((temp[i]==0) && (counter==1))
		{
		x--;
		printf("\n %d \t\t\t %d \t\t\t %d \t\t %d\n",a[i],burst[i],time-arr[i],time-arr[i]-burst[i]);
		wt=wt+time-arr[i]-burst[i];
		tat=tat+time-arr[i];
		counter=0;	
		}
		if(i==ends)
		{
			i=0;
		}
		else if(arr[i+1]<=time)
		{
			i++;
		}
		else
		{
			i=0;
		}
		}	
		


	
	
}

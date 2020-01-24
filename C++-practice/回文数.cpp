#include <stdio.h>
#include <math.h>
int value(int x)
{
	int wei=log10(x);
	int low=0;
	int a[20];
	
	int high=wei-1;
	while(low<high)
	{
		if(a[low]==a[high])
		{
			low++;
			high--;
		}
		else
		return 0;
	
		}
	return 1;
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int i;
	int s=0;
	int isprime=value(i);
	for(i=n;i<=m;i++)
	{
		if(isprime==1)
		{
			s+=i;
			
		}
	}
	printf("%d",s);
	return 0; 
}

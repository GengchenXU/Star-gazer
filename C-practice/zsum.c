#include<stdio.h>
int main()
{
	int a,n[5],i;
	scanf("%d",&a);
	int sum=0;
	for(int i=0;i<5;i++)
	{
		scanf("%d",&n[i]);
	}
	for(int i=0;i<5;i++){
		if(n[i]<a)
			sum=sum+n[i];
		
		
	}
	printf("%d\n",sum);
	return 0;

}

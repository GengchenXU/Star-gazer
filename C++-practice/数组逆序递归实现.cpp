#include <stdio.h>
void fun(int a[],int i)
{
	if(i>0)
	{
		printf("%d ",a[i-1]);
		fun(a,--i);
	}
}
int main()
{
	
	int i,a[10],N;
	scanf("%d",&N);
	for(i=0;i<N;i++)
		scanf("%d",&a[i]);
	fun(a,N);
	printf("\n");
}



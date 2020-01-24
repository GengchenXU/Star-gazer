#include<Stdio.h>
#define N 10 
int main(void)
{
	int i,pool,M,a[N];
	scanf("%d%d",&pool,&M);
	for(i=0;i<M;i++)
	{
		scanf("%d",&a[i]);
	}
	int j;
	for(i=0;i<M-1;i++)
	for(j=0;j<M-1-i;j++)
	{
		if(a[j]<a[j+1])
		{
			a[j]=a[j]^a[j+1];
			a[j+1]=a[j]^a[j+1];
			a[j]=a[j]^a[j+1];
		}
	}
	int b[10]={0};
	for(i=0;i<M;++i)
	{
		b[i]=pool/a[i];
		pool=pool%a[i];
	}
	for(i=0;i<M;i++)
	printf("%d  ",b[i]);
	return 0;
}

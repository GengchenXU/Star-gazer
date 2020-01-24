#include<Stdio.h>
#define N 4
int main(void)
{
	int i,pool,M,a[N];
	scanf("%d%d",&pool,&M);
	for(i=0;i<M;i++)
	{
		scanf("%d",&a[i]);
	}
	int j;
	//for(i=0;i<M-1;i++)
	for(j=0;j<M-1-i;j++)
	{
		if(a[j]<a[j+1])
		{
			a[j]=a[j]^a[j+1];
			a[j+1]=a[j]^a[j+1];
			a[j]=a[j]^a[j+1];
		}
	}
	int b[N]={0};
	for(i=0;i<M;++i)
	{
		b[i]=pool/a[i];
		pool=pool%a[i];
	}
	for(i=M-1;i>=0;i--)
	printf("%d ",b[i]);
	return 0;
}



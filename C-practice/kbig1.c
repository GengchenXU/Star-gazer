#include<stdio.h>
int maxk(int N,int K)
{
	int a[1000],i,j;
        for(i=0;i<N;i++)
	scanf("%d",&a[i]);
	for(i=0;i<N-1;i++)
		for(int j=0;j<N-1-i;j++)
			if(a[j]<a[j+1]){
			int temp=a[j];	
			a[j]=a[j+1];
			a[j+1]=temp;
		}
	          printf("%d\n",a[K-1]);
		  return 0;
       		
		}
		int main(void)
		{
			int N;
			int K;
			scanf("%d\n%d\n",&N,&K);
			maxk(N,K);
			return 0;
		}


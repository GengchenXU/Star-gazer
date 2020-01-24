#include <stdio.h>
int main() {
	int V,n,i,j,p;
	scanf("%d %d",&V,&n);
	int v[n],num[V+1][n],sum[V];
	for(i=0;i<=V;i++){
		sum[i]=10000;
	    for(j=0;j<n;j++)
		    num[i][j]=0;
	}
	for(i=0;i<n;i++)
	    scanf("%d",&v[i]);
		for(i=0;i<=V;i++)
		{
			if(i==0) 
				sum[i]=0;
			else
			{
				for(j=0;j<n;j++)
				{
					if(i-v[j]>=0&&sum[i]>sum[i-v[j]])
					{
					
						sum[i]=sum[i-v[j]];
						for(p=0;p<n;p++)
							num[i][p]=num[i-v[j]][p];
						num[i][j]++;
						sum[i]=sum[i-v[j]]+1;
					}
				}
			}
		} 
	
	for(i=0;i<n;i++){
		printf("%d",num[V][i]);
			if(i!=n-1)
		    printf(" ");
	}
	return 0;
}
//一.代码中数组表示的东西
//以下i,j为常数，不是变量。
//1.数组v[i]表示桶的体积
//如：v[0]为第一个桶的体积
//2.num[i][j]是表示不同需要灌的水量时，不同的桶的数量，
//如：num[5][1]为，5L水时，第二个桶的数量(值得注意的是，保存的是最优时的数量)
//3.sum[j]表示某一(需罐)水量时，所需全部桶数的最少量(一开始，像学长讲的那样，赋一个很大的值) /// 

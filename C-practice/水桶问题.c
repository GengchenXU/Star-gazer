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
	for(i=0;i<=V;i++){
		if(i==0) sum[i]=0;
		else{
			for(j=0;j<n;j++){
				if(i-v[j]>=0&&sum[i]>sum[i-v[j]]){
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



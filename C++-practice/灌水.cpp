/*
 * @Description: 
 * @Sample Intput: 
 * @Output: 
 * @Author: GengchenXu
 * @CreateDate: 2020-03-10 22:22:46
 * @LastEditTime: 2020-08-31 23:58:07
 */
#include <stdio.h>
int main() {
	int V,n,i,j,p;
	scanf("%d %d",&V,&n);
	int v[n];
	int num[V+1][n];	//num[i][j]是表示不同需要灌的水量时
	int sum[V];		//sum[j]表示某一(需罐)水量时，所需全部桶数的最少量
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
				int last = i-v[j];
				if(last>=0&&sum[i]>sum[last]){
					//sum[i]=sum[i-v[j]];
					for(p=0;p<n;p++)
						num[i][p]=num[last][p];
					num[i][j]++;//当剩余水大于0，这个桶数可以增加
					sum[i]=sum[last]+1;
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
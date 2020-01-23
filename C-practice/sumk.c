#include<stdio.h>
int main(){
	int n,k,a[1000],i;
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++){
	scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(k==a[i]+a[j]){        				                     printf("yes");
				return 0;}
		}
	}
printf("no");
return 0;
}

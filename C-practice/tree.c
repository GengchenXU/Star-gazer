#include<stdio.h>
int main(){
	int l,m,a[1000],i,j,b[1000],n,c,d;
	n=m*2;
	scanf("%d%d",&l,&m);
	for(int i=0;i<l;i++){
		a[i]=i;
	}
	for (i=0;i<n;i+=2){
		scanf("%d%d",&b[i],&b[i+1]);
	}
	for(int i=0;i<n;i+=2){
		c=b[i];
		d=b[i+1];
		for (j=c;j<=d;j++){
			a[j]=-1;
		}
	}
	int z=0;
	for(i=0;i<=l;i++){
		if(a[i]!=-1){
			z++;
		}
	}
	printf("%d",z);
	return 0;


}


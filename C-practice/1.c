#include<stdio.h>
int main(){
	int a[1000],N;
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d",&a[i]);
	}
	for(int i=0;i<N-1;i++)
		for(int j=0;j<N-1-i;j++)
			if(a[j]<a[j+1]){
				int temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
			for(int i=0;i<N;i++){
				printf("%d\n",a[i]);}
				return 0;
}


#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main(){
	int a[100],minl=100,temp,N;
	scanf("%d",&N);
	for(int i=0;i<N;i++)
		scanf("%d",&a[i]);
	for(int i=0;i<N;i++){
		for (int j=i+1;j<N;j++){
			temp=abs(a[i]-a[j]);
			if (temp<minl)
				minl=temp;
				}
				}
				printf("%d",minl);
				return 0;

}

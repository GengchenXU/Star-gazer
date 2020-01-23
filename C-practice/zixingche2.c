#include<stdio.h>
int main(){
	int a[1000],n;
	float tw,tb;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=0;i<n;i++){
		tb=a[i]/3+50;
                tw=a[i]/1.2;
		if(tb>tw){
			printf("Walk\n");
		}
		else if(tb<tw){
			printf("Bike\n");
		}
		else if(tb=tw){
			printf("All\n");
		}
		}
		return 0;
}

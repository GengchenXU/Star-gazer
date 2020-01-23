#include<stdio.h>
int main(){
	int i=5;
	int a[10]={0};
	for(i=0;i<5;i++)
		scanf("%d",&a[i]);
		for(i=0;i<5;i++){
			if(a[i]%3==0)
				printf("3 ");
			if(a[i]%5==0)
				printf("5 ");
			if(a[i]%7==0)
				printf("7");
			if(a[i]%3!=0&&a[i]%5!=0&&a[i]%7!=0)
				printf("n");
			printf("\n");			
		}
return 0;
}

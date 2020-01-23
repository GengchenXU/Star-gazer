#include<stdio.h>
int main(){
	int i=0,n;
	int flag = 0;
	scanf("%d",&n);
	int a[100];
	for (i = 0; i<n; i ++){
		scanf("%d", &a[i]);
		if (i == a[i]){
			printf("%d\n", i);
			flag = 1;
			break;
		}
	}
	if (flag == 0){
		printf("N\n");
	}
	return 0;
}


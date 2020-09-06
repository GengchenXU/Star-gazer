#include<stdio.h>
int main()
{
	float n,tw,tb,l;
	scanf("%f",&n);
	for (int i=0;i<n;i++){
		
	scanf("%f",&l);
	tb=50+(l/3.0);
	tw=l/1.2;
		if(tb>tw){
		printf("Walk");
	}
	else if(tw>tb){
		printf("Bike");
	}
	else if(tw=tb){
		printf("All");
	}
	}
	return 0;
}

#include<stdio.h>
int main()
{
	int n,a[1000];
	int e=0,b=0,c=0,d=0;
	float f,g,h,j; 
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for (int i=0;i<n;i++){
		if(a[i]<18){
		e++;
	}
	if(a[i]<=35&&a[i]>=19){
		b++;
	}
	if(a[i]<=60&&a[i]>=36){
		c++;
	}
	if(a[i]>=61){
		d++;
	}
	}
	f=100.0*e/n;
	g=100.0*b/n;
	h=100.0*c/n;
	j=100.0*d/n;
printf("1-18:%.2f%%\n",f);
printf("19-35:%.2f%%\n",g);
printf("36-60:%.2f%%\n",h);
printf("61-:%.2f%%\n",j);
return 0;
}

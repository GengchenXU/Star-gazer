#include<stdio.h>
int main()
{
	int z,a,b,c,d,e,f,g,h,i,j;
		scanf("%d",&z);
	a=z%100;
	b=z/100;
	c=a%50;
	d=a/50;
	e=c%20;
	f=c/20;
	g=e%10;
	h=e/10;
	i=g%5;
	j=g/5;
	

	printf("%d\n%d\n%d\n%d\n%d\n%d\n",b,d,f,h,j,i);
	return 0;
}


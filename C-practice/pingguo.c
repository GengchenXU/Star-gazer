#include<stdio.h>
#include<math.h>
int main()
{
	int n,x,y,z,a;
	scanf("%d%f%f",&n,&x,&y);
	a=ceil(y/x);
	z=n-a;
	printf("%d",z);
	return 0;
}

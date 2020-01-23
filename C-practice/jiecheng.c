#include<stdio.h>
int main()
{
	int i,t;
	t=1;
	i=2;
	while(i<=29)
	{
		t=t*i;
		i=i+1;
	}
	printf("%d\n",t);
	return 0;
}

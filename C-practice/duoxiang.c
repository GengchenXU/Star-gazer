#include <stdio.h>
int main()
{
	int sign=1;
	double deno=3,sum=1,term;
	while(deno<=3000000000)
	{
		sign=-sign;
		term=sign/deno;
		sum=sum+term;
		deno=deno+2;
	}
	printf("%15.20f\n",sum*4);
	return 0;
}
	

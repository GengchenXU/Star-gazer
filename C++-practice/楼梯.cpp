#include <stdio.h>
#include <stdlib.h>
int fun(int n){
    if(n <= 0)
        return 0;
    if(n == 1)
        return 1;
    if(n == 2)
        return 2;
    else return fun(n-1)+fun(n-2);
}
int main()
{
	int N;
while(scanf("%d",&N)!=EOF)
	{
    
		printf("%d\n",fun(N));
	}
    return 0;
}

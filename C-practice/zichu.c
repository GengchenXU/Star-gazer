#include<stdio.h>
int main(){
    int n,i,a,b;
    scanf("%d",&n);
    for(i=10;i<=n;i++)
    {
        a=i/10;
        b=i%10;
    if(i%(a+b)==0) 
	  {
		printf("%d\n",i);
	  }
    }
    return 0;
    }

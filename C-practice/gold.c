#include <iostream>
#include <cstdio>
using namespace std;

int main()	{
	int i,j,sum=0,sumd=0,n,ans;
	scanf("%d",&n);
	for (i=1;;i++)	{
		sum+=i;
		if (sum>=n)	break;
	}
	//i--;	
	for (j=1;j<i;j++)
		sumd+=j*j;
//	ans=(1+i)*(n-(sum-i-1))+sumd;
	ans=j*(n-(sum-i))+sumd;
	printf("%d\n",ans);
	return 0;
}


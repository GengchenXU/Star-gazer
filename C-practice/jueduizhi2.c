#include<stdio.h>

int main()
{
int a[6],result,maxj,mino=a[0];
for(int i=0;i<6;i++)
scanf("%d",&a[i]);
for (int i=0;i<6;i++)
	for(int j=0;j<6-i;j++)
	
	if (a[j-1]%2==0&&a[j]%2!=0)
	{int temp=a[j];
		a[j]=a[j-1];
	}

mino=a[j-1];

printf("%d",mino);
return 0;}

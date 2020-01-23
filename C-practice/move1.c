#include<stdio.h>
void main()
{
int a[100],n,m,i,j,temp;
scanf("%d%d",&n,&m);
for(i=0;i<n;i++)
scanf("%d",&a[i]);
for(i=0;i<11-m;i++)//一个一个移动直到移动4个
{
temp=a[0];
for(j=0;j<n-1;j++)//
a[j]=a[j+1];
a[j]=temp;
}
for(i=0;i<n;i++)
printf("%d ",a[i]);
printf("\n");
} 

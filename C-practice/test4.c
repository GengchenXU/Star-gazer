#include <stdio.h>
void main()
{
int i,j,max,temp,a[10];
for(i=0;i<10;i++)
scanf("%d",&a[i]);
for(i=0;i<10;i++)
{
max=i;
for(j=i+1;j<10;j++)
if(a[max]<a[j])
max=j;
temp=a[i];
a[i]=a[max];
a[max]=temp;
}
for(i=0;i<10;i++)
printf("%d ",a[i]);
} 

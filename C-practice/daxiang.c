#include<stdio.h>
#define pi 3.1415926
int main()
{
int h,r,y;
scanf("%d%d",&h,&r);
y=(20000+h*r*r*pi-1)/(h*r*r*pi);
printf("%d",y);
return 0;
}

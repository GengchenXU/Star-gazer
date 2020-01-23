#include<stdio.h>
#include<math.h>
#define pi 3.1415926
int main()
{
int h,r,y,x;
scanf("%d%d",&h,&r);
y=ceil(20000/(h*r*r*pi));
printf("%d",y);
return 0;
}


#include<stdio.h>
#include<math.h>
double f(double x) //定义我们的函数
{
 double a,b,c,d; 
 return a*x*x*x+b*x*x+c*x+d;
}
int main()
{
  float a,b,c,d; 
  printf("请输入方程一般式的系数a,b,c,d\n");
  scanf("%f,%f,%f,%f",&a,&b,&c,&d);
  float m,n,eq;
  printf("请输入需求根的所在的区间[m,n],及要求精度eq\n");
  scanf("%f,%f,%f",&m,&n,&eq);
  float x1,x2,y1,y2;
  x1=m;
  x2=n;
  y1=f(x1); 
  y2=f(x2);
  if(y1*y2>0)
	  printf("此区间无零点\n");
  else if(y1*y2<0)
  { 
	  float x,y;
	  x=(x1+x2)/2;
      
	  y=f(x);
	  do
	  {
	     if(y1*y<0)
		 {
			 x2=x;y2=y;
		 }
		 if(y2*y<0)
		 {
			 x1=x;y1=y;
		 }
	  }
	  while(fabs(x1-x2)>eq);
	  printf("不足近似值x1=%f\n过剩近似值x2=%f\n",x1,x2);
  }
	  else if(y1=0)
		  printf("x1=%f\n",x1);
	  else if(y2=0)
          printf("x2=%f\n",x2);
          return 0;

}

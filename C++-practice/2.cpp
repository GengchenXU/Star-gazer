#include<stdio.h>
 int f(int x,int y)
   {return x*y;}
   int main( )
   {  int i,j,(*fun)(int,int);
	  fun=f;
	  for(i=1;i<4;i++)
	  {  switch(i)
		{case 1:
		 case 2: j=(*fun)(i,i+1);break;
 		 case 3: j=(*fun)(i-1,i+2);break;
		}
		printf("j=%d",j);
	   }
}


#include<stdio.h>
  #include<iostream>
  
  int main()
  {
      int a, b, c;
     scanf("%d,%d,%d",&a,&b,&c);
      if (a+b==c)
    {
         printf("+");
     } else if (a-b==c)
     {
         printf("-");
     } else if (a*b==c) {
         printf("*");
     } else if (b!=0 &&a/b==c)
     {
         printf("/");
     } else if (b!=0 && a%b==c)
     {
         printf("%c",'%');
    } else {
         printf("error");
     }
     return 0; 
 }

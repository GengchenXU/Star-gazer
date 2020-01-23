#include <stdio.h>
int main()
{
 int c;
 int a[4];
 int i;
 for(c=1;c<5;c++)
 {
  a[0]=(c==2);
  a[1]=(c==4);
  a[2]=(c!=3);
  a[3]=(c!=4);
  if((a[0]+a[1]+a[2]+a[3])==1)
  {
   printf("%d\n",c);
   for(i=0;i<4;i++)
   {
    if(a[i]) printf("%c\n",'A'+i);
   }
  }
 }
 return 0;
}

#include<stdio.h>
void fun(char *a,char *p)
{char *q=a;
 int j=0;
 while(*q++=='*');
 for(q--;q<p;q++)
   if(*q!='*')a[j++]=*q;
 //a[j++]=*p++;
 for(;a[j++]=*p++;);
}
int main()
{char s[100],*p=s;
gets(s);
 for(;*p;p++);
 for(p--;*p=='*';p--);
 fun(s,p);
 printf("%s\n",s);
 return 0;
}

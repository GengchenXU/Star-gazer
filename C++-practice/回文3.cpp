#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int fun(char *s) //ÅÐ¶ÏÊÇ·ñ»ØÎÄ
{
int i=0,n;
n=strlen(s);
n--;
while(n>i)
{
if(s[n]!=s[i])
return 0;
i++;
n--;
}
return 1;
}

int main()
{
int i,m,n,sum=0;
char a[10];
scanf("%d%d",&n,&m);
for(i=n;i<=m;i++)
{
itoa(i,a,10);
if(fun(a))
sum+=i;
}
if(sum!=0)
printf("%d\n",sum);
return 0;
} 

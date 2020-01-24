#include<stdio.h>
void del(char *s,char c)
{
int i = 0,j = 0;
for(i=0;s[i]!='\0';)
{
if(s[i]==c)
{
for(j=i;s[j]!='\0';j++)
{
s[j]=s[j+1];
}
}
else
{
i++;
}
}
}
int main()
{
char s[80],c;
gets (s);
c=getchar(); 
del(s,c);
puts(s);
return 0;
}


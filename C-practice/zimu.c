#include<stdio.h>
#include<string.h>
int main()
{
char s[80];
int a,e,f,o,u;
a=e=f=o=u=0;
fgets(s,80,stdin); 
for(int i = 0; s[i] != '\0'; i++)
                                if(s[i] >= 'A' && s[i] <= 'Z')
                                                s[i] += 'a'-'A';

for(int i=0;i<strlen(s);i++){
switch(s[i]){
case'\0':break;
case'a':++a;break;
case'e':++e;break;
case'i':++f;break;
case'o':++o;break;
case'u':++u;break;
}
}
printf("%d,%d,%d,%d,%d",a,e,f,o,u);
return 0;
} 

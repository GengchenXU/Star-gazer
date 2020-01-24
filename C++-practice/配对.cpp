#include<iostream>
#include<cstring>
using namespace std;
int main()
{ 
string string1;
char b[100];
int i,j,k,t,p;
while(cin>>string1)
{

k=strlen(string1);
for(i=0;i<k;i++)
{

if(string1[i]!='('&&string1[i]!=')')
b[i]=' ';
else if(string1[i]==')') b[i]='?';
else 
{
j=1;p=0;
for(j=1;j<k-i;j++)
if(string1[i+j]==')'&&b[i+j]!=' ') 
{
p=1;
for(t=i+j-1;t>=i;t--)
if(string1[t]=='(')
{
b[i]=' ';b[i+j]=' ';
}
}if(p==0) b[i]='$';
}

}
for(i=0;i<k;i++)
cout<<b[i];
cout<<endl;
}
return 0;
} 

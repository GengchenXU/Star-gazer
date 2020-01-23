#include<stdio.h>
#include<string.h>
void Match(char s[],int n)
{
	int j;
	for(int i=0;i<n;i++)
	{
		if(s[i]==')')
			for( j=i-1;j>=0;j--)
				if(s[j]=='('){
					s[i]=' ';
					s[j]=' ';
					break;}
		if(s[i]=='}')
			for(j=i-1;j>=0;j--)
				if(s[j]=='{'){
					s[i]=' ';
					s[j]=' ';
					break;}
		if(s[i]==']')
			for(j=i-1;j>=0;j--)
				if(s[j]=='['){
					s[i]=' ';
					s[j]=' ';
					break;}
				
	}
}
int Judge(char *s,int n)
{
	int m;
	for(int i=0;i<n;i++)
	{
		if((s[i]=='[')||(s[i]==']')||(s[i]=='(')||(s[i]==')')||(s[i]=='{')||(s[i]=='}'))
		{
			m=0;
			break;
		}
		else m=1;
	}
	return m;
}
int main()
{
	int n,m;
	char a[100];
	gets(a);
	n=strlen(a);
	Match(a,n);
	printf("%d",Judge(a,n));
	return 0;

}

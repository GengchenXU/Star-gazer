#include<stdio.h>
int main(){
	int a,b;
	char ch;
	scanf("%d %d %c",&a,&b,&ch);
	if(ch!='+'&&ch!='-'&&ch!='*'&&ch!='/')
	printf("Invalid operator!");
	else{
		if(ch=='+') printf("%d",a+b);
		if(ch=='-') printf("%d",a-b);
		if(ch=='*') printf("%d",a*b);
		if(ch=='/') {if(b==0){
			printf("Divided by zero!");
		}
		else{
			printf("%d",a/b);
		}
		}
		}
	
	return 0;
}

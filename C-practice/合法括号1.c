
#include<stdio.h>
#include<string.h>
#include<stdbool.h>
int main(){
	int lens,i,j,t;
	char a[100];
	scanf("%s",a);
	lens=strlen(a);
	for(i=0;i<lens;i++){
		bool pi=true;
		//for(j=i+1;j<lens;j++)
			if(a[i]==')'){
				for( j=i;j>0;j--){
					if (a[j]=='(')
						pi=true;
				}
			}
			else if(a[i]==']'){
				for (j=i;j>0;i--){
					if(a[j]=='[')
						pi=true;
				}
			}
			else if(a[i]=='}'){
				for(j=i;j>0;j--){
					if(a[j]=='{'){
						pi=true;
					}
				}
			}
		if(pi){
			printf("1");
		}
		else printf("0");
	}
	return 0;
}


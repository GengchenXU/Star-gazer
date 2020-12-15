/*
 * @Description: 
 * @Sample Intput: 
 * @Output: 
 * @Author: GengchenXu
 * @CreateDate: 2020-03-10 22:22:46
 * @LastEditTime: 2020-12-15 22:35:14
 */
#include<stdio.h>
#include<string.h>
int main(){
	int lens,i,j,t;
	char s[100];
	scanf("%s",s);
	lens=strlen(s);
	for(i=0;i<lens;i++){
		for(j=i+1;j<lens;j++)
			if(s[i]!=s[j]&&s[i]!=' '&&s[j]!=' '){
				for(t=j-1;t>=0;){
					if(s[t]==' ')
						t=t-1;
					else{
						s[t]=' ';
						printf("%d ",t);
						break;
					}
				}
				printf("%d\n",j);
				s[j]=' ';
			}
	}
	return 0;
}

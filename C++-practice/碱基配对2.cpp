#include<stdio.h>
#include<string.h>
int main()
{
	int n;
	scanf("%d",&n);
	char a[100][100];
	for(int i=0;i<n;i++)
	{
		scanf("%s",a[i]);
	}
		for(int j=0;j<n;j++){
			for(int k=0;a[j][k]!='\0';k++)  //for(int k=0;k<strlen(a[j]);k++)  a[j]!='\0'wrong	//		
			{  
			switch(a[j][k]){
				case 'A': printf("T");break;
            	case 'T': printf("A"); break;
            	case 'G': printf("C"); break;
            	default: printf("G");
				}
				}
            	printf("\n");
			}
			return 0;
}

#include<stdio.h>
int main()
{
	int a[100],n,m,i,j,tmp,*p=a;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++){
		scanf("%d",p++);
	}
	p=a;
	for(i=0;i<11-m;i++){
		tmp=*p;
		for(j=0;j<n-1;j++,p++){
			*p=*(p+1);
		}
		*p=tmp;
		p=a;
	}
	for(i=0;i<n;i++)
	//	printf("%d ",a[i]);
		printf("%d ",*p++);
		printf("\n");
		return 0;
}

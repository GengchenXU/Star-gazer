#include<stdio.h>
int main()
{
int a[6],i,result,maxj,mino;
for(int i=0;i<=6;i++)
scanf("%d",&a[i]);

	if (a[i]%2==0&&mino<a[i])
{
mino=a[i];
}
			
			else if
				(a[i]%2==1&&maxj>a[i]){
maxj=a[i];
				}
							
		result==maxj-mino;
		printf("%d",result);
												return 0 ;
	
}

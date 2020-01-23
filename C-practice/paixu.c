#include<stdio.h>
int main ()
{int a[10];
	for (int i=0;i<10;i++)
		scanf("%d",&a[i]);
		for(int i=0;i<10;i++)
			for (int j=0;j<10-i;j++)
			if (a[j-1]>a[j])
			{	int temp=a[j];
				a[j]=a[j-1];
				a[j-1]=temp;}
for(int i=0;i<10;i++)
	for(int j=0;j<10-i;j++)
		if (a[j-1]%2==0 && a[j]%2!=0)
		{int temp =a[j];
			a[j]=a[j-1];
			a[j-1]=temp;}
			for (int i=0;i<10;i++)
				printf("%d ",a[i]);
				return 0;
printf("\n");
return 0;
}

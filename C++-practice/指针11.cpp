#include<iostream>;
using namespace std;
int main()
	/*{
		int i,a[10],*p=a;
		for(int i=0;i<10;i++)
		{
			scanf("%d",p++);//p++��ַ�ѱ�			
		}
		p=a;//����ʹpָ��a[0] 
		for(i=0;i<10;i++)
		printf("%d ",*p++);
		return 0;
		}	*/ 
	/*{
		int i,a[10],*p=a;
		for(int i=0;i<10;i++)
		{
			scanf("%d",p++);			
		}
		p=a;//����ʹpָ��a[0] 
		for(i=0;i<10;i++,p++)
		printf("%d ",*p);
		return 0;	
	}*/ 
	/*{
		int i,a[10],*p=a;
		for(int i=0;i<10;i++)
		{
			scanf("%d",p++);			
		}
		for(i=0;i<10;i++,p++)
		printf("%d ",*p);
		return 0;	
	}*/
	{
		int i,a[10],*p=a;
		for(int i=0;i<10;i++)
		{
			scanf("%d",&a[i]);
			
		}
		for(i=0;i<10;i++,p++)
		printf("%d ",*p);
		return 0;
	}

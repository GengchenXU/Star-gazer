#include <stdio.h>

int main()
{
	int pool = 0,m = 0,temp;
	//printf("请输入水池容积和桶的数量（空格分开）：");
	scanf("%d %d",&pool,&m);//读入水桶个数和水池容积 
	
	int ton[m],cnt = 0,result[m];
	//printf("输入每桶水的容积（空格分开）：");
	for(cnt = 0; cnt<m; cnt++)//读入每桶水的容积 
		scanf("%d",&ton[cnt]);
		
	
	int dnt = 0;
	for(cnt = 0; cnt<m; cnt++)//排序,从大到小 
	{
		for(dnt = cnt; dnt<m; dnt++)
		{
			/*if(ton[cnt] < ton[dnt])
			{
				ton[cnt] = ton[cnt] + ton[dnt];//7 = 3 + 4
				ton[dnt] = ton[cnt] - ton[dnt];//3 = 7 - 4
				ton[cnt] = ton[cnt] - ton[dnt];//4 = 7 - 3
			}*/
			if(ton[cnt] < ton[dnt])
			{
				temp=ton[cnt];
				ton [cnt]=ton[dnt];
				ton[dnt]=temp;
			}
		}
	}
	
	for(cnt = 0; cnt<m; cnt++)
		result[cnt] = 0;
	
	for(cnt = 0; cnt<m - 1; cnt++)//计算
	{
		if(pool%ton[cnt] == 0)
		{
			result[cnt] = pool / ton[cnt];
			goto END;
		}	
	}
		
	
	for(cnt = 0; cnt<m; cnt++)
	{
		result[cnt] = pool / ton[cnt];
		pool%=ton[cnt];
		
	}

END:
	for(cnt = 0; cnt<m; cnt++)
	//for(cnt=m;cnt>=0;--cnt)
		//printf("%d的桶需要%d次\n",ton[cnt],result[cnt]);
		printf("%d ",result[cnt]);
	
	return 0; 
}


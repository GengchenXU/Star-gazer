#include <stdio.h>

int main()
{
	int pool = 0,m = 0,temp;
	//printf("������ˮ���ݻ���Ͱ���������ո�ֿ�����");
	scanf("%d %d",&pool,&m);//����ˮͰ������ˮ���ݻ� 
	
	int ton[m],cnt = 0,result[m];
	//printf("����ÿͰˮ���ݻ����ո�ֿ�����");
	for(cnt = 0; cnt<m; cnt++)//����ÿͰˮ���ݻ� 
		scanf("%d",&ton[cnt]);
		
	
	int dnt = 0;
	for(cnt = 0; cnt<m; cnt++)//����,�Ӵ�С 
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
	
	for(cnt = 0; cnt<m - 1; cnt++)//����
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
		//printf("%d��Ͱ��Ҫ%d��\n",ton[cnt],result[cnt]);
		printf("%d ",result[cnt]);
	
	return 0; 
}


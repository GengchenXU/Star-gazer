
#include<stdio.h>
struct student
{
	int num;
	int score[3];
	double ave;
} stu[10];
/*int ave(struct student stu[])
{
	float ave[3];
	float sum;
	for (int j = 0; j < 3; j++)
	{
		sum = 0;
		for (int i = 0; i < 10; i++)
		{
			sum += stu[i].score[j];
		}
		ave[j] = sum / 10;
	}
	for (int j = 0; j < 3; j++)
	{
		printf("第%d门课程的平均成绩为：%.3f\n",j+1, ave[j]);
	}
	puts("*****************************************************");
	return 0;
}*/
void find(struct student stu[])
{
	int cnt = 0,dnt = 0,rnt = 0,tatol = 0;
	
	for(cnt = 0;cnt<10;cnt++)//输出平均数 排序前 
	{
		tatol = stu[cnt].score[0] + stu[cnt].score[1] + stu[cnt].score[2];
		stu[cnt].ave = tatol / 3.0;
		printf("平均分:%.2f\n",stu[cnt].ave);
	}
	struct student tmp;
	for(cnt = 0;cnt<10;cnt++)
	{
		
		for(dnt = cnt;dnt<10;dnt++)
		{
			if(stu[cnt].ave < stu[dnt].ave)
			{
				//既然要替换就要全部替换 
				tmp.ave = stu[cnt].ave; 
				tmp.num = stu[cnt].num;
		
				for(rnt = 0;rnt<3;rnt++)
					tmp.score[rnt] = stu[cnt].score[rnt];
				
				stu[cnt].ave = stu[dnt].ave;
				stu[cnt].num = stu[dnt].num;
			
				for(rnt = 0;rnt<3;rnt++)
					stu[cnt].score[rnt] = stu[dnt].score[rnt];
				
				stu[dnt].ave = tmp.ave;
				stu[dnt].num = tmp.num;
				
				for(rnt = 0;rnt<3;rnt++)
					stu[dnt].score[rnt] = tmp.score[rnt];	
				
			}	
		}
	}
	for(cnt = 0; cnt<10; cnt++)//输出顺序 
	{
		printf("%d-%d-%d-%d-%0.2f\n",stu[cnt].num,//编号 
		stu[cnt].score[0],stu[cnt].score[1],stu[cnt].score[2]//成绩 
		,stu[cnt].ave);//平均数 
	}
	/*for(cnt = 0;cnt<10;cnt++)//输出平均数 排序完 
	{
		tatol = stu[cnt].score[0] + stu[cnt].score[1] + stu[cnt].score[2];
		stu[cnt].ave = tatol / 3.0;
		printf("第%d号的同学平均分为:%.2f\n",stu[cnt].num,stu[cnt].ave);
	}*/ 
	/*printf("最高分的学生数据为：%d-%d-%d-%d-%.2f", 
	stu[0].num, stu[0].score[0], stu[0].score[1], stu[0].score[2], stu[0].ave);*/ 
}
int main()
{
	int i;
	//在次调试的时候注释掉这个循环
	//默认用数组初始化的值 
	for (i = 0; i < 10; i++)
	{
		//printf("请输入%d名学生的信息：",i+1);
		scanf("%d", &stu[i].num);
		int j;
		for (j = 0; j < 3; j++)
		{
			scanf("%d", &stu[i].score[j]);
		}
	}
	//ave(stu);
	find(stu);
	return 0;
}



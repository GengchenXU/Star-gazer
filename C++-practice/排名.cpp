#include<stdio.h>
struct student
{
	int num;
	int score[3];
}stu[10];
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
	int i, j,ta,tb;
	double tmp;
	float sum;
	double ave[10];
	for (i = 0; i < 10; i++)
	{
		sum = 0;
		for (j = 0; j < 3; j++)
		{
			sum += stu[i].score[j];
		}
		ave[i] = sum / 3.0;
	}
	/*for (i = 0; i < 10; i++){ 
	printf("平均%.2f\n",ave[i]);} */ 
	for (i = 0; i < 10; i++)
	{
		for(int j=0;j<10;j++)
		{
			if(ave[j]<ave[j+1])
			{tmp=ave[j];
			ave[j]=ave[j+1];
			ave[j+1]=tmp;
			ta=stu[j].num;
			stu[j].num=stu[j+1].num;
			stu[j+1].num=ta;
			for (int a = 0; a < 3; a++)
		{
			tb=stu[j].score[a];
			stu[j].score[a]=stu[j+1].score[a];
			stu[j+1].score[a]=tb;
		}
			}
		}
	}
			for(int t=0;t<10;t++){
			printf("%d-%d-%d-%d-%.2f\n", stu[t].num, stu[t].score[0], stu[t].score[1], stu[t].score[2], ave[t]);
			}	
			//printf("第%d个学生的平均分为：%.2f\n", i + 1, ave[i]);
		/*int t = 0;
	int max = 0;
	for (i = 0; i < 10; i++)
	{
		if (ave[max] < ave[i])
		{
			max = i;
			t = i; 
		}
	}
	printf("最高分的学生数据为：%d-%d-%d-%d-%.2f", stu[t].num, stu[t].score[0], stu[t].score[1], stu[t].score[2], ave[t]);*/
}
int main()
{
	
	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &stu[i].num);
	
		for (int j = 0; j < 3; j++)
		{
			scanf("%d", &stu[i].score[j]);
		}
	}

	//ave(stu);
	find(stu);
	return 0;
}

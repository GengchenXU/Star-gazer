#include<stdio.h>
int main()
{
	float weight;
	float value;
	printf("你值不值钱\n");
	printf("让我们康康\n");
	printf("输入你的体重：");
	scanf("%f",&weight);
	value=0.0003*weight*14.5833;
	printf("你的体重换成狗屎的价值 $%.2f.\n",value);
	printf("看来你不值钱阿\n ");
	printf("eat more to maintain your value .\n");
	return 0;

}

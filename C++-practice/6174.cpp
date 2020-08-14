/*
 * @Description: 
 * @Sample Intput: 
 * @Output: 
 * @Author: GengchenXu
 * @Date: 2020-08-14 19:47:02
 * @LastEditTime: 2020-08-14 19:49:33
 */

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void mysort(int *num);
int maxnum(int *num);
int minnum(int *num);
int main()
{
    int num[4];
    int number;
    int i=1,j,t=1;
    scanf("%d",&number);
    for(i=0;i<4;i++)
        num[i]=(int)(number/pow(10.0,(double)i))%10;
        mysort(num);
    number=maxnum(num)-minnum(num);
    printf("%d-%d=%d\n",maxnum(num),minnum(num),number);
    while(number!=6174)
    {
        for(i=0;i<4;i++)
            num[i]=(int)(number/pow(10.0,(double)i))%10;
        mysort(num);
        number=maxnum(num)-minnum(num);
        printf("%d-%d=%d\n",maxnum(num),minnum(num),number);
        t++;
    }
    printf("%d",t);
}
void mysort(int *num)
{
    int i,j,temp;
    for(i=0;i<4;i++)
        for(j=0;j<3-i;j++)
            if(num[j]<num[j+1])
            {
                temp=num[j];
                num[j]=num[j+1];
                num[j+1]=temp;
            }
}
int maxnum(int *num)
{
    int max=0,i;
    for(i=0;i<4;i++)
        max=max+(int)(num[i]*pow(10.0,3-i));
    return max;
}
int minnum(int *num)
{
    int min=0,i;
    for(i=0;i<4;i++)
        min=min+(int)(num[i]*pow(10.0,i));
    return min;
}

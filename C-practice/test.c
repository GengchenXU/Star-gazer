/*
 * @Description: 
 * @Sample Intput: 
 * @Output: 
 * @Autor: GengchenXu
 * @Date: 2020-05-26 23:59:09
 * @LastEditTime: 2020-05-28 12:02:33
 */ 
#include<stdio.h>

void b(int *a,int n)
{
    int t=10,count=0;
    
    int i,j,tmp;

    for(i=0;i<10;i++){
    scanf("%d",&a[i]);
    }
    
    for(i=0;i<t;i++)//姑且就用冒泡排序   排序方法不限
    for(j=0;j<t-1-i;j++)
    {if(a[j]>a[j+1]){
	
    tmp=a[j+1];
    a[j+1]=a[j];
    a[j]=tmp;}
    
	}

	for(i=0;i<10;i++){
		if(a[i]==a[i+1])//出现下一个数重复的就跳过输出进入下一循环
		continue;
		else printf("%d ",a[i]);
		
	}
}
int main(){
    int a[10],n=0;
    b(a,n);
    return 0;
}

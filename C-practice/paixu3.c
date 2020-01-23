#include<stdio.h>
 int main()
{
    int i,a[10],b[10],c[20]={0},j=0,flag,temp;
     int p = 10;
        for(i=0;i<p;++i)
    {
      scanf("%d",&a[i]);
    }
    flag = 1;
    while(flag)
    {
        temp = p;
        flag = 0;
        b[j] = 999999;
        for(i=0;i<p;i++)
        {
            if(a[i]%2==1&&c[i]==0)
            {
                flag = 1;
                if(a[i]<b[j])
                {
                    b[j] = a[i];
                    temp = i;
                }
            }
        }
        c[temp] = 1;
        j++;
    }
    j--;
    flag = 1;
    while(flag)
    {
        temp = p;
        flag = 0;
        b[j] = 999999;
        for(i=0;i<p;i++)
        {
            if(a[i]%2==0&&c[i]==0)
            {
                flag = 1;
if(a[i]<b[j])
                {
                    b[j] = a[i];
                    temp = i;
                }
            }
        }
        c[temp] = 1;
        j++;
	}
    for(i=0;i<p;++i)
    {
a[i]=b[i];
    printf("%d ",a[i]);
	}              
    printf("\n");
    return 0;
}

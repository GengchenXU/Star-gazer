#include<stdio.h>
int main()
{
    int n,age;
    int a,b,c,d,i;
        scanf("%d",&n);
    a=0;
    b=0;
    c=0;
    d=0;
    for(i=0;i<n;i++)
    {
        scanf("%d",&age);
        if(age>60)  d++;
        else if(age>=36)  c++;
        else if(age>=19)  b++;
        else  a++;
    }
    printf("1-18: %.2lf%%\n",a*100.0/n);
    printf("19-35: %.2lf%%\n",b*100.0/n);
    printf("36-60: %.2lf%%\n",c*100.0/n);
    printf("61-: %.2lf%%\n",d*100.0/n);
    return 0;
}

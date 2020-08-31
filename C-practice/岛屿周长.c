/*
 * @Description: 
 * @Sample Intput: 
 * @Output: 
 * @Author: GengchenXu
 * @CreateDate: 2020-08-31 21:46:28
 * @LastEditTime: 2020-08-31 21:47:29
 */
#include <stdio.h>
int a[105][105]={0};
int main()
{
    int n,m;
    int i,j;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            scanf("%d",&a[i][j]);
        }
    }
    int cnt=0;
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(a[i][j]==1){
                cnt=cnt+4-(a[i-1][j]+a[i+1][j]+a[i][j-1]+a[i][j+1]);
            }
        }
    }
    printf("%d\n",cnt);
    return 0;
}
#include<stdio.h>
int main(){
	int i,j,n,m,e,num,o,h;
        scanf("%d",&n);
    char ss[100][100];
    int hzb[100]={0},zzb[100]={0};
    for(i=0;i<n;i++){
        scanf("%s",ss[i]);
    }
    scanf("%d",&m);
    while(m>1)
    {
        e=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                    if(ss[i][j]=='@'){
                    hzb[e]=i;
                    zzb[e]=j;
                    e++;//寻找第一天得流感的人
		            }
            }
        }

        for(i=0;i<e;i++)
        {
            o=hzb[i];
            h=zzb[i];//判断病人，邻居，上一行，是否有人，有人,另感染
            if(o>=1&&ss[o-1][h]=='.')
            {
                ss[o-1][h]='@';
            }//判断病人，邻居，左列，是否有人，有人，另感染
            if(h>=1&&ss[o][h-1]=='.')
            {
                ss[o][h-1]='@';
            }  //判断病人，邻居，右列，是否有人，有人，另感染
            //h+1<=n-1,不能让列数超过给定范围
            if(h+1<=n-1&&ss[o][h+1]=='.')
            {
                ss[o][h+1]='@';
            }//判断病人，邻居，下一行，是否有人，有人，另感染
            if(o+1<=n-1&&ss[o+1][h]=='.')
            {
                ss[o+1][h]='@';
            }
        }
        m--;
    }
    num=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(ss[i][j]=='@')
            {
                num++;
            }
        }
    }
    printf("%d\n",num);
    return 0;
}

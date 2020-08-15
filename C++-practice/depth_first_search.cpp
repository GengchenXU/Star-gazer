/*
 * @Description: 
 * @Sample Intput: 2 3
 * @Output: 38
 * @Author: GengchenXu
 * @Date: 2020-08-15 20:58:26
 * @LastEditTime: 2020-08-15 21:27:49
 */
#include<iostream>
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};
bool vis[10][10];
int ans,m,n;
void dfs(int x,int y){
    vis[x][y]=1;
    if(x==n&&y==m){
        ans++;
        vis[x][y]=0;
        return;
    }
    for(int i=0;i<=3;i++){
        int nx=x+dx[i],ny=y+dy[i];
        if(nx>=0&&ny>=0&&nx<=n&&ny<=m&&!vis[nx][ny]){
            dfs(nx,ny);
        }
    }
    vis[x][y]=0;
}
int main(){
    scanf("%d%d",&n,&m);
    dfs(0,0);
    printf("%d\n",ans);
    return 0;
}
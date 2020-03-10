#include<iostream>
#include<cstring>
using namespace std;
int main()
{
   int w,l,num;
   cin>>w>>l>>num;
   int c[w+1][l+1];
   memset(c,0,sizeof(c));
   int a,b,v;
   while(cin>>a>>b){
       a=a-1;
       b=b-1;
       c[a-1][b-1]++;
       c[a-1][b]++;
       c[a-1][b+1]++;
       c[a][b-1]++;
       c[a][b+1]++;
       c[a+1][b-1]++;
       c[a+1][b]++;
       c[a+1][b+1]++;
       v++;
       c[a][b]=100;
       if(v==num){
           break;
       }
   }
   int i,j,sum=0;
   int num1,num2,num3;
   for(i=0;i<w;i++){
   for(j=0;j<l;j++){
       if(c[i][j]==1){
            num1++;
       }
        if(c[i][j]==2){
            num2++;
       }
       if(c[i][j]==3){
            num3++;
       }
        //cout<<c[i][j]<<' ';
        if(c[i][j]<100)   
       sum+=c[i][j];
   }
   //cout<<endl;
   }
   
  
   cout<<sum<<endl;
   return 0;
}

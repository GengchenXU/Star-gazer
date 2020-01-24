#include<iostream>
using namespace std;
int main() 
{
   int l,m,num=0,a,b;
   cin>>l>>m;
   int t[l+1]= {0};
   for(int i=1; i<=m; i++) {
           cin>>a>>b;
               for(int j=a; j<=b; j++)
                 t[j]=1;
}
       for(int i=0; i<=l; i++) {
          if(t[i]==0)
	   num++;
}
cout<<num<<endl;
return 0;
} 

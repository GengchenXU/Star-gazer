#include<iostream>
using namespace std;
int main(){
 int a[3][4],m,n;
 cin>>m>>n;
  for(int i=0;i<m;i++)
   for(int j=0;j<n;j++)
   cin>>a[i][j];
   
 int *p;
 for(p=&a[0][0];p<=&a[0][0]+11;p++)
	 {
 cout<<*p<<" "<<endl;
 }
   return 0;
}


#include<iostream>
using namespace std;
int main()
	{
		int n,k=100,a[100],b[100][100],c[100];
 		cin >> n;
 		for (int i = 0; i < n; i++)
  		cin >> a[i];
  		for (int i = 0; i < n; i++)
  		c[i]=a[i];
  		    for (int i = 0; i < 3; i++){
  			for(int j=0;j<n;j++)
 			{
 				b[i][j]=a[j]/k;
 				a[j]=a[j]%k;}
 				k/=10;}
 			for(int e=0;e<3;e++){
 			for(int i=0;i<n;i++){
 			for(int j=0;j<n-1;j++)
 			{
 				if(b[e][j-1]>b[e][j])
 				swap(c[j-1],c[j]);
			 }
			} 
			for(int i=0;i<n;i++){
			  cout<<c[i]<<ends;
			}
			cout<<endl;
		}
		return 0;
	}
	
	//有错但不知道为啥
	 

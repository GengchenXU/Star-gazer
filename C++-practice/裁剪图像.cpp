#include<iostream>
using namespace std;
int main()
{
	int h1,w1;
	cin>>w1>>h1;
	int x,y,h2,w2,a[20][20];
	cin>>x>>y>>w2>>h2;
	for(int i=0;i<h1;i++){
		for(int j=0;j<w1;j++){
			cin>>a[i][j];
		}
	}
	for(int i=y;i<y+h2;i++){
		for(int j=x;j<x+w2;j++){ 
		if(j==x+w2-1)  cout<<a[i][j]; 
		else cout<<a[i][j]<< ends;	
	}
      cout<<endl;
	}
	return 0;
 }

#include<iostream>
using namespace std;
void jump(int n,int a){
	int b=a[0];
	cout<<a[b];
	jump( n,a); 
}
int main()
{
	int n;
	int a[100];
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>a[i];
	}	
		jump( n,a[100]);
		return 0;
}

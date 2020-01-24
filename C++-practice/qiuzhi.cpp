#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int n,result;
	cin>>n;
	int a[20];
	for(int i=0 ;i<2*n;i++){
		cin>>a[i];
	}
	int x;
	cin>>x;
	for (int i=0;i<2*n;){
				result+=a[i]*pow(x,a[i+1]);
				i+=2;}
	cout<<result;
	return 0;
	
}

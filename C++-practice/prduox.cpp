#include<iostream>
using namespace std;
int main()
{
	int n,a[10];
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	
	for(int i=0;i<n;i++)
	{
		if(a[i]<0&&i<n-1)
		cout<<a[i]<<"x^";
		else if(a[i]>0&&i>0&&i<n-1)
			cout<<"+"<<a[i]<<"x^";
		else cout<<a[i]<<"x^";
		//else if(a[i]!=0)
		cout<<n-i;
	
	}
	
	return 0;
}		


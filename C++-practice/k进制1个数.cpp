#include<iostream> 
using namespace std;
int main()
{
	int a,num,k;
	cin>>a>>k;
	int aa[20], i;
	for(i = 0;a ; i++ )
	{
	aa[i] = a%k;
	a/= k;
	}
	for( ; i; i-- ){
	if(aa[i]==1)
	num++;}
	cout<<num;
	return 0;
	
	
}

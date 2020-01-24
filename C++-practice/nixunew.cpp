#include<iostream>
using namespace std;
int recur()
{
	char c;
	c=cin.get();
	if(c!='\n')
		recur();
		cout<<c;
		return 0;
		}	
int main(){
       	int n;
	cin>>n;	
	recur();
	return 0;
	}

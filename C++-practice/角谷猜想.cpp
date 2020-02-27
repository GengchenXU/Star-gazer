#include<iostream>
using namespace std;
int c(int a){
	if(a==1){
		cout<<"End";
		return 0;
	}
           else {
		if (a % 2 == 0) {
			cout << a << '/' << 2 << '=' << a / 2 << endl;
			a = a / 2;
			c(a);
			return 0;
		}
		if (a % 2 == 1) {
			cout << a << "*3+1=" << a * 3 + 1 << endl;			            a = a * 3 + 1;
			c(a);
			return 0;}
	   }
	   }	
int main(){
	int a;
	cin>>a;
        c(a);
	return 0;
}


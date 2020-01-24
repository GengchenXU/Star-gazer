#include<iostream>
using namespace std;
int i=0;
char a[501];
int f(){
	char c=a[i];
	i++;
	if(c==' '){
		return 1;
}
	if(c!=' '&&c!='\0'){
	f();
	cout<<c;
			
		return 1;
}
}
int main(){
	cin.getline(a,501);
	if(f()==1)
		cout<<' ';
		while(a[i]!='\0'){
			if(f()==1){
				cout<<' ';
			}
			}
			return 0;

		}



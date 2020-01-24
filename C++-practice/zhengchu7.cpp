#include<iostream>
using namespace std;
int main(){
	int d;
	while(cin>>d){
		switch((!(d%7)<<2)+(!(d%5)<<1)+(!(d%3))){
			case 0:cout<<"n"<<endl;break;
			case 1:cout<<"3"<<endl;break;
			case 2:cout<<"5"<<endl;break;
			case 3:cout<<"3 5"<<endl;break;
			case 4:cout<<"7"<<endl;break;
			case 5:cout<<"3 7"<<endl;break;
			case 6:cout<<"5 7"<<endl;break;
			case 7:cout<<"3 5 7"<<endl;break;
		}
	}
return 0;
}

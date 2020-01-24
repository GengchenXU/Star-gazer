#include <iostream>
using namespace std;
int main (){
	int n , i ; //需要办理的事情
	float walk ,bike ,Distance ; //申明走路、骑车、办事的距离
	cin >> n ;
	for( i = 0; i < n ; i++){
		cin >> Distance;
		walk = Distance / 1.2;
		bike = Distance/3.0 + 27 + 23 ;
		if( walk > bike)
			cout << "Bike"<< endl;
		else if ( bike > walk)
			cout << "Walk" << endl;
		else if ( bike == walk)
			cout << "All" << endl;
		}
		return 0 ;
	}

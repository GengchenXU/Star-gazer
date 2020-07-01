/*
 * @Description: 
 * @Sample Intput: 
 * @Output: 
 * @Autor: GengchenXu
 * @Date: 2020-03-10 22:22:46
 * @LastEditTime: 2020-07-01 21:58:42
 */ 
#include<iostream>
using namespace std;
int main() {	
	int row, col;
	cin >> row >> col;
	int shuzu[100][100];
	for (int j = 0; j < row; j++) {	
		for (int o = 0; o < col; o++) {	
			cin >> shuzu[j][o];	
		}	
	}	
	int k = col + row - 1;//共有（行数+列数-1）条对角线	
	for (int i = 0; i <= k; ++i) {//对每一条对角线进行处理	
		int c = i - 1;//对角线行数列数起始点为0，每次+1；所以，刚好起始点横坐标是对角线编号-1	
		for (int r = 0; r < row; r++) {//同理 		
		if (r>=0&&r < row&&c < col&&c>=0) {//通过这个，找到在范围内的。		
			cout << *(*(shuzu + r) + c) << endl;//只打印在范围内的		
		}				c--;//因为是由右边到左边，所以C--	
		}		
	}
	return 0;
}


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
	int k = col + row - 1;//���У�����+����-1�����Խ���	
	for (int i = 0; i <= k; ++i) {//��ÿһ���Խ��߽��д���	
		int c = i - 1;//�Խ�������������ʼ��Ϊ0��ÿ��+1�����ԣ��պ���ʼ��������ǶԽ��߱��-1	
		for (int r = 0; r < row; r++) {//ͬ�� 		
		if (r>=0&&r < row&&c < col&&c>=0) {//ͨ��������ҵ��ڷ�Χ�ڵġ�		
			cout << *(*(shuzu + r) + c) << endl;//ֻ��ӡ�ڷ�Χ�ڵ�		
		}				c--;//��Ϊ�����ұߵ���ߣ�����C--	
		}		
	}
	return 0;
}


#include<iostream>
using namespace std;
int main()
{
	int a, b, c, d;
	a = b = c = d = 0;
	for (a = 1; a <= 4; a++) {//��ͥ�����ܵ�����
		for (b = 1; b <= 4; b++) {//��������ܵ�����
			for (c = 1; c <= 4; c++) {//۶�������ܵ�����
				for (d = 1; d <= 4; d++) {//̫�����ܵ�����
					if ((a != b && a != c && a != d && b != c && b != d && c != d)
						&& ((a == 1) + (b == 4) + (c == 3) == 1) //��ΪFalse��Ϊ0�����Ϊ1˵��ֻ��һ��True
						&& ((b == 1) + (a == 4) + (c == 2) + (d == 3) == 1)
						&& ((b == 4) + (a == 3) == 1)
						&& ((c == 1) + (d == 4) + (b == 2) + (a == 3) == 1)) {
						//��˳�����
						cout << c << endl;
						cout << a << endl;
						cout << d << endl;
						cout << b << endl;
					}
				}
			}
		}
	}
	return 0;
}




 

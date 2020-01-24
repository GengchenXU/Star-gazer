#include<iostream>
using namespace std;
int main()
{
	int a, b, c, d;
	a = b = c = d = 0;
	for (a = 1; a <= 4; a++) {//洞庭湖可能的名次
		for (b = 1; b <= 4; b++) {//洪泽湖可能的名次
			for (c = 1; c <= 4; c++) {//鄱阳湖可能的名次
				for (d = 1; d <= 4; d++) {//太湖可能的名次
					if ((a != b && a != c && a != d && b != c && b != d && c != d)
						&& ((a == 1) + (b == 4) + (c == 3) == 1) //若为False则为0，相加为1说明只有一个True
						&& ((b == 1) + (a == 4) + (c == 2) + (d == 3) == 1)
						&& ((b == 4) + (a == 3) == 1)
						&& ((c == 1) + (d == 4) + (b == 2) + (a == 3) == 1)) {
						//按顺序输出
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




 

/*
 * @Description: 
 * @Autor: GengchenXu
 * @Date: 2020-04-11 13:41:34
 * @LastEditTime: 2020-04-11 13:42:24
 */
#include <iostream>
#include <cstring>
using namespace std;
class Array2 {
	// 在此处补充你的代码
private:
	int x, y;
	int *p;
public:
	Array2(int i, int j) :x(i), y(j) { p = new int[i*j]; }
	Array2() :x(0), y(0), p(NULL) {}
	int* operator [](int i) {
		return (p + i*y);//注意这里是y不是x
	}
	int& operator()(int i, int j) {
		return p[y*i + j];//注意这里是y不是x
	}
	Array2& operator=(const Array2& a) {
		if (a.p == NULL) {
			p = NULL;
			return *this;
		}
		if (p) delete[]p;
		x = a.x;
		y = a.y;
		p = new int[x*y];
		memcpy(p, a.p, sizeof(int)*x*y);
		return *this;
	}
};
int main() {
	Array2 a(3, 4);
	int i, j;
	for (i = 0; i < 3; ++i)
		for (j = 0; j < 4; j++)
			a[i][j] = i * 4 + j;
	for (i = 0; i < 3; ++i) {
		for (j = 0; j < 4; j++) {
			cout << a(i, j) << ",";
		}
		cout << endl;
	}
	cout << "next" << endl;
	Array2 b;     b = a;
	for (i = 0; i < 3; ++i) {
		for (j = 0; j < 4; j++) {
			cout << b[i][j] << ",";
		}
		cout << endl;
	}
	return 0;
}


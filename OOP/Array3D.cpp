/*
 * @Description: 
 * @Sample Intput: 
 * @Output: 
 * @Autor: GengchenXu
 * @Date: 2020-06-06 13:43:20
 * @LastEditTime: 2020-06-07 16:07:22
 */ 
#include <iostream>
#include <iomanip> 
#include <cstring>
using namespace std;
template <class T>
class CArray3D
{
// 在此处补充你的代码
public:
	T* p;
	int f, r, c; //数组共f层，每层r行,每行c列
	class CArray2D {
	public:
		T* fp; // fp是一层的元素的起始地址
		int c; //数组每行c列
		CArray2D(T* p_, int c_) :fp(p_), c(c_) { }
		T* operator[](int r) {
			return fp + r * c; //返回本层的第 r行起始地址		  
		}
		operator T* () {// T* a[i]，返回a[i]的fp,类型为T* 
			return fp; //返回值本层的起始地址	//fp表示第i行的起始位置——故a[1]对象可被强制转换为起始位置指针line 80	 
		}
	};
	CArray3D(int _f, int _r, int _c) :f(_f), r(_r), c(_c) {
		p = new T[f * r * c];
	}
	CArray2D operator[](int _f) {//第_f层元素的起始地址
		return CArray2D(p + _f * r * c, c);
	}
	~CArray3D() { delete[] p; }
};

CArray3D<int> a(3,4,5);
CArray3D<double> b(3,2,2);
void PrintA()
{
	for(int i = 0;i < 3; ++i) {
		cout << "layer " << i << ":" << endl;
		for(int j = 0; j < 4; ++j) {
			for(int k = 0; k < 5; ++k) 
				cout << a[i][j][k] << "," ;
			cout << endl;
		}
	}
}
void PrintB()
{
	for(int i = 0;i < 3; ++i) {
		cout << "layer " << i << ":" << endl;
		for(int j = 0; j < 2; ++j) {
			for(int k = 0; k < 2; ++k) 
				cout << b[i][j][k] << "," ;
			cout << endl;
		}
	}
}

int main()
{

	int No = 0;
	for( int i = 0; i < 3; ++ i ) {
		a[i];
		for( int j = 0; j < 4; ++j ) {
			a[j][i];
			for( int k = 0; k < 5; ++k )
				a[i][j][k] = No ++;
			a[j][i][i];	
		}
	}
	PrintA();
	memset(a[1],-1 ,20*sizeof(int));	
	memset(a[1],-1 ,20*sizeof(int));
	PrintA(); 
	memset(a[1][1],0 ,5*sizeof(int));	
	PrintA();

	for( int i = 0; i < 3; ++ i )
		for( int j = 0; j < 2; ++j )
			for( int k = 0; k < 2; ++k )
				b[i][j][k] = 10.0/(i+j+k+1);
	PrintB();
	int n = a[0][1][2];
	double f = b[0][1][1];
	cout << "****" << endl;
	cout << n << "," << f << endl;
		
	return 0;
}

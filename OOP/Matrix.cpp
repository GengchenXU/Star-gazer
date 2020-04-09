/*
 * @Description: 
 * @Autor: GengchenXu
 * @Date: 2020-04-01 19:33:21
 * @LastEditTime: 2020-04-09 21:44:11
 */
#include <iostream>
#include <cstring>
using namespace std;
class Matrix {
private:
    int **p;
    int r;
    int c;
public:
    static int total;
    Matrix(){
        r=10;
        c=10;
        p= new int*[r];    //指向一级指针数组
    for (int i = 0; i < r; i++) {
        p[i] = new int[c];  //指向一维数组
    }
    }
    Matrix(int m, int n) {
    r = m;
    c = n;
    p= new int*[r];    //指向一级指针数组
        for (int i = 0; i < r; i++) {
            p[i] = new int[c];  //指向一维数组
        }
    }
    Matrix & operator=(const Matrix &A)
    {
        int i, j;
        this->r = A.r;
        this->c = A.c;
        if (p != NULL)    // 要先清除，否则行数列数会被改变
        {
            for (i = 0;i < r;i++)
                delete p[i];
            delete[]p;
        }
        p = new int *[r];
        for (i = 0;i <r;i++)
            p[i] = new int[c];
        return *this;
    }
    Matrix(const Matrix & is){//拷贝构造函数
    r = is.r;
    c = is.c;
    p = new int*[r];
    for (int i = 0; i < r; i++)
    {
        p[i] = new int[c];
    }
    }
    ~Matrix(){
        for (int i = 0; i < r; ++i) {
			delete[] p[i];
		}
		delete[] p;
        total++;
        cout<<"fuck"<<" "<<total<<endl;
    }
    friend Matrix operator * (const Matrix &L, const Matrix &R){
        Matrix e(L.r, R.c);        //创建一个m行n列的矩阵，行数与L相等，列数与R相等
        Matrix b=e;
        Matrix temp;
        temp=b;
        for (int i = 0; i < L.r; i++) {
            for (int j = 0; j < R.c; j++) {
                long sum=0;
                for (int k = 0; k < L.c; k++) {
                    sum += L.p[i][k] * R.p[k][j];    //累加第i行与第j列的元素乘积
                }
                temp.p[i][j] = sum;   //赋给i,j元素
            }
        }
        return temp;
    }
    friend istream & operator >> (istream &o,  Matrix &a){
        o>> a.r>> a.c;
        //Matrix(a.r, a.c);
        for(int i = 0;i < a.r;i ++){
            for(int j = 0;j < a.c;j ++) 
            o >> a.p[i][j] ;
            //o >> endl;
        }
        return o;
    }
    friend ostream & operator << (ostream &o, const Matrix &a){
        for(int i = 0;i < a.r;i ++){
            for(int j = 0;j < a.c;j ++) o << a.p[i][j] << " ";
            o << endl;
        }
        return o;
    }
};
int Matrix::total=0;


int main() {
    Matrix a, b;
    cin >> a >> b;
    cout << a * b << endl;
    return 0;
}
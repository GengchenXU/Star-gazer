/*
 * @Description: 
 * @Autor: GengchenXu
 * @Date: 2020-04-25 14:29:22
 * @LastEditTime: 2020-04-25 14:31:09
 */
#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;

class A {
// 在此处补充你的代码
private:
    int v;
    char c[10];
public:
    A(int n):v(n){}
    friend ostream &operator<<(ostream& o, const A& a) {
        o << a.v;
        return o;
    }
    operator string() {
        sprintf(c,"%d",this->v);//字符串转换
        return string("A:v=") + c;//string类重载，字符串相加
    }
};
int main()
{
    A a(5),b(6);
    cout << (string)a <<  endl;
    cout <<  b <<  endl;
    return 0;
}

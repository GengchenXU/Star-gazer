#include<iostream>
using namespace std;
int pd(int d)
{
 switch ((!(d % 7) << 2) + (!(d % 5) << 1) + (!(d % 3))) {
  //**此处的精妙点在于只用了三次求余，把每次求余的结果组合成一个
  //三位二进制数来恰好表示所需要的八种情况**
 case 0:cout << "n" << endl; break;
 case 1:cout << "3" << endl; break;
 case 2:cout << "5" << endl; break;
 case 3:cout << "3 5" << endl; break;
 case 4:cout << "7" << endl; break;
 case 5:cout << "3 7" << endl; break;
 case 6:cout << "5 7" << endl; break;
 case 7:cout << "3 5 7" << endl; break;
 }return 0;
}
int main() {
 int d;
 while( cin >> d)
    {
 pd(d);}
 return 0;
}
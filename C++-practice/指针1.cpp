#include <iostream>

using namespace std;



int main()

{

  int a = 100;

  char str[20] = "c.biancheng.net";

 cout<<hex<<&a<<", "<<hex<<str<<endl;

  cout<<"sizeof int: "<<sizeof(a)<<", sizeof str[20]: "<<sizeof(str)<<endl;

  return 0;

}

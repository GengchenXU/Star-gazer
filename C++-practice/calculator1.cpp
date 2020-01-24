#include <iostream>
using namespace std;

int main()
{
    int a = 0, b = 0;
    char operate = 0;
    cin >> a>>b >> operate;

    switch(operate)
    {
    case '+':cout << a+b << endl;break;
    case '-':cout << a-b << endl;break;
    case '*':cout << a*b << endl;break;
    case '/':if (b == 0)
            {
                    cout << "Divided by zero!" << endl;
            } 
            else
            {
                cout << a/b << endl;
            }
            break;
    default:cout << "Invalid operator!" << endl;break;
    }
    return 0;
}


#include <iostream>
using namespace std;

char boy;

int reline(char str[], int s)
{
    int n;
    if (str[s] != boy)
    {
        return s;
    } 
    else
    {
        n = reline(str, s+1);
        cout << s << ' ' << n << endl;
        return reline(str, n+1);
    }
}
int main()
{
    char str[101] = {0};
    cin >> str;
    boy = str[0];
    int n = reline(str, 1);
    cout << "0 " << n << endl;  
    return 0;
}


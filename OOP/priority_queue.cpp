/*
 * @Description: 
 * @Sample Intput: 1
10 7 66 4 5 30 91 100 8 9
 * @Output: 66 5
 * @Autor: GengchenXu
 * @Date: 2020-06-20 13:46:07
 * @LastEditTime: 2020-06-20 14:27:37
 */ 

#include <iostream>
#include <cmath>
#include <set>
using namespace std;

//判断一个数是否为质数
bool isPrime(int iVal)
{
    for (int i = 2; i <= sqrt((float)iVal); i++)
    {
        if (iVal % i == 0)
            return false;
    }
    return true;
}

//得到一个数的质因数数目
int getFactor(int val)
{
    int sum = 0;
    int k = 0;
    for (int i = 2; i <= sqrt((float)val); i++)
    {
        if (val % i == 0)//即a/i = k，无余数
        {
            k = val / i;
            if (i != k && isPrime(k))
                sum += 1;
            if (isPrime(i))
            {
                sum += 1;
            }
        }
    }
    return sum;
}

//函数对象，判断大小
class _Compare
{
public:
    bool operator()(const int& a, const int& b)
    {
        int sumA = 0, sumB = 0;
        sumA = getFactor(a);
        sumB = getFactor(b);
        if (sumA == sumB)//当因数个数相同时，比较数值大小
        {
            if (a < b)
            {
                return true;
            }
            else
                return false;
        }
        else if (sumA > sumB)
        {
            return false;
        }
        else
            return true;
    }
};


int main()
{
    set<int, _Compare> queue;
    int n = 0;
    cin >> n;
    while (n--)
    {
        int num;
        for (int i = 0; i < 10; i++)
        {
            cin >> num;
            queue.insert(num);
        }
        //set<int>::iterator it;
        // for (it = queue.begin(); it!=queue.end(); it++)
        // {
        //     cout<<*it<<ends;
        // }
        int min = *(queue.begin());
        int max = *(queue.rbegin());
        queue.erase(max);
        queue.erase(min);
        cout << max << " " << min << endl;
    }
    return 0;
}
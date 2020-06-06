/*
 * @Description: 
 * @Sample Intput: 
 * @Output: 
 * @Autor: GengchenXu
 * @Date: 2020-06-06 16:44:07
 * @LastEditTime: 2020-06-06 16:45:29
 */ 
/*
 * @Description: 现有一整数集（允许有重复元素），初始为空。我们定义如下操作：
add x 把x加入集合
del x 把集合中所有与x相等的元素删除
ask x 对集合中元素x的情况询问
对每种操作，我们要求进行如下输出。
add 输出操作后集合中x的个数
del 输出操作前集合中x的个数
ask 先输出0或1表示x是否曾被加入集合（0表示不曾加入），再输出当前集合中x的个数，中间用空格格开。
输入
第一行是一个整数n，表示命令数。0<=n<=100000。后面n行命令，如Description中所述。
* @Sample Intput: 7
add 1
add 1
ask 1
ask 2
del 2
del 1
ask 1
 * @Output: 1
2
1 2
0 0
0
2
1 0
 * @Autor: GengchenXu
 * @Date: 2020-06-06 16:44:07
 * @LastEditTime: 2020-06-06 16:44:08
 */ 
#include<iostream>
#include<set>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    multiset<int> s;
    set<int> s1; 
    string cmd; 
    cin >> n;
    int ii;
    for(ii = 0; ii < n; ii++)
    {
        cin >> cmd;
        if(cmd == "add")
        {
            int x;
            cin >> x;
            s.insert(x);
            s1.insert(x);
            cout << s.count(x) << endl;
        }
        else if(cmd == "del")
        {
            int x;
            cin >> x;
            cout << s.count(x) << endl;
            multiset<int>::iterator i;
            i = s.lower_bound(x);
            while(*i == x && i != s.end())
            {
                s.erase(i++);  
            }
        }
        else if(cmd == "ask")
        {
            int x;
            cin >> x;
            set<int>::iterator i1 = s1.find(x);
            if(i1 != s1.end())
            {
                cout << '1' << " " << s.count(x);
            }
            else cout << '0' << " " << s.count(x);
            cout << endl;
        }
    }
    return 0;
}



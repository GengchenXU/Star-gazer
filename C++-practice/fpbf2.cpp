#include <iostream>
#include <iomanip>
//#include <cstdio>
using namespace std;
int main()
{
    float degree[50];
    int num[50];
    int m;
    float max;
    cin >> m >> max;
    //int q = 0;
    //while (q <m ) {
    //    cin >> num[i] >> degree[i];
    //    q++;
    //    m--;//问题出现在这里！！导致m出了问题(原先是用while(m>0))
    //}
    for (int i = 0; i < m; i++) {
        cin >> num[i] >> degree[i];
    }
    /*
    ** 可以先对严重程度进行从大到小排序
    */
    //bool flag = false;
    for (int i = 0; i < m; i++) {
        //if (degree[i] >= max) {
        //    flag = true;
        //}
        for (int j = i + 1; j < m; j++) {
            float tempdegree;
            int tempnum;
            if (degree[i] >= max && degree[i] < degree[j]) {
                tempdegree = degree[i];
                tempnum = num[i];
                degree[i] = degree[j];
                num[i] = num[j];
                degree[j] = tempdegree;
                num[j] = tempnum;
            }
        }
    }
    /*
    **如果把这个条件判断放在排序一起进行的话，排序的条件要做出相应的改变
    */
    bool flag = false;
    for (int i = 0; i < m; i++) {
    if (degree[i] >= max) {
            flag = true;
        }
    }
    //cout << flag << endl;
    if (flag == false) {
        //cout << "None" << endl;//知道为什么一直错了吗？
        cout << "None." << endl;
        return 0;//直接结束
    }
    
    else {
        for (int i = 0; i < m; i++) {
            if (degree[i] >= max) {
                printf("%03d", num[i]);
                //std::cout << std::setprecision(1) << degree[i] << '\n';
                //cout << ' ' << fixed << setprecision(1) << degree[i] << endl;
                cout << ' ' << setiosflags(ios::fixed) << setprecision(1) << degree[i] << endl;
            }
        }
        return 0;
    }
    
    
 
}


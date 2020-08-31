/*
 * @Description: 
 * @Sample Intput: 
 * @Output: 
 * @Author: GengchenXu
 * @CreateDate: 2020-08-31 21:58:12
 * @LastEditTime: 2020-08-31 21:59:09
 */
#include<iostream>
using namespace std;

int main(){
    int n = 0, m = 0;
    int res[1005][12] = {0}; //N<= 1000, M<= 10, with 0 means sum
    int volume[12] = {0};
    int min, min_num, index;    //��С��������С������Ӧǰһ��������С������ӦˮͰID

    cin >> n >> m;
    for(int i = 1; i <= m; i++)
        cin >> volume[i];
    // cout << "volume ";
    // for(int i = 1; i <= m; i++)
    //     cout << volume[i];
    // cout << endl;
    
    for(int cur = 1; cur <= n; cur++){
        min = n;
        for(int i = 1; i <= m; i++){
            int last = cur - volume[i];
            if (last >= 0 && min > res[last][0] + 1)
            {
                min = res[last][0] + 1;
                index = i;
                min_num = last;
            }
        }

        res[cur][0] = min;
        for(int i = 1; i <= m; i++)
            res[cur][i] = res[min_num][i];  //��������
        res[cur][index] += 1;
    }

    //result
    for(int i = 1; i <= m; i++){
        cout << res[n][i];
        if(i != m)
            cout << ' ';
    }
    return 0;
}

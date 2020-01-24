#include<iostream>
using namespace std;

int main(){
    int n = 0, m = 0;
    int res[1005][12] = {0}; //N<= 1000, M<= 10, with 0 means sum
    int volume[12] = {0};
    int min, min_num, index;    //最小数量，最小数量对应前一个数，最小数量对应水桶ID

    cin >> n >> m;
    for(int i = 1; i <= m; i++)
        cin >> volume[i];
   
    
    for(int cur = 1; cur <= n; cur++)
	{
        	min = n;
        	for(int i = 1; i <= m; i++)
			{
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
            res[cur][i] = res[min_num][i];  //复制数组
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

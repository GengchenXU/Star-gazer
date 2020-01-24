#include<iostream>
using namespace std;

int main(){

    int a[1000];//存放要排序的数
    int N;
    int K;

    cin >> N;
    cin >> K;

    for (int i = 0; i < N; i++){
        cin >> a[i];
    }

    //冒泡排序法对数组进行排序
    for (int i = 0; i < N; i++){
        for (int j = 1; j < N - i; j++){
            if (a[j - 1] < a[j]){
                int temp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = temp;
            }
        }
    }

    cout << a[K - 1] << endl;
       return 0;
}


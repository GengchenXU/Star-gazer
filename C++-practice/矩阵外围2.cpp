#include<iostream>

using namespace std;

int main() {
    int k, l, a[100][100];
    cin >> k;
    while (k > 0) {
        int m, n, i, j;
        int sum = 0;
        cin >> m >> n;
        for (i=0; i < m; i++) 
        {
            for (j=0; j < n; j++) 
            {
                cin >> a[i][j];
                if (i==0||i==m-1||j==0||j==n-1) {
                    sum += a[i][j];
                }
            }
        }
        cout << sum << endl;
        k--;
    }
    return 0;
}

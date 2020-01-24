#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main()
 {
      int n;
      float a[100], b[100], max = 0;
      cin >> n;
      for (int i = 0; i < n; i++)
        {
             cin >> a[i] >> b[i];
         }
         for (int i = 0; i < n- 1; i++)
             for (int j = i; j < n - 1; j++)
             {
                 float temp = sqrt((a[i] - a[j + 1])*(a[i] - a[j + 1]) + (b[i] - b[j + 1])*(b[i] - b[j + 1]));
                 if (temp > max) {
                     max = temp;
                }
             }
	      //printf("%.6g",max);不补0

         cout << fixed << setprecision(4) << max << endl;
    return 0;
}

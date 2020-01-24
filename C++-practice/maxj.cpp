#include <iostream>
#include <vector>
#include <math.h>
#include <iomanip>
using namespace std;

int main()
{
    int n = 0;
    cin >> n;
    vector<float> PointX(n, 0), PointY(n, 0);
    float DisTemp = 0, DisBiggest = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> PointX[i] >> PointY[i];
    }

    for (int i = 0; i < n-1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            DisTemp = sqrt((PointX[i]-PointX[j])*(PointX[i]-PointX[j])+(PointY[i]-PointY[j])*(PointY[i]-PointY[j]));
            if (DisTemp > DisBiggest)
            {
                DisBiggest = DisTemp;
            }
        }
    }

    cout << fixed << setprecision(4) << DisBiggest << endl;
    return 0;
}

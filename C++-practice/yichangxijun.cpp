# include <iostream>
# include <cmath>
using namespace std;
int main () {
    int n;
    int a[1000][1000];
    cin>>n;
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            cin>>a[i][j];
    int k=0;
    for (int i=1;i<n-1;i++)
        for (int j=1;j<n-1;j++)
            if ((a[i-1][j]-a[i][j]>=50)&&(a[i+1][j]-a[i][j]>=50)&&(a[i][j-1]-a[i][j]>=50)&&(a[i][j+1]-a[i][j]>=50)) 
            {
              k++;
            }
    cout<<k<<endl;
    return 0;
}

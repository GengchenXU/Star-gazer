#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int ID;
    int n;
    char x;
    float y;
    float sum[6]={0};
    while(cin >> ID >> n ){
        for(int i = 0;i < n;++i){
            cin >>  x >> y;
            if(x == 'A')
                sum[3] += y;
            else if(x == 'B')
                sum[4] += y;
            else if(x == 'C')
                sum[5] += y;
            sum[ID -1] += y;
        }
    }
    cout << "1" << " " << fixed << setprecision(2)<< sum[0] << endl;
    cout << "2" << " " << fixed << setprecision(2)<< sum[1] << endl;
    cout << "3" << " " << fixed << setprecision(2)<< sum[2] << endl;
    cout << "A" << " " << fixed << setprecision(2)<< sum[3] << endl;
    cout << "B" << " " << fixed << setprecision(2)<< sum[4] << endl;
    cout << "C" << " " << fixed << setprecision(2)<< sum[5] << endl;
	return 0;
}


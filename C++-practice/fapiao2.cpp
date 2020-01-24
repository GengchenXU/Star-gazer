#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int ID;
    int n;
    char x;
    float y;
    float sum[3]={0},d=0,e=0,f=0; 
    while(cin >> ID >> n ){
        for(int i = 0;i < n;++i){
            cin >>  x >> y;
            if(x == 'A')
                d+= y;
            else if(x == 'B')
                e += y;
            else if(x == 'C')
                f += y;
            sum[ID -1] += y;
        }
    }
    cout << "1" << " " << fixed << setprecision(2)<< sum[0] << endl;
    cout << "2" << " " << fixed << setprecision(2)<< sum[1] << endl;
    cout << "3" << " " << fixed << setprecision(2)<< sum[2] << endl;
    cout << "A" << " " << fixed << setprecision(2)<< d << endl;
    cout << "B" << " " << fixed << setprecision(2)<< e << endl;
    cout << "C" << " " << fixed << setprecision(2)<< f << endl;
	return 0;
}


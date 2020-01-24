#include<iostream>
using namespace std;
void huiwen(int n)
{
	int m, revn = 0;
	int k = n;
	while(k)
	{
		m = k % 10;
		revn = revn * 10 + m;
		k /= 10;
	}
	if(n == revn)
	sun
		cout << n << endl;
}
int main()
{
	int n;
	for ( n = 1000; n < 10000; n++)
        huiwen(n);
	return 0;
}

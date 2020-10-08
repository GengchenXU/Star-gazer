#include<iostream>
const int seasons=4;
struct cost{
	double expense[seasons];
};
using namespace std;
const char * snames[4]={"spring","summer","fall","winter"};//¿Õ×Ö·û¼ÓÒ»£¡£¡ 
void fill(cost &a);
void show(cost a);
int main()
{
	cost a;
	fill(a);
	cout<<a.expense[1];
	show(a);
	return 0;
}
void fill(cost &pa)
{
    for (int i = 0; i < seasons; i++)
    {
	cout << "Enter " << snames[i] << " expenses: ";
	cin >> pa.expense[i];
	cout<<pa.expense[i];
    }
}

void show(cost pa)
{
    double total = 0.0;
    cout << "\nEXPENSES\n";
    for (int i = 0; i < seasons; i++)
    {
	cout << snames[i] << ": $" << pa.expense[i] << endl;
	total += pa.expense[i];
    }
    cout << "Total Expenses: $" << total << endl;
}

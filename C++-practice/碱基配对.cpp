#include<iostream>
using namespace std;
int main()
{
	int n;
	char a[100][100];
	cin>>n;
	for(int i=0;i<n;i++)
	cin>>a[i];
	for (int i = 0; i < n; i++){
        int j = 0;
        while (a[i][j] != '\0'){
            switch (a[i][j]){
            case 'A': cout << 'T'; break;
            case 'T': cout << 'A'; break;
            case 'G': cout << 'C'; break;
            default: cout << 'G';
            }
            j++;
        }
        cout << endl;
    }
} 

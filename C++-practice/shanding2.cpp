#include<iostream>
using namespace std;
int main()
{
	int m,n,i,j;
	int a[100][100]={0,0};
	cin>>m>>n;
	for (i=0;i<m;i++)
		for (j=0;j<n;j++)
			cin>>a[i][j];
	for (i=0;i<m;i++)
		for(j=0;j<n;j++)
			if (a[i][j]>=a[i-1][j]&&a[i][j]>=a[i+1][j]&&a[i][j]>=a[i][j-1]&&a[i][j]>=a[i][j+1]) 
				cout<<i<<" "<<j<<endl;
				return 0;
				

}

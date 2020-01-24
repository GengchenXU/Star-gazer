#include<iostream>
using namespace std;
int main(){
	int k,b,a[100][100];
	cin>>k;
	for(b=1;b<=k;b++){
	int i,j,m,n,x=0;	
	cin >> m >> n;
	for (i=0;i<m;i++)
	{		
		for (j=0;j<n;j++)
		{			
			cin >> a[i][j];			
			if (i==0 || i==m-1 ||j==0 || j==n-1)				
				x += a[i][j];		
		}	
	}	
		cout << x;
		}
		return 0;

}

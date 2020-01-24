#include<iostream>
using namespace std;
int main(){
	int row,col;
	int array[100][100];
	cin>>row>>col;
	for(int i=0;i<row;i++)
		for(int j=0;j<col;j++)
			cin>>array[i][j];
			for(int i=0;i<row+col;i++)
				for(int j=i;j>=0;j--)
					if(j<col&&i-j<row)
					cout<<array[i-j][j]<<endl;
					return 0;
}

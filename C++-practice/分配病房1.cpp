#include<iostream>
using namespace std;
int main()
{
	int m,max,e;
	int t[100];
	float r[100];
	cin>>m>>max;
	for(int i=0;i<m;i++){
		cin>>t[i]>>r[i];
		}
	for (int i=0;i<m;i++){
			for(int j=i+1;j<m;j++){
			float tempr;
			int tempt;
			if(r[i]>=max&&r[i]<r[j])
				tempr=r[i];
				tempt=t[i];
				r[i]=r[j];
				t[i]=t[j];
				r[j]=tempr;
				t[j]=tempt;  }}
	
			for(int j=0;j<m;j++)
				if(r[j]>=max&&e!=0){
					printf("%03d",t[j]);
					cout << fixed << setprecision(1) << r[j] << endl;

					e++ ;

				}
				else if(e=0)
					cout<<"None.";
					return 0;
}

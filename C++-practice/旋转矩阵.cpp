#include <iostream>
using namespace std;
//����˳ʱ����ת90��
void Rotation(int arr[100][100] ,int m,int n){ 
int tmp[n][m];//�ֲ��������������������Զ��ͷ� 
int dst=m-1;   //�������Ǵ�Ŀ���������һ�п�ʼ�������
//˳ʱ����ת����90�� 
for(int i=0;i<m;i++,dst--)  
for(int j=0;j<n;j++)   
tmp[j][dst]=arr[i][j]; //����ת��ľ��󱣴��ԭ���ľ���
 for(int i=0;i<n;i++)  
 for(int j=0;j<m;j++)   
 arr[i][j]=tmp[i][j];
 }
int main()
 { 
 	int m,n,N,temp;
 	int arr[100][100];
 	cin>>m>>n>>N;
 for(int i=0;i<m;i++){
 	for(int j=0;j<n;j++){
 	cin>>arr[i][j];
 	}
 }
 for(int i=0;i<N;i++){
	 Rotation(arr, m ,n);
		swap(m,n); 
	} 
    for(int i=0;i<m;i++) {  
			 for(int j=0;j<n;j++) {
			 if(j==n-1)  cout<<arr[i][j]; 
		else cout<<arr[i][j]<<" ";  
			
			 	 	}
	 			cout<<endl; 
				 } 
	 		
	 	return 0;
	 }
	 



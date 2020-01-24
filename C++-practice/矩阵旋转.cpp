#include <iostream>
using namespace std;
//矩阵顺时针旋转90度
void Rotation(int arr[100][100] ,int m,int n){ 
int tmp[n][m];//局部变量，函数调用完后会自动释放 
int dst=m-1;   //这里我们从目标矩阵的最后一列开始存放数据
//顺时针旋转矩阵90度 
for(int i=0;i<m;i++,dst--)  
for(int j=0;j<n;j++)   
tmp[j][dst]=arr[i][j]; //将旋转后的矩阵保存回原来的矩阵
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
```

#include<iostream>
#include<stdlib.h> 
using namespace std;
#define RADIX_10 10  
  //整形排序
  #define KEYNUM_31 10     //关键字个数，这里为整形位数 // 打印结果
  void Show(int  arr[], int n){    
  int i;   
   for ( i=0; i<n; i++ )     
      printf("%d  ", arr[i]); 
	     printf("\n");} // 找到num的从低到高的第pos位的数据
		 int GetNumInPos(int num,int pos){
		 	int temp = 1;
			 	for (int i = 0; i < pos - 1; i++)	
				 	temp *= 10;   
					  	return (num / temp) % 10;}  //基数排序  pDataArray 无序数组；iDataNum为无序数据个数
						  void RadixSort(int* pDataArray, int iDataNum){	
						  int *radixArrays[RADIX_10];    //分别为0~9的序列空间
						  	for (int i = 0; i < 10; i++)	{	
							  	radixArrays[i] = (int *)malloc(sizeof(int) * (iDataNum + 1));		
								  radixArrays[i][0] = 0;    //index为0处记录这组数据的个数	
								  }		for (int pos = 1; pos <= KEYNUM_31; pos++)    //从个位开始到31位
								  	{		for (int i = 0; i < iDataNum; i++)    //分配过程	
									  	{			int num = GetNumInPos(pDataArray[i], pos);	
										  		int index = ++radixArrays[num][0];		
												  	radixArrays[num][index] = pDataArray[i];	
													  	}        	
														  	for (int i = 0, j =0; i < RADIX_10; i++)    //收集		
															  {			for (int k = 1; k <= radixArrays[i][0]; k++)	
															  			pDataArray[j++] = radixArrays[i][k];		
																		  	radixArrays[i][0] = 0;    //复位	
																			  	}	
																				  }
																				  } 
int main(){  
		int n,a[n];
		cin  >>n;
		for(int i=0;i<n;i++){
			cin>>a[i];
		}  
		Show( a, n );   
		 RadixSort( a, n);    //排序后数组序列   
		  Show( a, n );    
		  return 0;
		  }


#include<stdio.h> 
#include<stdlib.h> 
#define Max_ 10      //�������
#define RADIX_10 10    //��������
#define KEYNUM_31 10     //�ؼ��ָ���������Ϊ����λ�� // ��ӡ���
void Show(int  arr[], int n){    
	int i;   
	for ( i=0; i<n; i++ )    
    printf("%d  ", arr[i]);   
	printf("\n");
} // �ҵ�num�Ĵӵ͵��ߵĵ�posλ������
int GetNumInPos(int num,int pos){	
	int temp = 1;	
	for (int i = 0; i < pos - 1; i++)	
	  	temp *= 10;    
	return (num / temp) % 10;
}  //��������  pDataArray �������飻iDataNumΪ�������ݸ���
void RadixSort(int* pDataArray, int iDataNum){
  	int *radixArrays[RADIX_10];    //�ֱ�Ϊ0~9�����пռ�
	for (int i = 0; i < 10; i++)	{		
		radixArrays[i] = (int *)malloc(sizeof(int) * (iDataNum + 1));	
		radixArrays[i][0] = 0;    //indexΪ0����¼�������ݵĸ���
	}	
	for (int pos = 1; pos <= KEYNUM_31; pos++){    //�Ӹ�λ��ʼ��31λ
 		for (int i = 0; i < iDataNum; i++){    //�������	
			int num = GetNumInPos(pDataArray[i], pos);		
			int index = ++radixArrays[num][0];		
			radixArrays[num][index] = pDataArray[i];	
		}        	
  		for (int i = 0, j =0; i < RADIX_10; i++) {   //�ռ�	
			for (int k = 1; k <= radixArrays[i][0]; k++)		
				pDataArray[j++] = radixArrays[i][k];	
				radixArrays[i][0] = 0;    //��λ	
		}
	}
} 
int main(){   //��������    
int arr_test[Max_] = { 18, 24, 42, 33, 5, 71, 66, 69, 80, 57 };    //����ǰ��������  
	Show( arr_test, Max_ );   
	RadixSort( arr_test, Max_);    //�������������   
	Show( arr_test, Max_ );   
    return 0;
}


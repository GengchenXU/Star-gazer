#include<iostream>
#include<iomanip> 
using namespace std;
int main()
		{
				int a[3][4]={1,3,5,7,9,11,13,15,17,19,21,23};
				int (*p)[4],i,j;//p=a,a��a��3�� ��4���ĵ�һ��Ԫ�ص�ָ���һ��Ԫ����ָһ������4��int��Ԫ�ص�һά����,p�Ļ����Ͱ���4��int��Ԫ�ص�һά���� 
				p=a;
				cin>>i>>j;
				cout<<setw(4)<<a[i][j];
				cout<<setw(4)<<*(*(p+i)+j);//p��ָ��һ������4��int��Ԫ�صĵ�һά����p+i�ǵ�i+1������4����������ַ��p+i�ȼ�&a��i����*��p+i���ȼ���a��i����*��p+i��+j�ȼ���a��i��+j����Ϊa��i��+j�ȼ�&a��i����j��*(*(p+i)+j)�ȼ���a��i����j�� 
				cout<<setw(4)<<p[i][j];//c��׼���� 
				return 0; 
		}

#include<iostream>
#include<iomanip> 
using namespace std;
int main()
		{
				int a[3][4]={1,3,5,7,9,11,13,15,17,19,21,23};
				int (*p)[4],i,j;//p=a,a是a【3】 【4】的第一个元素的指针第一个元素是指一个包含4个int型元素的一维数组,p的基类型包含4个int型元素的一维数组 
				p=a;
				cin>>i>>j;
				cout<<setw(4)<<a[i][j];
				cout<<setw(4)<<*(*(p+i)+j);//p是指向一个包含4个int型元素的的一维数组p+i是第i+1个包含4个。。。地址，p+i等价&a【i】，*（p+i）等价与a【i】；*（p+i）+j等价于a【i】+j。因为a【i】+j等价&a【i】【j】*(*(p+i)+j)等价于a【i】【j】 
				cout<<setw(4)<<p[i][j];//c标准都可 
				return 0; 
		}

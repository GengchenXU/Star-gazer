/*
 * @Description: 
 * @Sample Intput: 
 * @Output: 
 * @Author: GengchenXu
 * @Date: 2020-03-10 22:22:46
 * @LastEditTime: 2020-08-14 19:41:24
 */
#include<iostream>
using namespace std;
int main()
	{
	int n,sum=0,flag=0,k=0;
	int a[100];
	cin>>n;
	for (int i=0;i<n;i++){
		cin >>a[i];
	}
	int *p=&a[0];
	
/*	while(k<n&&k>=0&&sum<20) {
		cout<<k<<" "<<a[k]<<endl;
		sum++;
		if(k==n-1)
		{
			flag=1;
		break;
		}
		k+=*(p+k);
		
	} 
	while(k<n&&k>=0&&sum<20){
		cout<<k<<" "<<a[k]<<endl;
		sum++;
		if(k==n-1)
		{
			flag=1;
			break;
		}
		k+=a[k];
	}
	if(flag==1)
	{
	cout<<"yes"<<endl;
	}
	else
	{
	cout<<"no"<<endl;
	}
	return 0;
	}*/
	while(k<n&&k>=0&&sum<20){
		cout<<k<<" "<<a[k]<<endl;
		sum++; 
		k+=a[k];}
		if(k==1){
		cout<<"yes"<<endl;
	}
	else
	{
	cout<<"no"<<endl;//´íÎó 
	}
	return 0;}
		 
		
		
		
		
		
		
		
		
		
		
		
		
		

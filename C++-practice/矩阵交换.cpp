/*
 * @Description: 
 * @Sample Intput: 
 * @Output: 
 * @Autor: GengchenXu
 * @Date: 2020-03-10 22:22:46
 * @LastEditTime: 2020-07-01 21:56:01
 */ 
#include<iostream>
#include<iomanip>
    using namespace std;
        int main(){
        int a[1000][1000];
        for(int i=0;i<5;i++)
            for(int j=0;j<5;j++)
                cin>>a[i][j];
        int n,m;
        cin>>n>>m;
        if(n>=0&& n<=5 && m>=0 && m<=5)
        {
		swap(a[n],a[m]);
            /*for(int k=0;k<5;k++)
                swap(a[n][k],a[m][k]);*/
            for(int i=0;i<5;i++)
            {
                for(int j=0;j<5;j++)
                    cout<<setw(4)<<a[i][j];
                    cout<<endl;
            }
        }
        else
            cout<<"error"<<endl;
    return 0;
    }


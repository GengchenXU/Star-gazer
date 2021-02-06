/*
 * @Description: 
 * @Sample Intput: 
 * @Output: 
 * @Author: GengchenXu
 * @CreateDate: 2021-02-06 22:15:59
 * @LastEditTime: 2021-02-06 22:24:42
 */
#include <iostream>    
#include <algorithm>    
using namespace std;  
typedef struct 
{        
    int x;        
    int y;    
} Position; //λ��@@@    
int m[30][30]; //��ͼ    
Position first, second; //��ǰλ�ã���һ��λ��    
Position DIR[4]={0, 1, 1, 0, 0, -1, -1, 0}; //�ҡ��¡����Ϸ�������@@@    
void Init(int n)    {        
    for(int i=1; i<=n; i++)        
    {            
        for(int j=1; j<=n; j++) //�������г�ʼ��Ϊ0               
        m[i][j]=0;        
    }        
    for(int j=0; j<=n+1; j++) //������������Χǽ            
    m[0][j]=m[n+1][j]=-1;        
    for(int i=0; i<=n+1; i++) //������������Χǽ            
    m[i][0]=m[i][n+1]=-1;    }   
    void Print(int start, int endi)//start, endiΪ��ʼ�ͽ����±�    
    {        
        for(int i=start; i<=endi; i++)        
        {            
            cout<<m[i][start];            
            for(int j=start+1; j<=endi; j++)            
            {                
                cout<<"\t"<<m[i][j];            
            }            
            cout<<endl;        
        }        
        cout<<endl;    
    }   
    // n��ԭ�����ģ    
    // m����ͼ����    
    void Solve(int n)    
    {        
        first.x=1; //���Ͻ��е����λ��        
        first.y=1;        
        int dirIndex=0;        
        int num=1;        
        m[1][1]=1;        
        while(num<n*n)        
        {            
            second.x=first.x+DIR[dirIndex].x;            
            second.y=first.y+DIR[dirIndex].y;            
            if(m[second.x][second.y]==0) //�ж���һ��λ���Ƿ��е���            
            {                
                m[second.x][second.y]=++num; //���˵��⣬���������ּ�1                
                first=second;   //��secondΪ��ǰλ�ã�������            
            }            
            else                
            dirIndex=(dirIndex+1)%4; //����һ�����򣬰��������ϵ�˳������Ե���        
        }   
    }   
int main()    
{        
    int n=0;        
    cout<<"���������1С�ڵ���20������n:"<<endl;        
    cin>>n;        
    while(n<1||n>20)        
    {          
        cout<<"���������1С�ڵ���20������n:"<<endl;          
        cin>>n;        
    }        
    Init(n);        
    Print(0, n+1);        
    Solve(n);        
    Print(1, n);        
    return 0;    
}

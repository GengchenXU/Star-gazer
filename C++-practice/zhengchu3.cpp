#include <iostream>
using namespace std;

int main()
{
    int tmp;
    
    while(cin>>tmp)
    {
        int k = (tmp%3 == 0) + (tmp%5 == 0)*2 +(tmp%7 == 0)*4;
        switch(k)
        {
        case 0: cout<<"n"<<endl;break;
        case 1: cout<<"3"<<endl;break;
        case 2: cout<<"5"<<endl;break;
        case 3: cout<<"3 5"<<endl;break;
        case 4: cout<<"7"<<endl;break;
        case 5: cout<<"3 7"<<endl;break;
        case 6: cout<<"5 7"<<endl;break;
        case 7: cout<<"3 5 7"<<endl;
        }
        cout<<"";
    }   
    return 0;
}


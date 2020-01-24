#include<iostream>
#include<string>
using namespace std;
int main(){
    char s[80]; int  a=0,b=0,c=0,d=0,e=0;
    cin.getline(s,80);
       for(int i=0;i<80;++i){
        switch(s[i]){
            case '\0':
                break;
            case 'a' :
                ++a;break;
            case 'e' :
                ++b;break;
            case 'i' :
                ++c;break;
            case 'o':
                ++d;break;
            case 'u':
                ++e;break;
       }
}

    cout << a << " "<<b <<" "<<c<<" " <<d<<" "<<e<<endl;
    return 0;

}


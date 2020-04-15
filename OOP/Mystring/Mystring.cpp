#include <cstdlib>
#include <iostream>
using namespace std;
int strlen(const char * s) 
{    int i = 0;
    for(; s[i]; ++i);
    return i;
}
void strcpy(char * d,const char * s)
{
    int i = 0;
    for( i = 0; s[i]; ++i)
        d[i] = s[i];
    d[i] = 0;

}
int strcmp(const char * s1,const char * s2)
{
    for(int i = 0; s1[i] && s2[i] ; ++i) {
        if( s1[i] < s2[i] )
            return -1;
        else if( s1[i] > s2[i])
            return 1;
    }
    return 0;
}
void strcat(char * d,const char * s)
{
    int len = strlen(d);
    strcpy(d+len,s);
}
class MyString
{
// 在此处补充你的代码
private:
    char* p;
    int len;
public:
    MyString(const char* a){//有参构造
        len=strlen(a);
        p=new char[len+1];
        strcpy(p,a);
    }    
    MyString(){//无参构造
        len=1;
        p=new char[1];
        strcpy(p,"");
    }
    MyString(const MyString& a){//复制构造
        len=strlen(a.p);
        p=new char[len+1];
        strcpy(p,a.p);
    }
    friend ostream& operator<<(ostream& o,const MyString& a){//重载流输出
    o<<a.p;
    return o;
    }
    MyString& operator=(const MyString& a){//重载等号
        if(p==a.p){
            return *this;
        }
        if(p)
            delete p;
        len=strlen(a.p);
        p=new char[len+1];
        strcpy(p,a.p);
        return *this;
    }
    char& operator[](int i){
        return p[i];
    }
    friend MyString operator+(const MyString& a,const MyString& b){
        int l=b.len+a.len;
        char *c=new char[l+1];
        strcpy(c,a.p);
        int i ;
        int j=0;
    for( i = a.len; i<=l-1; ++i,++j)
        c[i]=b.p[j];
    c[i] = 0;
    return MyString(c);
    }
    void operator +=(const char *a){
        int i=len;
        char *b=new char[len+1];
        strcpy(b,p);
        delete p;
        len=len+strlen(a);
        p=new char[len+1];
        strcpy(p,b);
        int j=0;
        for(;i<=len-1;i++,j++){
            p[i]=a[j];
        }
        p[i]=0;
    }
    friend bool operator<(const MyString& a,const MyString& b){//重载CompareString中的大于等于
        if(strcmp(b.p,a.p)==1){
            return 1;
        }
        return 0;
    }
    friend bool operator>(const MyString& a,const MyString& b){
        if(strcmp(a.p,b.p)==1){
            return 1;
        }
        return 0;
    }
    friend bool operator==(const MyString& a,const MyString& b){
        if(strcmp(a.p,b.p)==0){
            return 1;
        }
        return 0;
    }    
    char* operator()(int a,int l){
        char* c=new char[l+1];
        int j=0;
        for(int i=a;i<a+l;i++,j++){
            c[j]=p[i];
        }
        c[j]=0;
        return c;
    }
};


int CompareString( const void * e1, const void * e2)
{
    MyString * s1 = (MyString * ) e1;
    MyString * s2 = (MyString * ) e2;
    if( * s1 < *s2 )
    return -1;
    else if( *s1 == *s2)
    return 0;
    else if( *s1 > *s2 )
    return 1;
}
int main()
{
    MyString s1("abcd-"),s2,s3("efgh-"),s4(s1);
    MyString SArray[4] = {"big","me","about","take"};
    cout << "1. " << s1 << s2 << s3<< s4<< endl;
    s4 = s3;
    s3 = s1 + s3;
    cout << "2. " << s1 << endl;
    cout << "3. " << s2 << endl;
    cout << "4. " << s3 << endl;
    cout << "5. " << s4 << endl;
    cout << "6. " << s1[2] << endl;
    s2 = s1;
    s1 = "ijkl-";
    s1[2] = 'A' ;
    cout << "7. " << s2 << endl;
    cout << "8. " << s1 << endl;
    s1 += "mnop";
    cout << "9. " << s1 << endl;
    s4 = "qrst-" + s2;
    cout << "10. " << s4 << endl;
    s1 = s2 + s4 + " uvw " + "xyz";
    cout << "11. " << s1 << endl;
    qsort(SArray,4,sizeof(MyString),CompareString);
    for( int i = 0;i < 4;i ++ )
    cout << SArray[i] << endl;
    //s1的从下标0开始长度为4的子串
    cout << s1(0,4) << endl;
    //s1的从下标5开始长度为10的子串
    cout << s1(5,10) << endl;
    return 0;
}
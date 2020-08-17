/*
 * @Description: 
 * @Sample Intput: 
 * @Output: 
 * @Author: GengchenXu
 * @CreateDate: 
 * @LastEditTime: 2020-08-17 20:08:06
 */

#include<iostream>
#include<stdlib.h>
#include<math.h>
#define pi 3.1415926535
using namespace std;
class CShape{
public:
    virtual double Area ()=0;//纯虚函数
    virtual void PrintInfo ()=0;
};
class CRectangle:public CShape{
public:
    int w,h;
    virtual double Area();
    virtual void PrintInfo();
};
class CCircle:public CShape {
public:
    int r; 
    virtual double Area();
    virtual void PrintInfo();
};
class CTriangle :public CShape {
public: 
    int a,b,c;
    virtual double Area(); 
    virtual void PrintInfo();
};
class CHexagonal:public CShape {
public:
    int w;
    virtual double Area();
    virtual void PrintInfo();
};
double CRectangle::Area(){
    return w*h;
}
void CRectangle:: PrintInfo(){
    cout<<"Rectangle:"<<Area()<<endl;
};
double CCircle:: Area(){
    return pi*r*r;
} 
void CCircle:: PrintInfo(){
    cout<<"Circle:"<<Area()<<endl;
}
double CTriangle:: Area(){
    double p=(a +b+c)/2.0; 
    return sqrt(p*(p-a)*(p-b)*(p-c));
}
void CTriangle::PrintInfo(){
    cout<<"Triangle:"<<Area()<<endl; 
    CShape * pShapes[100]; 
}
double CHexagonal::Area(){
    CTriangle*ct=new CTriangle;
    ct->a=w;
    ct->b=w;
    ct->c=w;
    double p=(ct->Area())*6;
    delete ct;
    return p;
}
void CHexagonal::PrintInfo(){
    cout<<"Hexagonal:"<<Area()<<endl;
}
CShape * pShapes[100];
int MyCompare(const void *s1, const void * s2); 
int main(){
    int i;
    int n; 
    CRectangle * pr;
    CCircle * pc;
    CTriangle * pt;
    CHexagonal * ph;
    cin>>n; 
    for(i=0;i<n;i++){
        char c;
        cin >>c;
        switch (c){
            case 'R':
            pr=new CRectangle;
            cin>>pr->w>>pr->h; 
            pShapes[i]=pr; 
            break; 
            case 'C': 
            pc=new CCircle;
            cin>>pc->r; 
            pShapes[i]=pc;
            break; 
            case 'T': 
            pt=new CTriangle;
            cin >>pt->a >>pt->b>>pt->c; 
            pShapes[i]=pt; 
            break;
            case 'H':
            ph=new CHexagonal;
            cin>> ph->w;
            pShapes[i]=ph;
            break;
        }
    }
    qsort(pShapes,n, sizeof(CShape*),MyCompare); 
    for(i=0;i<n;i++)//按面积大小输出
        pShapes[i]->PrintInfo();
    return 0;
}
int MyCompare(const void*s1,const void*s2){
    double a1,a2;
    CShape**p1;//s1，s2是void*，不可写“*s1”来取得s1指向的内容
    CShape**p2;
    p1=(CShape**)s1;//s1，s2指向pShapes数组中的元素，数组元素的类型是CShape*
    p2=(CShape**)s2;//故pl，p2都是指向指针的指针，类型为CShape**
    a1=(*p1)->Area();//*p1的类型是Cshape*，是基类指针，故此句为多态
    a2=(*p2)->Area();
    if(a1<a2)
        return -1;
    else if(a2<a1)
        return 1;
    else
        return 0;
}
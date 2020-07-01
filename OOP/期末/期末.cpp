/*
 * @Description: 
 * @Sample Intput: 
 * @Output: 
 * @Autor: GengchenXu
 * @Date: 2020-06-23 22:10:07
 * @LastEditTime: 2020-06-25 23:47:56
 */ 
#include <iostream>
using namespace std;

class CShape{
public:
    virtual double Getperimeter()const=0;
    virtual void Setperimeter()=0;
};

class CTriangle:public CShape{
private:
    double a,b,c;
public:
    double Getperimeter()const{
        return a+b+c;
    }
    void Setperimeter(){
        cout<<"CTriangle.a:";cin>>this->a;
        cout<<"CTriangle.b:";cin>>this->b;
        cout<<"CTriangle.c:";cin>>this->c;
    }
    bool operator>(const CShape& CBase){
        return this->Getperimeter() > CBase.Getperimeter();
    }
};
class CRect:public CShape{
private:
    double length;
    double width;
public:
    double Getperimeter()const{
        return 2*(width+length);
    }
    void Setperimeter(){
        cout<<"CRect.length:";cin>>this->length;
        cout<<"CRect.width:";cin>>this->width;
    }
    bool operator>(const CShape& CBase){
        return this->Getperimeter() > CBase.Getperimeter();
    }

};

class CCircle:public CShape{
private:
    double radius;
public:
    double Getperimeter()const{
        return 2*3.141592654 * radius ;
    }
    void Setperimeter(){
        cout<<"CCircle.radius:";cin>>this->radius;
    }
    bool operator>(const CShape& CBase){
        return this->Getperimeter() > CBase.Getperimeter();
    }

};

int main(){
    CTriangle ct;
    ct.Setperimeter();
    cout<<"CTriangle周长:"<<ct.Getperimeter()<<endl<<endl;

    CRect cr;
    cr.Setperimeter();
    cout<<"CRect周长:"<<cr.Getperimeter()<<endl<<endl;

    CCircle cc;
    cc.Setperimeter();
    cout<<"CCircle周长:"<<cc.Getperimeter()<<endl<<endl;

    if(ct > cr && ct > cc)
        cout<<"CTriangle周长最大"<<endl;
    else if(cr > ct && cr > cc)
        cout<<"CRect周长最大"<<endl;
    else if(cc > ct && cc > cr)
        cout<<"CCircle周长最大"<<endl;
    else
        cout<<"最大值不唯一"<<endl;
return 0;
}


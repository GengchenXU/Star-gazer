/*
 * @Description: 
 * @Autor: GengchenXu
 * @Date: 2020-04-21 15:03:03
 * @LastEditTime: 2020-04-22 23:27:07
 */
#include<iostream>
#include<cstdio>
#include<cmath>//sqrt头文件
#include<cstdlib>//qsort头文件
#include<algorithm>//sort头文件
#define PI 3.1415926535
using namespace std;

class Shape
{
public:
    virtual double Area()=0;//纯虚函数
    virtual void Print()=0;//纯虚函数
};
class Rectangle:public Shape
{
public:
    double length,width;
public:
    virtual double Area();
    virtual void Print();
};
double Rectangle::Area()
{
    return length*width;
}
void Rectangle::Print()
{
    printf("Rectangle:%.2f\n",Area());
}

class Triangle:public Shape
{
public:
    double a,b,c;
public:
    virtual double Area();
    virtual void Print();
};
double Triangle::Area()
{
    double p=(a+b+c)/2;
    return sqrt(p*(p-a)*(p-b)*(p-c));//海伦公式求三角形面积
}
void Triangle::Print()
{
    printf("Triangle:%.2f\n",Area());
}
class Circle:public Shape
{
public:
    double random;
public:
    virtual double Area();
    virtual void Print();
};
double Circle::Area()
{
    return PI*random*random;
}
void Circle::Print()
{
    printf("Circle:%.2f\n",Area());
}

int compare(const void *s1,const void *s2)//自定义比较函数
{
    double a1;
    double a2;
    Shape **p1,**p2;
    p1=(Shape**)s1;
    p2=(Shape**)s2;
    a1=(*p1)->Area();
    a2=(*p2)->Area();

    if(a1<a2)
        return -1;
    else if(a1>a2)
        return 1;
    else
        return 0;
}
bool cmp(Shape *a,Shape *b)
{
    return a->Area()>b->Area();
}//sort函数排序规则；

int main()
{
    Shape *p_shape[100];
    Rectangle *p_r;
    Triangle *p_t;
    Circle *p_c;

    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        getchar();
        char c;
        cin>>c;

        switch(c)
        {
        case 'R':
            p_r=new Rectangle();
            cin>>p_r->length>>p_r->width;
            p_shape[i]=p_r;
            break;
        case 'T':
            p_t=new Triangle();
            cin>>p_t->a>>p_t->b>>p_t->c;
            p_shape[i]=p_t;
            break;
        case 'C':
            p_c=new Circle();
            cin>>p_c->random;
            p_shape[i]=p_c;
            break;
        }
    }
    cout<<"accomplish\n";
    qsort(p_shape,n,sizeof(Shape *),compare);
    for(int i=0;i<n;i++)
        p_shape[i]->Print();
    sort(p_shape,p_shape+n,cmp);
    for(int i=0;i<n;i++)
        p_shape[i]->Print();
    for(int i=0;i<n;i++)
        delete p_shape[i];
    return 0;
}

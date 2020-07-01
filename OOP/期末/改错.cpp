/*
 * @Description: 
 * @Sample Intput: 
 * @Output: 
 * @Autor: GengchenXu
 * @Date: 2020-06-30 11:36:41
 * @LastEditTime: 2020-06-30 20:29:54
 */ 
/*
 * @Description: #include <iostream>
using namespace std;
class Product{
private:
float price;
public:
void Product(float p){price=p;}
Float getPrice(){return price;}
}
class Foods:public Product{ //Derived from class Product
private:
int storeTime;
public:
Foods(float p,int s) {storeTime=s;}
void display(){cout<<price<<storeTime<<endl;}
}；
int main()
{
Product p(3.1);
Foods *pf,
Foods f(2.5, 3);
pf=&p;
cout<<p.price;
cout<<f.price;
return 0;
}

 * @Sample Intput: 
 * @Output: 
 * @Autor: GengchenXu
 * @Date: 2020-06-30 11:36:41
 * @LastEditTime: 2020-06-30 20:28:36
 */ 
#include <iostream>
using namespace std;
class Product{
public:
float price;
public:
    Product(float p);
    float getPrice(){return price;}
};
Product::Product(float p):price(p){}
class Foods:public Product{ //Derived from class Product
private:
int storeTime;
public:
Foods(float p,int s) ;
void display(){cout<<price<<storeTime<<endl;}
};
Foods::Foods(float p,int s):Product(p),storeTime(s){}
int main(){
    Product p(3.1);
    Foods *pf;
    Foods f(2.5, 3);
    pf=&f;
    cout<<p.price<<endl;
    cout<<f.price;
    pf->display();
    return 0;
}

/*
 * @Description: 
 * @Autor: GengchenXu
 * @Date: 2020-04-14 15:08:37
 * @LastEditTime: 2020-04-17 22:11:36
 */
#include<cstring>
#include<iostream>
#include<iomanip>
using namespace std;
class base
{
private:
    int blood, productable[5], end, ord[5], step, num[5],sum;
    string name;
    static int life[5], time;
    static string monname[5];
public:
    base(int a, int b, int c, int d, int e, int f, const char* g) ;
    static void set();
    static void grow(base a, base b);
    void product();
};
int base::life[5] = {1,1,1,1,1};
int base::time = 0;
string base::monname[5] = {"dragon", "ninja", "iceman", "lion", "wolf"};
base::base(int a, int b, int c, int d, int e, int f, const char* g ){
    blood = f;
    sum = 0;
    step = 0;
    name = g;
    for(int i = 0; i < 5; i++) num[i] = 0;
    ord[0] = a;ord[1] = b;ord[2] = c;ord[3] = d;ord[4] = e;
    memset(productable, 0, sizeof(productable));
    end = 0;
}
void base::set(){
    for(int i = 0; i < 5; i++)
        cin >>life[i];
    time = 0;
}
void base::product(){
    if(end) return;
    if(productable[0] + productable[1] + productable[2] + productable[3] + productable[4] == 5){
        cout << setw(3) << setfill('0') << time <<" " << name << " headquarter stops making warriors" << endl;
        end = 1;
    }
    if(!productable[ord[step]] && blood >= life[ord[step]]){//当productable[]=1是证明生命值不够
        num[ord[step]]++;
        sum++;
        cout << setw(3) << setfill('0') << time << " "<< name <<" " << monname[ord[step]] << " " << sum << " born with strength"<< " "<< life[ord[step]]<< "," 
        << num[ord[step]] << " " << monname[ord[step]] << " in " << name << " headquarter"<<  endl;
        blood -= life[ord[step]];
    }
    else{//如果不够跳到下一个
        productable[ord[step]] = 1;
        step = (step + 1) % 5;
        product();
    }
    step=(step + 1) % 5;//五个魔兽一循环
}
void base::grow(base a, base b){
    while(1){
        a.product();
        b.product();
        time++;
        if(a.end + b.end == 2) break;
    }
}
int main(){
    int n = 0;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cout << "Case:" << i << endl;
        int tep = 0;
        cin >> tep;
        base red(2, 3, 4, 1, 0, tep, "red"), blue(3, 0, 1, 2, 4, tep, "blue");//出战顺序和生命值
        base::set();
        base::grow(blue, red);
    }
    return 0;
}
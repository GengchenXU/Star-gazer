/*
 * @Description: dragon 可以拥有一件武器。编号为n的dragon降生时即获得编号为 n%3 的武器。dragon还有“士气”这个属性，是个浮点数，其值为它降生后其司令部剩余生命元的数量除以造dragon所需的生命元数量。
ninjia可以拥有两件武器。编号为n的ninjia降生时即获得编号为 n%3 和 (n+1)%3的武器。
iceman有一件武器。编号为n的iceman降生时即获得编号为 n%3 的武器。
lion 有“忠诚度”这个属性，其值等于它降生后其司令部剩余生命元的数目。
wolf没特点。
 * @Output: Case:1
000 red iceman 1 born with strength 5,1 iceman in red headquarter
It has a bomb
000 blue lion 1 born with strength 6,1 lion in blue headquarter
It's loyalty is 14
001 red lion 2 born with strength 6,1 lion in red headquarter
It's loyalty is 9
001 blue dragon 2 born with strength 3,1 dragon in blue headquarter
It has a arrow,and it's morale is 3.67
002 red wolf 3 born with strength 7,1 wolf in red headquarter
002 blue ninja 3 born with strength 4,1 ninja in blue headquarter
It has a sword and a bomb
003 red headquarter stops making warriors
003 blue iceman 4 born with strength 5,1 iceman in blue headquarter
It has a bomb
004 blue headquarter stops making warriors
 * @Autor: GengchenXu
 * @Date: 2020-04-30 23:30:21
 * @LastEditTime: 2020-05-01 00:02:58
 */

#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;
int lifetomake[5] = {0};
const string weapon[3] = {"sword", "bomb","arrow"};
int t = 0;
const string monname[5] = {"dragon", "ninja", "iceman", "lion", "wolf"};

class monster
{
public:
    int id, life;
    string belong;//阵营
    monster(int x, int y, string s){
        id = x;
        life = y;
        belong=s;
    }
};

class dragon:public monster
{
    int equipment;
    double courage;
public:
    dragon(int m_, int id_, int life_,int num_, const string s): monster(id_, life_, s){
        equipment = id % 3;
        courage = double(m_)/double(lifetomake[0]);
        cout << setw(3) << setfill('0') <<t<<" " <<belong <<" " << monname[0]<<" " << id<<" born with strength " << life <<",";
        cout << num_ <<" " << monname[0] << " in " << belong <<" headquarter" << endl;
        cout << "It has a " << weapon[equipment] <<",and it's morale is " <<fixed<<setprecision(2)<< courage <<endl;
    }
};
class ninjia:public monster{
    int equipment1, equipment2;
public:
    ninjia(int m_, int id_, int life_,int num_,  const string s):monster(id_,life_,s){
        equipment1 = id % 3;
        equipment2 = (id + 1) % 3;
        cout  << setw(3) << setfill('0') <<  t<<" " <<belong <<" " << monname[1] << " " << id<<" born with strength " << life <<",";
        cout << num_ <<" " << monname[1] << " in " << belong <<" headquarter" << endl;
        cout << "It has a " << weapon[equipment1] <<" and a " << weapon[equipment2]<<endl;
    }
};

class iceman:public monster{
    int equipment;
public:
    iceman(int m_, int id_, int life_, int num_, const string s):monster(id_,life_,s){
        equipment = id % 3;
        cout  << setw(3) << setfill('0') <<  t<<" " <<belong <<" " << monname[2] <<" " << id<<" born with strength " << life <<",";
        cout << num_<<" "  << monname[2] << " in " << belong <<" headquarter" << endl;
        cout << "It has a " << weapon[equipment]<<endl;
    }
};
class lion:public monster{
    int loyalty;
public:
    lion(int m_,int id_,int life_, int num_, const string s):monster(id_, life_, s){
        loyalty = m_;
        cout  << setw(3) << setfill('0') <<  t<<" " <<belong <<" " << monname[3] << " " << id<<" born with strength " << life <<",";
        cout << num_<<" "  << monname[3] << " in " << belong <<" headquarter" << endl;
        cout << "It's loyalty is " << loyalty <<endl;
    }
};
class wolf:public monster{
public:
    wolf(int m_, int id_, int life_, int num_, const string s):monster(id_, life_, s){
        cout  << setw(3) << setfill('0') << t<<" " <<belong <<" " << monname[4]<<" "<< id<<" born with strength " << life <<",";
        cout << num_<<" " << monname[4] << " in " << belong <<" headquarter" << endl;
    }
};

class base{
private:
    int m, productable[5], end, ord[5], step, num[5],sum;
    string name;
    monster* p[100];
    friend class monster;
public:
    base(int, int, int, int, int, int, const char*);
    void product();
    static void grow(base, base);
    void setname();
    void mon_product(int , int);
};

base::base(int a, int b, int c, int d, int e, int f, const char* g ){
    m = f;
    sum = 0;
    step = 0;
    name=g;
    for(int i = 0; i < 5; i++) num[i] = 0;
    ord[0] = a;
    ord[1] = b;
    ord[2] = c;
    ord[3] = d;
    ord[4] = e;
    memset(productable, 0, sizeof(productable));
    end = 0;
}

void base::mon_product(int x, int y){
    switch(x)
    {
    case 0:
        p[y] = new dragon(m, sum, lifetomake[0],num[0], name);
        break;
    case 1:
        p[y] = new ninjia(m,sum,lifetomake[1],num[1], name);
        break;
    case 2:
        p[y] = new iceman(m,sum,lifetomake[2],num[2],name);
        break;
    case 3:
        p[y] = new lion(m,sum,lifetomake[3],num[3],name);
        break;
    case 4:
        p[y] = new wolf(m,sum,lifetomake[4],num[4],name);
        break;
    default:
        break;
    }
    return;
}
void base::product(){
    if(end) return;
    if(productable[0] + productable[1] + productable[2] + productable[3] + productable[4] == 5){
        cout << setw(3) << setfill('0') << t <<" " << name << " headquarter stops making warriors" << endl;
        end = 1;
    }
    if(!productable[ord[step]] && m >= lifetomake[ord[step]]){
        num[ord[step]]++;
        m -= lifetomake[ord[step]];
        sum++;
        mon_product(ord[step], sum);
    }
    else{
        productable[ord[step]] = 1;
        step = (step + 1) % 5;
        product();
    }
}

void base::grow(base a, base b){
    while(1){
        a.product();
        a.step = (a.step + 1) % 5;
        b.product();
        b.step = (b.step + 1) % 5;
        t++;
        if(a.end + b.end == 2) break;
    }
}

int main(){
    int n = 0;
    cin >> n;
    for(int i = 1; i <= n; i++){
        t = 0;
        cout << "Case:" << i << endl;
        int tep = 0;
        cin >> tep;
        for(int j = 0; j < 5; j++)
            cin >> lifetomake[j];
        base red(2, 3, 4, 1, 0, tep, "red"), blue(3, 0, 1, 2, 4, tep, "blue");
        base::grow(red, blue);
    }
    return 0;
}
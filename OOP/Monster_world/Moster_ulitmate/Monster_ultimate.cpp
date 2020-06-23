/*
 * @Description: 
 * @Autor: GengchenXu
 * @Date: 2020-06-12 15:08:37
 * @LastEditTime: 2020-06-16 22:28:49
 */
#include <iostream>
#include <cstdio>
#include <algorithm>
//#include <stdlib.h>
#include <string>
#include <memory.h>
#include <map>

using namespace std;

//定义各种变量
int M, N, R, K, T;//每个司令部的初始生命元数量,城市数量，arrow攻击力，忠诚衰减量，截止时间量
map<string, int> hp;//生命值
map<string,int>atk;//攻击力
int hour, minute,_hour,_minute;
int arrowwin[25],endflag,headtaken[2];
class warrior*(cities[25][2]);
int flag[25];
string headname[2] = { "red","blue" };
string warriorcreateline[2][5] = { { "iceman", "lion", "wolf", "ninja", "dragon" },
{ "lion", "dragon", "ninja", "iceman", "wolf" }, };
string weaponname[3] = { "sword","bomb","arrow" };
int winner[25],givereward[25];
int firstflag[25];
warrior *redreached, *bluereached;


//武器
class weapon {
public:
    int atk;
    weapon(int type, int _atk) {
        if (type == 0)atk = _atk * 2 / 10;//攻击力的 %20
        if (type == 1)atk = 10000;//极大的数
        if (type == 2)atk = 3;//3次
    }
};

//司令部
class base
{
public:
    string type;
    int warriors;
    int locat;//所处地
    int source;//生命元
    int id;
    base(){}
    base(string _type) :type(_type){
        if (type == "red") { locat = 0; id = 0; }
        else { locat = N + 1; id = 1; }
        source = M;
        warriors = 0;
    }
};

base head[2];//head[0]红 head[1]蓝

//武士
class warrior {
public:
    int str;//生命值
    int id;//编号
    string type;//种类
    weapon*weapons[3];
    int force;//战力
    int step;
    string mast;//司令部
    int loyalty;//忠诚值
    double morale;//士气
    string namae() {
        return mast + " " + type + " " + to_string(id);
    }
    warrior(string _mast, int _id, string _type,double headsource) :mast(_mast), id(_id), type(_type){
        step = 0; loyalty = 0; morale = 0;
        str = hp[type]; force = atk[type];
        for (int i = 0; i < 3; i++)
        {
            weapons[i] = NULL;
        }
        weapon* w1 = new weapon(id % 3, force);
        weapon* w2 = new weapon((id + 1) % 3, force);
        if (!(w1->atk))
            w1 = NULL;
        if (!(w2->atk))
            w2 = NULL;
        if (type == "dragon")
        {
            weapons[id % 3] = w1;
            morale = headsource / (double)hp[type];
        }
        else if(type=="ninja")
        {
            weapons[id % 3] = w1;
            weapons[(id + 1) % 3] = w2;
        }
        else if (type == "lion")
            loyalty = headsource;
        else if (type == "iceman")
            weapons[id % 3] = w1;
    }
    int sumatk(int defense) {
        if (defense)return force / 2 + usesword(0);
        return force + usesword(0);
    }
    int usesword(int mode) {
        if (weapons[0]) {
            if (!mode)return weapons[0]->atk;
            else {
                weapons[0]->atk = weapons[0]->atk * 8 / 10;
                if (weapons[0]->atk == 0)
                    weapons[0] = NULL;
                return 0;
            }
        }
        else
            return 0;
    }
    void rob(warrior*loser) {//wolf抢武器
        for (int i = 0; i < 3; i++) {
            if (!weapons[i])//没有才抢
                weapons[i] = loser->weapons[i];
        }
    }
    string outweapon() {//武士报告武器情况
        bool pt[3];
        int sum=0;
        for (int i = 0; i < 3; i++)
        {
            pt[i] = weapons[i];
            sum += pt[i];
        }
        string all="";
        int count = 0;
        for (int i = 2; i >=0; i--)
        {
            if (weapons[i])
            {
                count++;
                all += weaponname[i];
                if(weaponname[i]!="bomb")
                    all += "(" + to_string(weapons[i]->atk) + ")";//000:55 blue wolf 2 has arrow(2),bomb,sword(23)
                if (count != sum)
                    all += ",";
            }
        }
        return all;
    }
};

//城市
class city {
public:
    int soldier_n;
    int wintime[2];
    int source;
}allcity[25];

//初始化
void clear() {
    endflag = 0;
    hour = 0; minute = 0;
    _hour = T / 60, _minute = T % 60;
    head[0] = base("red");
    head[1] = base("blue");
    for (int i = 0; i <= N + 1; i++)
    {
        cities[i][0] = NULL; cities[i][1] = NULL;
        allcity[i].soldier_n = 0; allcity[i].wintime[0] = allcity[i].wintime[1] = 0;
        if (!(i % 2))flag[i] = 1;
        else flag[i] = 0;
        allcity[i].source = 0;
        allcity[i].wintime[0] = 0;
        allcity[i].wintime[1] = 0;
    }
    memset(firstflag, 0, sizeof(int) * 25);
    memset(winner, 0, sizeof(int) * 25);
    memset(givereward, 0, sizeof(int) * 25);
    memset(arrowwin, 0, sizeof(int) * 25);
    bluereached = NULL, redreached = NULL;
    headtaken[0] = 0;
    headtaken[1] = 0;
}

//输入
void init() {
    cin >> M >> N >>R>> K >> T;
    cin >> hp["dragon"] >> hp["ninja"] >> hp["iceman"] >> hp["lion"] >> hp["wolf"];
    cin >> atk["dragon"] >> atk["ninja"] >> atk["iceman"] >> atk["lion"] >> atk["wolf"];
}

//制造武士
void createwarriors() {
    for (int i = 0; i <= 1; i++) {
        string wtype = warriorcreateline[i][(head[i].warriors % 5)];
        if (hp[wtype] <= head[i].source)//如果己方阵营生命元大于才能制造
        {
            head[i].warriors++;
            head[i].source -= hp[wtype];
            warrior*newone = new warrior(headname[i], head[i].warriors, wtype, head[i].source);
            cities[head[i].locat][head[i].id] = newone;
            printf("%03d:00 %s %s %d born\n", hour,head[i].type.c_str(), wtype.c_str(),newone->id);
            if (wtype == "dragon")printf("Its morale is %.2lf\n", newone->morale);
            if (wtype == "lion")printf("Its loyalty is %d\n", newone->loyalty);
        }
    }
}

//lion逃跑
void lionsescape() {
    for (int i = 0; i <= N + 1; i++) {
        for (int j = 0; j < 2; j++) {
            if (cities[i][j] && cities[i][j]->type == "lion"&&cities[i][j]->loyalty <= 0) {
                printf("%03d:05 %s ran away\n", hour, cities[i][j]->namae().c_str());
                cities[i][j] = NULL;
            }
        }
    }
}

//行军
void marching() {
    warrior*tmp[25][2];
    for (int i = 0; i <= N + 1; i++)
    {
        tmp[i][0] = cities[i][0];
        tmp[i][1] = cities[i][1];
    }
    for (int i = 0; i <= N + 1; i++) {
        cities[i][0] = cities[i][1] = NULL;
    }
    for (int i = 0; i <= N + 1; i++) {
        if (tmp[i][0]) {
            cities[i + 1][0] = tmp[i][0]; tmp[i][0]->step++;
            if (tmp[i][0]->type == "iceman"&&tmp[i][0]->step % 2 == 0) {
                tmp[i][0]->force += 20; tmp[i][0]->str -= 9;
                if (tmp[i][0]->str <= 0)tmp[i][0]->str = 1;
            }
        }
        if (tmp[i][1]) {
            cities[i - 1][1] = tmp[i][1]; tmp[i][1]->step++;
            if (tmp[i][1]->type == "iceman"&&tmp[i][1]->step % 2 == 0) {
                tmp[i][1]->force += 20; tmp[i][1]->str -= 9;
                if (tmp[i][1]->str <= 0)tmp[i][1]->str = 1;
            }
        }
    }
    for (int i = 0; i <= N + 1; i++) {
        for (int j = 0; j < 2; j++) {
            if (cities[i][j])
            {
                if (i == 0)
                {
                    printf("%03d:10 %s reached red headquarter with %d elements and force %d\n",
                        hour, cities[i][j]->namae().c_str(), cities[i][j]->str, cities[i][j]->force);
                    headtaken[0]++;
                    if (headtaken[0] == 2)
                    {
                        printf("%03d:10 red headquarter was taken\n", hour);
                        endflag = 1;
                    }
                    redreached = cities[i][j];
                }
                else if (i == N + 1) {
                    printf("%03d:10 %s reached blue headquarter with %d elements and force %d\n",
                        hour, cities[i][j]->namae().c_str(), cities[i][j]->str, cities[i][j]->force);
                    headtaken[1]++;
                    if (headtaken[1] == 2)
                    {
                        printf("%03d:10 blue headquarter was taken\n", hour);
                        endflag = 1;
                    }
                    bluereached = cities[i][j];
                }
                else printf("%03d:10 %s marched to city %d with %d elements and force %d\n",
                    hour, cities[i][j]->namae().c_str(),i, cities[i][j]->str, cities[i][j]->force);
            }
        }
    }
}

//产出生命元
void sourceproduce() {
    for (int i = 1; i <= N; i++)
        allcity[i].source += 10;
}

//取走生命元
void getsource() {
    for (int i = 1; i <= N; i++)
        for (int j = 0; j < 2; j++) {
            if(cities[i][j]&&!cities[i][j^1]&&allcity[i].source)
            {
                printf("%03d:30 %s earned %d elements for his headquarter\n", hour, cities[i][j]->namae().c_str(), allcity[i].source);
                head[j].source += allcity[i].source;
                allcity[i].source = 0;
            }
        }
}

//放箭
void arrowreleased() {
    for (int i = 1; i <= N; i++) {
        if (cities[i][0]&&cities[i+1][1]&&cities[i][0]->weapons[2]) {
            cities[i + 1][1]->str -= R ;
            cities[i][0]->weapons[2]->atk--;
            if (!cities[i][0]->weapons[2]->atk)
                cities[i][0]->weapons[2] = NULL;
            if (cities[i + 1][1]->str <= 0) {
                printf("%03d:35 %s shot and killed %s\n", hour, cities[i][0]->namae().c_str(), cities[i + 1][1]->namae().c_str());
                arrowwin[i + 1] = 1;
            }
            else printf("%03d:35 %s shot\n", hour,cities[i][0]->namae().c_str());
        }
        if (cities[i][1] && cities[i - 1][0] && cities[i][1]->weapons[2]) {
            cities[i - 1][0]->str -= R ;
            cities[i][1]->weapons[2]->atk--;
            if (!cities[i][1]->weapons[2]->atk)
                cities[i][1]->weapons[2] = NULL;
            if (cities[i - 1][0]->str <= 0) {
                printf("%03d:35 %s shot and killed %s\n", hour, cities[i][1]->namae().c_str(), cities[i - 1][0]->namae().c_str());
                arrowwin[i - 1] = 1;
            }
            else printf("%03d:35 %s shot\n", hour,cities[i][1]->namae().c_str());
        }
    }
}

//自爆
void bombused() {
    for(int i=1;i<=N;i++){
        int j = flag[i];
            if (cities[i][j] &&cities[i][j ^1] && cities[i][j]->str>0 && cities[i][j ^ 1]->str>0) {
                if (cities[i][j ^ 1]->type != "ninja"&&cities[i][j]->weapons[1]&&cities[i][j ^ 1]->str > cities[i][j]->sumatk(0) && (cities[i][j ^ 1]->sumatk(1)) >= (cities[i][j]->str)) {
                    printf("%03d:38 %s used a bomb and killed %s\n", hour, cities[i][j]->namae().c_str(), cities[i][j ^ 1]->namae().c_str());
                    cities[i][j] = cities[i][j ^ 1] = NULL;
                }
                else if (cities[i][j ^ 1]->weapons[1] && cities[i][j]->sumatk(0) >= cities[i][j ^ 1]->str) {
                    printf("%03d:38 %s used a bomb and killed %s\n", hour, cities[i][j^1]->namae().c_str(), cities[i][j]->namae().c_str());
                    cities[i][j] = cities[i][j ^ 1] = NULL;
                }
            }
        }
}

//判断胜负
void judge() {
    memset(givereward, 0, sizeof(int) * 25);
    for (int i = 1; i <= N; i++)
    {
        if (cities[i][0] && cities[i][1])
        {
            if (cities[i][flag[i]]->sumatk(0) >= cities[i][flag[i] ^ 1]->str)
                winner[i] = flag[i];
            else if (cities[i][flag[i] ^ 1]->type!="ninja"&&cities[i][flag[i] ^ 1]->sumatk(1) >= cities[i][flag[i]]->str)
                winner[i] = flag[i] ^ 1;
        }
        if (arrowwin[i])
        {
            for (int j = 0; j < 2; j++)
                if (cities[i][j])
                    winner[i] = j;
        }
    }
    int r_reward = head[0].source / 8, b_reward = head[1].source / 8;
    for (int i = 1; i <= N; i++)
    {
        if (winner[i] == 0)
        {
            if (r_reward)
            {
                givereward[i] = 1;
                r_reward--;
            }
        }
        if (winner[N + 1 - i] == 1)
        {
            if (b_reward)
            {
                givereward[i] = 1;
                b_reward--;
            }
        }
    }
}

//战斗
void battle() {
    judge();
    for (int i = 1; i <= N; i++) {
            if (arrowwin[i]) {
                for (int j = 0; j < 2; j++)
                {
                    if (cities[i][j] && cities[i][j ^ 1] && cities[i][j ^ 1]->str <= 0 && cities[i][j]->str <= 0)
                    {
                        cities[i][j] = NULL;
                        cities[i][j ^ 1] = NULL;
                    }
                    else if (cities[i][j] && cities[i][j ^ 1] && cities[i][j ^ 1]->str <= 0)
                    {
                        if (cities[i][j]->type == "wolf")
                            cities[i][j]->rob(cities[i][j ^ 1]);
                        cities[i][j ^ 1] = NULL;
                    }
                    else if (cities[i][j] && !cities[i][j ^ 1])
                        cities[i][j] = NULL;
                }
            }
        if (cities[i][0] && cities[i][1])
        {
            arrowwin[i] = 1;
            {
                int hp_atk = cities[i][flag[i]]->str, hp_rcp = cities[i][flag[i] ^ 1]->str;
                cities[i][flag[i] ^ 1]->str -= cities[i][flag[i]]->sumatk(0);
                cities[i][flag[i]]->usesword(1);
                printf("%03d:40 %s attacked %s in city %d with %d elements and force %d\n", hour,
                    cities[i][flag[i]]->namae().c_str(), cities[i][flag[i] ^ 1]->namae().c_str(), i, cities[i][flag[i]]->str, cities[i][flag[i]]->force);
                if (cities[i][flag[i] ^ 1]->str > 0&&cities[i][flag[i]^1]->type!="ninja") {
                    cities[i][flag[i]]->str -= cities[i][flag[i] ^ 1]->sumatk(1);
                    cities[i][flag[i] ^ 1]->usesword(1);
                    printf("%03d:40 %s fought back against %s in city %d\n", hour, cities[i][flag[i] ^ 1]->namae().c_str(), cities[i][flag[i]]->namae().c_str(), i);
                    if (cities[i][flag[i]]->str <= 0) {
                        printf("%03d:40 %s was killed in city %d\n", hour, cities[i][flag[i]]->namae().c_str(), i);
                        if (cities[i][flag[i]^1]->type == "wolf")
                            cities[i][flag[i]^1]->rob(cities[i][flag[i] ]);
                        if (cities[i][flag[i]]->type == "lion")
                            cities[i][flag[i] ^ 1]->str += hp_atk;
                        cities[i][flag[i]] = NULL;
                    }
                }
                else if (cities[i][flag[i] ^ 1]->str <= 0) {
                    printf("%03d:40 %s was killed in city %d\n", hour, cities[i][flag[i] ^ 1]->namae().c_str(),i);
                    if (cities[i][flag[i]]->type == "wolf")
                        cities[i][flag[i]]->rob(cities[i][flag[i] ^ 1]);
                    if (cities[i][flag[i] ^ 1]->type == "lion")
                        cities[i][flag[i]]->str += hp_rcp;
                    cities[i][flag[i] ^ 1] = NULL;
                }
            }
            if (cities[i][0] && cities[i][1])
            {
                allcity[i].wintime[0] = allcity[i].wintime[1]=0;
            }
        }
        if (arrowwin[i]) {
            for (int j = 0; j < 2; j++) {
                if (cities[i][j]) {
                    if (cities[i][j]->type == "dragon" && !cities[i][j ^ 1])
                        cities[i][j]->morale += 0.2;
                    if (cities[i][j]->type == "dragon" && cities[i][j ^ 1])
                        cities[i][j]->morale -= 0.2;
                    if (j == flag[i] && cities[i][j]->type == "dragon"&&cities[i][j]->morale>0.8)
                        printf("%03d:40 %s yelled in city %d\n", hour, cities[i][j]->namae().c_str(), i);
                    if (cities[i][j ^ 1] && cities[i][j]->type == "lion")
                        cities[i][j]->loyalty -= K;
                    if (!cities[i][j^1])
                    {
                        if (givereward)
                        {
                            cities[i][j]->str += 8;
                            head[j].source -= 8;
                        }
                        printf("%03d:40 %s earned %d elements for his headquarter\n",
                            hour, cities[i][j]->namae().c_str(), allcity[i].source);
                        head[j].source += allcity[i].source;
                        allcity[i].source = 0;
                        allcity[i].wintime[j]++;
                        allcity[i].wintime[j ^ 1] = 0;
                        if (allcity[i].wintime[j] == 2&&(flag[i]!=j||firstflag[i]==0))
                        {
                            firstflag[i] = 1;
                            flag[i] = j;
                            printf("%03d:40 %s flag raised in city %d\n", hour, head[j].type.c_str(), i);
                        }
                    }
                }
            }
        }
    }
}

//报告生命元数
void reportsource() {
    printf("%03d:%02d %d elements in red headquarter\n", hour, minute, head[0].source);
    printf("%03d:%02d %d elements in blue headquarter\n", hour, minute, head[1].source);
}

//武士报告
void reportwaror() {
    for (int i = 0; i <= N ; i++)
    {
        if (cities[i][0])
        {
            if (!cities[i][0]->weapons[0] && !cities[i][0]->weapons[1] && !cities[i][0]->weapons[2])
                printf("%03d:55 %s has no weapon\n", hour, cities[i][0]->namae().c_str());
            else
            {
                printf("%03d:55 %s has %s\n", hour, cities[i][0]->namae().c_str(), cities[i][0]->outweapon().c_str());
            }
        }
    }
    if (bluereached)
    {
        if (!bluereached->weapons[0] && !bluereached->weapons[1] && !bluereached->weapons[2])
            printf("%03d:55 %s has no weapon\n", hour, bluereached->namae().c_str());
        else
        {
            printf("%03d:55 %s has %s\n", hour, bluereached->namae().c_str(), bluereached->outweapon().c_str());
        }
    }
    if (redreached)
    {
        if (!redreached->weapons[0] && !redreached->weapons[1] && !redreached->weapons[2])
            printf("%03d:55 %s has no weapon\n", hour, redreached->namae().c_str());
        else
        {
            printf("%03d:55 %s has %s\n", hour, redreached->namae().c_str(), redreached->outweapon().c_str());
        }
    }
    for (int i = 1; i <= N + 1; i++)
    {
        if (cities[i][1])
        {
            if (!cities[i][1]->weapons[0] && !cities[i][1]->weapons[1] && !cities[i][1]->weapons[2])
                printf("%03d:55 %s has no weapon\n", hour, cities[i][1]->namae().c_str());
            else
            {
                printf("%03d:55 %s has %s\n", hour, cities[i][1]->namae().c_str(), cities[i][1]->outweapon().c_str());
            }
        }
    }
}

int main()
{
    int n;//case数
    cin >> n;
    for (int c = 1; c <= n; c++) {
        init();
        clear();
        printf("Case %d:\n", c);
        while (1) {
            //0min
            minute = 0;
            if (hour == _hour && minute > _minute)
                break;
            createwarriors();
            //5min
            minute = 5;
            if (hour == _hour && minute > _minute)
                break;
            lionsescape();
            //10min
            minute = 10;
            if (hour == _hour && minute > _minute)
                break;
            marching();
            if (endflag)
                break;
            //20min
            minute = 20;
            if (hour == _hour && minute > _minute)
                break;
            sourceproduce();
            //30min
            minute = 30;
            if (hour == _hour && minute > _minute)
                break;
            getsource();
            //35min
            minute = 35;
            if (hour == _hour && minute > _minute)
                break;
            arrowreleased();
            //38min
            minute = 38;
            if (hour == _hour && minute > _minute)
                break;
            bombused();
            //40min
            minute = 40;
            if (hour == _hour && minute > _minute)
                break;
            for (int i = 1; i <= N; i++)
                winner[i] = -1;
            battle();
            memset(arrowwin, 0, sizeof(int) * 25);
            //50min
            minute = 50;
            if (hour == _hour && minute > _minute)
                break;
            reportsource();
            //55min
            minute = 55;
            if (hour == _hour && minute > _minute)
                break;
            reportwaror();
            hour++;
        }
    }
    return 0;
}
/*
 * @Description: 
 * @Sample Intput: 
 * @Output: 
 * @Autor: GengchenXu
 * @Date: 2020-06-16 22:36:01
 * @LastEditTime: 2020-06-17 00:41:32
 */ 
#include<iostream>   
#include<cstring>   
#include<stdio.h>   
#include<string>   
#include<cmath>   
#include <map>
using namespace std;   
string Hour,minute;   
int M,N,K,R,T;   //每个司令部的初始生命元数量,城市数量，arrow攻击力，忠诚衰减量，截止时间量
bool stop=0;   
map<string, int> hp;//生命值
map<string,int>atk;//攻击力  
class warrior;   
void Changetime();   
void clear();   
void produce();;   
void escape();   
void Move();   
void lifeincrease();   
void catchlife();   
void arrow();   
void Bomb();   
void battle();   
void reportlife();   
void Myreport(); 
class Head   
{   
public:   
    int reachnum;   
    int life;   
    int numofwarrior;   
    string country;   
    warrior * pf[1000000];   
    Head(string _country):country(_country)   
    {   
        reachnum=0;   
        numofwarrior=0;   
    }   
}Redhead("red"),Bluehead("blue");   
class City   
{   
public:   
    int life;   
    int tlife;   
    string flag;   
    int num;   
    string t;   
    int fight;   
    warrior * pred,*pblue;   
    City()   
    {   
        tlife=0;   
        t="no";   
        flag="no";   
        pred=NULL;   
        pblue=NULL;   
        fight=0;   
    }   
}city[100];   
class warrior   
{   
public:   
    double morale;   //士气
    bool bdragon;   
    int sword;   
    int loyal;   //忠诚值
    int arrow;   
    bool blion;   
    string country;   
    bool bsword,barrow,bbomb;   
    int location;   
    int life;   
    int id;   
    int power;   
    virtual int nattack()   //主动攻击
    {   
        if(life==0) return 0;   
        if(bsword==1) return sword+power;   
        else return power;   
    }   
    virtual int n2attack()   //第二次攻击
    {   
        if(life==0) return 0;   
        if(sword==0) return power/2;   
        else return power/2+sword;   
    }   
    virtual void Yale(){}   
    virtual void Bomb()   
    {   
        if(country=="red") {   
            if((city[location].flag=="red"||(location%2==1&&city[location].flag!="blue"))&&city[location].pblue!=NULL&&nattack()<city[location].pblue->life&&life<=city[location].pblue->n2attack()){   
                printf("%s:%s red %s %d used a bomb and killed blue %s %d\n",Hour.c_str(),minute.c_str(),name().c_str(),id,city[location].pblue->name().c_str(),city[location].pblue->id);   
                life=0;   
                city[location].pblue->life=city[location].pred->life=0;   
                city[location].pred=city[location].pblue=NULL;   
            }   
            else if((city[location].flag=="blue"||(location%2==0&&(city[location].flag!="red")))&&city[location].pblue!=NULL&&life<=city[location].pblue->nattack()){   
                printf("%s:%s red %s %d used a bomb and killed blue %s %d\n",Hour.c_str(),minute.c_str(),name().c_str(),id,city[location].pblue->name().c_str(),city[location].pblue->id);   
                life=0;   
                city[location].pblue->life=city[location].pred->life=0;   
                city[location].pred=NULL;   
                city[location].pblue=NULL;   
            }      
        }   
        else {   
            if((city[location].flag=="blue"||(location%2==0&&city[location].flag!="red"))&&city[location].pred!=NULL&&nattack()<city[location].pred->life&&life<=city[location].pred->n2attack()){   
                printf("%s:%s blue %s %d used a bomb and killed red %s %d\n",Hour.c_str(),minute.c_str(),name().c_str(),id,city[location].pred->name().c_str(),city[location].pred->id);   
                life=0;   
                city[location].pred->life=city[location].pblue->life=0;   
                city[location].pred=city[location].pblue=NULL;   
            }   
            else if((city[location].flag=="red"||(location%2==1&&city[location].flag!="blue"))&&city[location].pred!=NULL&&life<=city[location].pred->nattack()){   
                printf("%s:%s blue %s %d used a bomb and killed red %s %d\n",Hour.c_str(),minute.c_str(),name().c_str(),id,city[location].pred->name().c_str(),city[location].pred->id);   
                city[location].pblue->life=0;   
                city[location].pred->life=0;   
                city[location].pred=city[location].pblue=NULL;   
            }      
        }   
    }   
    virtual string name(){}   
    virtual void Arrow()   
    {   
        if(country=="red"&&city[location+1].pblue!=NULL){   
            if(city[location+1].pblue->life>R){   
                printf("%s:%s red %s %d shot\n",Hour.c_str(),minute.c_str(),name().c_str(),id);   
                city[location+1].pblue->life-=R;   
                arrow--;   
                if(arrow==0) barrow=0;   
            }   
        else {   
                printf("%s:%s red %s %d shot and killed blue %s %d\n",Hour.c_str(),minute.c_str(),name().c_str(),id,city[location+1].pblue->name().c_str(),city[location+1].pblue->id);   
                city[location+1].pblue->life=0;   
                arrow--;   
                if(arrow==0) barrow=0;   
            }   
        }   
        else if(country=="blue"&&city[location-1].pred!=NULL){   
            if(city[location-1].pred->life>R){   
                printf("%s:%s blue %s %d shot\n",Hour.c_str(),minute.c_str(),name().c_str(),id);   
                city[location-1].pred->life-=R;   
                arrow--;   
                if(arrow==0) barrow=0;   
            }   
        else {   
                printf("%s:%s blue %s %d shot and killed red %s %d\n",Hour.c_str(),minute.c_str(),name().c_str(),id,city[location-1].pred->name().c_str(),city[location-1].pred->id);   
                city[location-1].pred->life=0;   
                arrow--;   
                if(arrow==0) barrow=0;   
            }   
        }   
    }   
    virtual void Win()   
    {   
        if(bdragon==1){   
            morale+=0.2;   //dragon每取得一次战斗的胜利(敌人被杀死)，士气就会增加0.2，每经历一次未能获胜的战斗，士气值就会减少0.2。士气增减发生在欢呼之前。
            if(city[location].flag==country||(city[location].flag!="blue"&&location%2==1&&country=="red")||(city[location].flag!="red"&&location%2==0&&country=="blue"))   
                Yale();   
        }   
        if(country=="red"){   
            printf("%s:%s red %s %d earned %d elements for his headquarter\n",Hour.c_str(),minute.c_str(),name().c_str(),id,city[location].life);   
        }   
        else {   
            printf("%s:%s blue %s %d earned %d elements for his headquarter\n",Hour.c_str(),minute.c_str(),name().c_str(),id,city[location].life);   
        }   
        city[location].t=country;   
        if(city[location].fight==-1&&country=="red"){   
            city[location].fight=-2;   
        }   
        else if(city[location].fight==1&&country=="blue"){   
            city[location].fight=2;   
        }   
        else if(country=="red") city[location].fight=-1;   
        else if(country=="blue") city[location].fight=1;  
        if(city[location].fight==2&&city[location].flag!="blue"){   //胜两次
            printf("%s:%s blue flag raised in city %d\n",Hour.c_str(),minute.c_str(),location);   
            city[location].fight=0;   
            city[location].flag="blue";   
        }   
        else if(city[location].fight==-2&&city[location].flag!="red"){   
            printf("%s:%s red flag raised in city %d\n",Hour.c_str(),minute.c_str(),location);   
            city[location].fight=0;   
            city[location].flag="red";   
        }   
    }   
    virtual void Move()   
    {   
        if (country=="red"&&location<N){   
            if(city[location].pred==this) city[location].pred=NULL;   
            location++;   
            printf("%s:%s red %s %d marched to city %d with %d elements and force %d\n",Hour.c_str(),minute.c_str(),name().c_str(),id,location,life,power);   
        }   
        else if(country=="blue"&&location>1) {   
            if(city[location].pblue==this ) city[location].pblue=NULL;   
            location--;   
            printf("%s:%s blue %s %d marched to city %d with %d elements and force %d\n",Hour.c_str(),minute.c_str(),name().c_str(),id,location,life,power);   
        }   
        else if(country=="red"&&location==N){   
            if(city[location].pred==this) city[location].pred=NULL;   
            location++;   
            city[N+1].pred=this;   
            printf("%s:%s red %s %d reached blue headquarter with %d elements and force %d\n",Hour.c_str(),minute.c_str(),name().c_str(),id,life,power);   
            Bluehead.reachnum++;   
            if(Bluehead.reachnum==2){   
                printf("%s:%s blue headquarter was taken\n",Hour.c_str(),minute.c_str());   
                stop=1;   
            }   
        }   
        else if(country=="blue"&&location==1){   
            if(city[location].pblue==this) city[location].pblue=NULL;   
            location--;   
            city[0].pblue=this;   
            printf("%s:%s blue %s %d reached red headquarter with %d elements and force %d\n",Hour.c_str(),minute.c_str(),name().c_str(),id,life,power);   
            Redhead.reachnum++;   
            if(Redhead.reachnum==2){   
                printf("%s:%s red headquarter was taken\n",Hour.c_str(),minute.c_str());   
                stop=1;   
            }   
        }   
    }   
    virtual void Attack( warrior & f )   
    {   
        printf("%s:%s %s %s %d attacked %s %s %d in city %d with %d elements and force %d\n",Hour.c_str(),minute.c_str(),country.c_str(),name().c_str(),id,f.country.c_str(),f.name().c_str(),f.id,location,life,power);   
        if(bsword==1){   
            if ( f.life>power+sword ) {   
                f.life-=power+sword;   
                sword*=0.8;   
                if(sword==0) bsword=0;   
                if(bdragon==1) morale-=0.2;   
                if(blion==1) loyal-=K;   
                f.Attackback(*this);   
                if(city[location].flag==country||(city[location].flag!="blue"&&location%2==1&&country=="red")||(city[location].flag!="red"&&location%2==0&&country=="blue"))   
                    Yale();   
                if(life>0) city[location].fight=0;   
            }   
            else {   
                if(f.blion==1) life+=f.life;   
                sword*=0.8;   
                if(sword==0) bsword=0;   
                printf("%s:%s %s %s %d was killed in city %d\n",Hour.c_str(),minute.c_str(),f.country.c_str(),f.name().c_str(),f.id,location);   
                f.life=0;   
                Win();   
            }   
        }   
        else {   
            if(f.life>power){   
                f.life-=power;   
                loyal-=K;   
                morale-=0.2;   
                f.Attackback(*this);   
                if(city[location].flag==country||(city[location].flag!="blue"&&location%2==1&&country=="red")||(city[location].flag!="red"&&location%2==0&&country=="blue"))   
                    Yale();   
                if(life>0) city[location].fight=0;  
            }   
            else {   
                if(f.blion==1) life+=f.life;   
                f.life=0;   
                printf("%s:%s %s %s %d was killed in city %d\n",Hour.c_str(),minute.c_str(),f.country.c_str(),f.name().c_str(),f.id,location);   
                Win();   
            }   
        }  
    }   
    virtual void Attackback( warrior & f)   
    {   
        printf("%s:%s %s %s %d fought back against %s %s %d in city %d\n",Hour.c_str(),minute.c_str(),country.c_str(),name().c_str(),id,f.country.c_str(),f.name().c_str(),f.id,location);    
        if(bsword==1){   
            if (f.life>power/2+sword) {   
                city[location].fight=0;   
                loyal-=K;   
                f.life-=power/2+sword;   
                sword*=0.8;   
                if(sword==0) bsword=0;   
                if(bdragon==1) morale-=0.2;   
            }   
            else {   
                if(f.blion==1) life+=f.life;   
                f.life=0;   
                sword*=0.8;   
                if(sword==0) bsword=0;   
                printf("%s:%s %s %s %d was killed in city %d\n",Hour.c_str(),minute.c_str(),f.country.c_str(),f.name().c_str(),f.id,location);   
                Win();   
            }   
        }   
        else {   
            if (f.life>power/2) {   
                f.life-=power/2;   
                loyal-=K;   
                if(bdragon==1) morale-=0.2;   
                city[location].fight=0;   
            }   
            else {   
                if(f.blion==1) life+=f.life;   
                f.life=0;   
                printf("%s:%s %s %s %d was killed in city %d\n",Hour.c_str(),minute.c_str(),f.country.c_str(),f.name().c_str(),f.id,location);   
                Win();   
            }   
        }   
    }   
    virtual void escape(){}  
    warrior(string _country,int _location,int _life,int _id,int _power):country(_country),location(_location),life(_life),id(_id),power(_power)   
    {   
        if(country=="red"){   
            city[0].pred=this;   
            location=0;   
        }   
        else{   
            city[N+1].pblue=this;   
            location=N+1;   
        }   
        arrow=0;   
        blion=0;   
        sword=0;   
        bdragon=0;   
        bsword=barrow=bbomb=0;   
    }   
};   
class Dragon :public warrior   
{   
public:   
    virtual string name(){return "dragon";}   
    void Yale()   
    {   
        if(life>0&&morale>0.8) printf("%s:%s %s dragon %d yelled in city %d\n",Hour.c_str(),minute.c_str(),country.c_str(),id,location);   
    }   
    Dragon(string _country,int _location,int _id,int _life=hp["dragon"],int _power=atk["dragon"]):warrior(_country,_location,_life,_id,_power)   
    {   
        bdragon=1;   
        if(country=="red"){   
            Redhead.life-=hp["dragon"];   
        }   
        else {   
            Bluehead.life-=hp["dragon"];   
        }   
        if(id%3==0) {    
            bsword=1;   
            sword=0.2*power;   
            if(sword==0 ) bsword=0;   
        }   
        else if(id%3==1) bbomb=1;   
        else {   
            barrow=1;   
            arrow=3;   
        }   
        if(country=="red") morale=(Redhead.life+0.0)/hp["dragon"];   
        else morale=(Bluehead.life+0.0)/hp["dragon"];   
        printf("%s:%s %s dragon %d born\n",Hour.c_str(),minute.c_str(),country.c_str(),id);   
        printf("Its morale is %.2f\n",morale);   
    }   
};   
class Ninja:public warrior   
{   
public:   
    virtual string name(){return "ninja";}   
    virtual void Attackback(warrior & f)   
    {   
        if(life>0) city[location].fight=0;   
    }   
    virtual int n2attack() { return 0;}   
    Ninja(string _country,int _location,int _id,int _life=hp["ninja"],int _power=atk["ninja"]):warrior(_country,_location,_life,_id,_power)   
    {   
        if(country=="red"){   
            Redhead.life-=hp["ninja"];   
        }   
        else {   
            Bluehead.life-=hp["ninja"];   
        }   
        if(id%3==0) {   
            bsword=1;   
            bbomb=1;   
            sword=0.2*power;   
            if(sword==0 ) bsword=0;   
        }   
        else if(id%3==1){   
            bbomb=1;   
            barrow=1;   
            arrow=3;   
        }   
        else{   
            barrow=1;   
            arrow=3;   
            bsword=1;   
            sword=0.2*power;   
            if(sword==0 ) bsword=0;   
        }   
        printf("%s:%s %s ninja %d born\n",Hour.c_str(),minute.c_str(),country.c_str(),id);   
    }   
};   
class Iceman:public warrior   
{   
public:   
    virtual string name(){return "iceman";}   
    virtual void Move()   
    {   
        if(country=="red"&&location%2==1&&location!=0){   
            if(life>9) life-=9;   
            else life=1;   
            power+=20;   
        }   
        if(country=="blue"&&(location-N)%2==0&&location!=N+1){   
            if(life>9) life-=9;   
            else life=1;   
            power+=20;   
        }   
        if (country=="red"&&location<N){   
            if(city[location].pred==this) city[location].pred=NULL;   
            location++;   
            printf("%s:%s red %s %d marched to city %d with %d elements and force %d\n",Hour.c_str(),minute.c_str(),name().c_str(),id,location,life,power);   
        }   
        else if(country=="blue"&&location>1) {   
            if(city[location].pblue==this ) city[location].pblue=NULL;   
            location--;   
            printf("%s:%s blue %s %d marched to city %d with %d elements and force %d\n",Hour.c_str(),minute.c_str(),name().c_str(),id,location,life,power);   
        }   
        else if(country=="red"&&location==N){   
            if(city[location].pred==this) city[location].pred=NULL;   
            location++;   
            city[N+1].pred=this;   
            printf("%s:%s red %s %d reached blue headquarter with %d elements and force %d\n",Hour.c_str(),minute.c_str(),name().c_str(),id,life,power);   
            Bluehead.reachnum++;   
            if(Bluehead.reachnum==2){   
                printf("%s:%s blue headquarter was taken\n",Hour.c_str(),minute.c_str());   
                stop=1;   
            }   
        }   
        else if(country=="blue"&&location==1){   
            if(city[location].pblue==this) city[location].pblue=NULL;   
            location--;   
            city[0].pblue=this;   
            printf("%s:%s blue %s %d reached red headquarter with %d elements and force %d\n",Hour.c_str(),minute.c_str(),name().c_str(),id,life,power);   
            Redhead.reachnum++;   
            if(Redhead.reachnum==2){   
                printf("%s:%s red headquarter was taken\n",Hour.c_str(),minute.c_str());   
                stop=1;   
            }   
        }   
    }   
    Iceman(string _country,int _location,int _id,int _life=hp["iceman"],int _power=atk["iceman"]):warrior(_country,_location,_life,_id,_power)   
    { 
        if(id%3==0) {    
            bsword=1;   
            sword=0.2*power;   
            if(sword==0 ) bsword=0;   
        }   
        else if(id%3==1) bbomb=1;   
        else {   
            barrow=1;   
            arrow=3;   
        }   
        if(country=="red"){   
            Redhead.life-=hp["iceman"];   
        }   
        else {   
            Bluehead.life-=hp["iceman"];   
        }   
        printf("%s:%s %s iceman %d born\n",Hour.c_str(),minute.c_str(),country.c_str(),id);   
    }   
};   
class Lion:public warrior   
{   
public:   
    virtual string name(){return "lion";}   
    virtual void escape()   
    {   
        if((country=="red"&&location!=N+1)||(country=="blue"&&location!=0)){   
            if(loyal<=0){   
                life=0;   
                if(country=="red")city[location].pred=NULL;   
                else city[location].pblue=NULL;   
                printf("%s:%s %s lion %d ran away\n",Hour.c_str(),minute.c_str(),country.c_str(),id);   
            }   
        }   
    }   
    Lion(string _country,int _location,int _id,int _life=hp["lion"],int _power=atk["lion"]):warrior(_country,_location,_life,_id,_power)   
    {   
        blion=1;   
        if(country=="red"){   
            Redhead.life-=hp["lion"];   
            loyal=Redhead.life;   
        }   
        else {   
            Bluehead.life-=hp["lion"];   
            loyal=Bluehead.life;   
        }   
        printf("%s:%s %s lion %d born\n",Hour.c_str(),minute.c_str(),country.c_str(),id);   
        printf("Its loyalty is %d\n",loyal);   
           
    }   
};   
class Wolf:public warrior   
{   
public:   
    virtual string name(){return "wolf";}   
    virtual void Win()   
    {
        if(country=="red"){   
            printf("%s:%s red %s %d earned %d elements for his headquarter\n",Hour.c_str(),minute.c_str(),name().c_str(),id,city[location].life);   
        }   
        else {   
            printf("%s:%s blue %s %d earned %d elements for his headquarter\n",Hour.c_str(),minute.c_str(),name().c_str(),id,city[location].life);   
        }   
        city[location].t=country;   
        if(city[location].fight==-1&&country=="red"){   
            city[location].fight=-2;   
        }   
        else if(city[location].fight==1&&country=="blue"){   
            city[location].fight=2;   
        }   
        else if(country=="red") city[location].fight=-1;   
        else if(country=="blue") city[location].fight=1;   
        if(city[location].fight==2&&city[location].flag!="blue"){   
            printf("%s:%s blue flag raised in city %d\n",Hour.c_str(),minute.c_str(),location);   
            city[location].fight=0;   
            city[location].flag="blue";   
        }   
        else if(city[location].fight==-2&&city[location].flag!="red"){   
            printf("%s:%s red flag raised in city %d\n",Hour.c_str(),minute.c_str(),location);   
            city[location].fight=0;   
            city[location].flag="red";   
        }   

        if(country=="red"){   
            if(barrow==0&&city[location].pblue!=NULL&&city[location].pblue->barrow==1){   
                barrow=1;   
                arrow=city[location].pblue->arrow;   
            }   
            if(bbomb==0&&city[location].pblue!=NULL&&city[location].pblue->bbomb==1) bbomb=1;   
            if(bsword==0&&city[location].pblue!=NULL&&city[location].pblue->bsword==1){   
                bsword=1;   
                sword=city[location].pblue->sword;   
                if(sword==0 ) bsword=0;   
            }   
        }   
        else {   
            if(barrow==0&&city[location].pred!=NULL&&city[location].pred->barrow==1){   
                barrow=1;   
                arrow=city[location].pred->arrow;   
            }   
            if(bbomb==0&&city[location].pred!=NULL&&city[location].pred->bbomb==1) bbomb=1;   
            if(bsword==0&&city[location].pred!=NULL&&city[location].pred->bsword==1){   
                bsword=1;   
                sword=city[location].pred->sword;   
                if(sword==0 ) bsword=0;   
            }   
        }   

    }   
    Wolf(string _country,int _location,int _id,int _life=hp["wolf"],int _power=atk["wolf"]):warrior(_country,_location,_life,_id,_power)   
    {   
        if(country=="red"){   
            Redhead.life-=hp["wolf"];   
        }   
        else {   
            Bluehead.life-=hp["wolf"];   
        }      
        printf("%s:%s %s wolf %d born\n",Hour.c_str(),minute.c_str(),country.c_str(),id);   
    }   
};   
void clear()   
{   
    int i;    
    Hour="000";   
    minute="00";   
    stop=0;   
    Redhead.life=Bluehead.life=M;   
    Redhead.numofwarrior=Bluehead.numofwarrior=0;   
    for(i=0;i<=N+1;i++) {   
        city[i].life=0;   
        city[i].fight=0;   
        city[i].flag="no";   
        city[i].pblue=city[i].pred=NULL;   
        city[i].t="no";   
        city[i].tlife=0;   
        city[i].num=0;   
    }   
    Redhead.reachnum=Bluehead.reachnum=0;   
    for(i=0;i<999999;i++) Redhead.pf[i]=Bluehead.pf[i]=NULL;   
}   
void produce()   
{   
       
    if(Redhead.numofwarrior%5==0){   
        if(Redhead.life>=hp["iceman"]){   
            ++Redhead.numofwarrior;   
            Redhead.pf[Redhead.numofwarrior]=new Iceman ("red",0,Redhead.numofwarrior);   
        }   
    }   
    else if(Redhead.numofwarrior%5==1){   
        if(Redhead.life>=hp["lion"]){   
            ++Redhead.numofwarrior;   
            Redhead.pf[Redhead.numofwarrior]=new Lion ("red",0,Redhead.numofwarrior);   
        }   
    }   
    else if(Redhead.numofwarrior%5==2){   
        if(Redhead.life>=hp["wolf"]){   
            ++Redhead.numofwarrior;   
            Redhead.pf[Redhead.numofwarrior]=new Wolf ("red",0,Redhead.numofwarrior);   
        }   
    }   
    else if(Redhead.numofwarrior%5==3){   
        if(Redhead.life>=hp["ninja"]){   
            ++Redhead.numofwarrior;   
            Redhead.pf[Redhead.numofwarrior]=new Ninja ("red",0,Redhead.numofwarrior);   
        }   
    }   
    else {   
        if(Redhead.life>=hp["dragon"]){   
            ++Redhead.numofwarrior;   
            Redhead.pf[Redhead.numofwarrior]=new Dragon ("red",0,Redhead.numofwarrior);   
        }   
    }   
       
    if(Bluehead.numofwarrior%5==0){   
        if(Bluehead.life>=hp["lion"]){   
            ++Bluehead.numofwarrior;   
            Bluehead.pf[Bluehead.numofwarrior]=new Lion ("blue",N+1,Bluehead.numofwarrior);   
        }   
    }   
    else if(Bluehead.numofwarrior%5==1){   
        if(Bluehead.life>=hp["dragon"]){   
               
            ++Bluehead.numofwarrior;   
            Bluehead.pf[Bluehead.numofwarrior]=new Dragon ("blue",N+1,Bluehead.numofwarrior);   
        }   
    }   
    else if(Bluehead.numofwarrior%5==1){   
        if(Bluehead.life>=hp["dragon"]){   
            ++Bluehead.numofwarrior;   
            Bluehead.pf[Bluehead.numofwarrior]=new Dragon ("blue",N+1,Bluehead.numofwarrior);   
        }   
    }   
    else if(Bluehead.numofwarrior%5==2){   
        if(Bluehead.life>=hp["ninja"]){   
            ++Bluehead.numofwarrior;   
            Bluehead.pf[Bluehead.numofwarrior]=new Ninja ("blue",N+1,Bluehead.numofwarrior);   
        }   
    }   
    else if(Bluehead.numofwarrior%5==3){   
        if(Bluehead.life>=hp["iceman"]){   
            ++Bluehead.numofwarrior;   
            Bluehead.pf[Bluehead.numofwarrior]=new Iceman ("blue",N+1,Bluehead.numofwarrior);   
        }   
    }   
    else {   
        if(Bluehead.life>=hp["wolf"]){   
            ++Bluehead.numofwarrior;   
            Bluehead.pf[Bluehead.numofwarrior]=new Wolf ("blue",N+1,Bluehead.numofwarrior);   
        }   
    }   
}   
void Move()   
{   
    int i;   
    if(city[1].pblue!=NULL) city[1].pblue->Move();   
    for(i=1;i<=N;i++ ){   
        if(city[i-1].pred!=NULL) city[i-1].pred->Move();   
        if(city[i+1].pblue!=NULL) city[i+1].pblue->Move();   
    }   
    if(city[N].pred!=NULL) city[N].pred->Move();   
       
    for(i=0;i<=Redhead.numofwarrior;i++)   
    {   
           
        if(Redhead.pf[i]!=NULL&&Redhead.pf[i]->life!=0) {   
            city[Redhead.pf[i]->location].pred=Redhead.pf[i];   
        }   
    }   
    for(i=0;i<=Bluehead.numofwarrior;i++)   
    {   
        if(Bluehead.pf[i]!=NULL&&Bluehead.pf[i]->life!=0)    
        {   
            city[Bluehead.pf[i]->location].pblue=Bluehead.pf[i];   
               
        }   
    }   
    for( i=1;i<=N;i++) {   
        if(city[i].pred!=NULL&&city[i].pred->life==0) city[i].pred=NULL;   
        if(city[i].pblue!=NULL&&city[i].pblue->life==0) city[i].pblue=NULL;   
    }   
}   
void escape()   
{   
    for(int i=0;i<=N+1;i++)   
    {   
        if(city[i].pred!=NULL&&city[i].pred->blion==1) city[i].pred->escape();   
        if(city[i].pblue!=NULL&&city[i].pblue->blion==1) city[i].pblue->escape();   
    }   
}   
void lifeincrease()   
{   
    for(int i=1;i<=N;i++) city[i].life+=10;   
}   
void catchlife()   
{   
    for(int i=1;i<=N;i++){   
        if(city[i].pblue==NULL&&city[i].pred!=NULL){   
            printf("%s:%s red %s %d earned %d elements for his headquarter\n",Hour.c_str(),minute.c_str(),city[i].pred->name().c_str(),city[i].pred->id,city[i].life);   
            Redhead.life+=city[i].life;   
            city[i].life=0;   
        }   
        else if(city[i].pblue!=NULL&&city[i].pred==NULL){   
            printf("%s:%s blue %s %d earned %d elements for his headquarter\n",Hour.c_str(),minute.c_str(),city[i].pblue->name().c_str(),city[i].pblue->id,city[i].life);   
            Bluehead.life+=city[i].life;   
            city[i].life=0;   
        }   
    }   
}   
void arrow()   
{   
    for(int i=1;i<=N;i++){   
        if(city[i].pred!=NULL&&city[i].pred->barrow==1) city[i].pred->Arrow();   
        if(city[i].pblue!=NULL&&city[i].pblue->barrow==1) city[i].pblue->Arrow();   
    }   
}   
void Bomb()   
{   
    for(int i=1;i<=N;i++)   
    {   
        if(city[i].pred!=NULL&&city[i].pred->bbomb==1&&city[i].pblue!=NULL&&city[i].pred->life!=0&&city[i].pblue->life!=0) city[i].pred->Bomb();   
        if(city[i].pblue!=NULL&&city[i].pred!=NULL&&city[i].pblue->bbomb==1&&city[i].pblue->life!=0&&city[i].pred->life!=0) {   
            city[i].pblue->Bomb();   
        }   
    }   
}   
void battle()   
{   
    int i;   
    for(i=1;i<=N;i++){   
           
        if(city[i].pblue!=NULL&&city[i].pred!=NULL){   
            if(city[i].pblue->life==0&&city[i].pred->life!=0) city[i].pred->Win();   
            else if(city[i].pblue->life!=0&&city[i].pred->life==0) city[i].pblue->Win();   
            else if(city[i].pblue->life!=0&&city[i].pred->life!=0){   
                if(city[i].flag=="red") city[i].pred->Attack(*city[i].pblue);   
                else if(city[i].flag=="blue") city[i].pblue->Attack(*city[i].pred);   
                else {   
                    if(i%2==1) city[i].pred->Attack(*city[i].pblue);   
                    else  city[i].pblue->Attack(*city[i].pred);   
                }   
            }   
        }   
    }   
       
    int t=1;   
    while(Redhead.life>=8&&t<=N){   
        if(city[t].t=="red"&&city[t].pred!=NULL){   
            Redhead.life-=8;   
            city[t].pred->life+=8;   
        }   
        t++;   
    }   
    t=N;   
    while(t>=1&&Bluehead.life>=8){   
        if(city[t].t=="blue"&&city[t].pblue!=NULL){   
            Bluehead.life-=8;   
            city[t].pblue->life+=8;   
        }   
        t--;   
    }   
       
    for(i=1;i<=N;i++){   
        if(city[i].t=="red"){   
            Redhead.life+=city[i].life;   
            city[i].life=0;   
        }   
        if(city[i].t=="blue"){   
            Bluehead.life+=city[i].life;   
            city[i].life=0;   
        }   
    }   
    for(i=0;i<=N+1;i++)   
    {   
        if(city[i].pred!=NULL&&city[i].pred->life==0) city[i].pred=NULL;   
        if(city[i].pblue!=NULL&&city[i].pblue->life==0) city[i].pblue=NULL;   
    }   
    for(i=1;i<=N;i++) city[i].t="no";   
}   
void reportlife()   
{   
    printf("%s:%s %d elements in red headquarter\n",Hour.c_str(),minute.c_str(),Redhead.life);    
    printf("%s:%s %d elements in blue headquarter\n",Hour.c_str(),minute.c_str(),Bluehead.life);    
}   
void Myreport()   
{   
    int i;   
    for(i=1;i<=N+1;i++){   
        if(city[i].pred!=NULL){   
            if(city[i].pred->barrow==1&&city[i].pred->bbomb==1&&city[i].pred->bsword==1)    
                printf("%s:%s red %s %d has arrow(%d),bomb,sword(%d)\n",Hour.c_str(),minute.c_str(),city[i].pred->name().c_str(),city[i].pred->id,city[i].pred->arrow,city[i].pred->sword);   
            else if(city[i].pred->barrow==1&&city[i].pred->bbomb==1&&city[i].pred->bsword==0)   
                printf("%s:%s red %s %d has arrow(%d),bomb\n",Hour.c_str(),minute.c_str(),city[i].pred->name().c_str(),city[i].pred->id,city[i].pred->arrow);   
            else if(city[i].pred->barrow==0&&city[i].pred->bbomb==1&&city[i].pred->bsword==1)   
                printf("%s:%s red %s %d has bomb,sword(%d)\n",Hour.c_str(),minute.c_str(),city[i].pred->name().c_str(),city[i].pred->id,city[i].pred->sword);   
            else if(city[i].pred->barrow==1&&city[i].pred->bbomb==0&&city[i].pred->bsword==1)   
                printf("%s:%s red %s %d has arrow(%d),sword(%d)\n",Hour.c_str(),minute.c_str(),city[i].pred->name().c_str(),city[i].pred->id,city[i].pred->arrow,city[i].pred->sword);   
            else if(city[i].pred->barrow==1){   
                printf("%s:%s red %s %d has arrow(%d)\n",Hour.c_str(),minute.c_str(),city[i].pred->name().c_str(),city[i].pred->id,city[i].pred->arrow);   
            }   
            else if(city[i].pred->bbomb==1)   
                printf("%s:%s red %s %d has bomb\n",Hour.c_str(),minute.c_str(),city[i].pred->name().c_str(),city[i].pred->id);   
            else if(city[i].pred->bsword==1)    
                printf("%s:%s red %s %d has sword(%d)\n",Hour.c_str(),minute.c_str(),city[i].pred->name().c_str(),city[i].pred->id,city[i].pred->sword);   
            else printf("%s:%s red %s %d has no weapon\n",Hour.c_str(),minute.c_str(),city[i].pred->name().c_str(),city[i].pred->id);   
        }   
    }    
    for( i=0;i<=N;i++){   
        if(city[i].pblue!=NULL){   
            if(city[i].pblue->barrow==1&&city[i].pblue->bbomb==1&&city[i].pblue->bsword==1)    
                printf("%s:%s blue %s %d has arrow(%d),bomb,sword(%d)\n",Hour.c_str(),minute.c_str(),city[i].pblue->name().c_str(),city[i].pblue->id,city[i].pblue->arrow,city[i].pblue->sword);   
            else if(city[i].pblue->barrow==1&&city[i].pblue->bbomb==1&&city[i].pblue->bsword==0)   
                printf("%s:%s blue %s %d has arrow(%d),bomb\n",Hour.c_str(),minute.c_str(),city[i].pblue->name().c_str(),city[i].pblue->id,city[i].pblue->arrow);   
            else if(city[i].pblue->barrow==0&&city[i].pblue->bbomb==1&&city[i].pblue->bsword==1&&city[i].pblue->sword!=0)   
                printf("%s:%s blue %s %d has bomb,sword(%d)\n",Hour.c_str(),minute.c_str(),city[i].pblue->name().c_str(),city[i].pblue->id,city[i].pblue->sword);   
            else if(city[i].pblue->barrow==1&&city[i].pblue->bbomb==0&&city[i].pblue->bsword==1)   
                printf("%s:%s blue %s %d has arrow(%d),sword(%d)\n",Hour.c_str(),minute.c_str(),city[i].pblue->name().c_str(),city[i].pblue->id,city[i].pblue->arrow,city[i].pblue->sword);   
            else if(city[i].pblue->barrow==1)   
                printf("%s:%s blue %s %d has arrow(%d)\n",Hour.c_str(),minute.c_str(),city[i].pblue->name().c_str(),city[i].pblue->id,city[i].pblue->arrow);   
            else if(city[i].pblue->bbomb==1)   
                printf("%s:%s blue %s %d has bomb\n",Hour.c_str(),minute.c_str(),city[i].pblue->name().c_str(),city[i].pblue->id);   
            else if(city[i].pblue->bsword==1)    
                printf("%s:%s blue %s %d has sword(%d)\n",Hour.c_str(),minute.c_str(),city[i].pblue->name().c_str(),city[i].pblue->id,city[i].pblue->sword);   
            else printf("%s:%s blue %s %d has no weapon\n",Hour.c_str(),minute.c_str(),city[i].pblue->name().c_str(),city[i].pblue->id);   
        }   
    }   
}   
void Changetime()   
{   
    if(minute=="00") { produce(); minute="05";}   
    else if(minute=="05") { escape(); minute="10";}   
    else if(minute=="10") { Move(); minute="20";}   
    else if(minute=="20") { lifeincrease(); minute="30"; }   
    else if(minute=="30") { catchlife(); minute="35"; }   
    else if(minute=="35") { arrow(); minute="38";}   
    else if(minute=="38") { Bomb(); minute="40"; }   
    else if(minute=="40") { battle(); minute="50"; }   
    else if(minute=="50") { reportlife(); minute="55"; }   
    else {   
        Myreport();   
        minute="00";   
        Hour[2]++;   
        if(Hour[2]>'9') {   
            Hour[2]='0';   
            Hour[1]++;   
            if(Hour[1]>'9') {   
                Hour[1]='0';   
                Hour[0]++;   
            }   
        }   
    }   
}   
bool condition()   
{   
    int rtn=0;   
    rtn+=(Hour[0]-'0')*100;   
    rtn+=(Hour[1]-'0')*10;   
    rtn+=(Hour[2]-'0');   
    rtn*=60;   
    rtn+=(minute[0]-'0')*10;   
    rtn+=(minute[1]-'0');   
    if(rtn>T) return 1;   
    return 0;   
}   
int main()   
{   
    int n;
    cin>>n;   
    for(int i=1;i<=n;i++){   
        cin>>M>>N>>R>>K>>T;   
        cin >> hp["dragon"] >> hp["ninja"] >> hp["iceman"] >> hp["lion"] >> hp["wolf"];
        cin >> atk["dragon"] >> atk["ninja"] >> atk["iceman"] >> atk["lion"] >> atk["wolf"];
        clear();   
        printf("Case %d:\n",i);   
        while(stop!=1&&condition()!=1 ){   
            Changetime();   
        }   
    }
    return 0;   
}   
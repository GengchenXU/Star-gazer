/*
 * @Description: 
 * @Sample Intput: 
 * @Output: 
 * @Autor: GengchenXu
 * @Date: 2020-06-16 22:15:17
 * @LastEditTime: 2020-06-16 22:28:41
 */ 
#include <iostream>   
#include <stdio.h>   
#include <cstring>   
#include <string.h>   
#include <fstream>   
using namespace std;   
int m=0,n=0,k=0,r=0,t=0;    
const string name[5] = {"dragon", "ninja", "iceman", "lion", "wolf"};   
const int makinglist[2][5] = {2,3,4,1,0,3,0,1,2,4};   
int warriorlife[5]={0};   
int warriorattack[5]={0};   
int templife[2] ={0};   
const string warriorcolor[2] = {"red", "blue"};   
int totallife[2]={0};   
bool lastcolor[2]={0};   
bool headnum[2]={0};   
int totalnum[2]={0};   
bool gameover = 0;   
int hour = 0;   
class sword   
{   
    private:   
    int attacks;   
    public:   
    sword(int a):attacks(a){}   
    void getdull(){attacks = int (attacks * 0.8);}   
    bool destroy(){return (attacks == 0);}   
    int getattacks()   
    {   
            return  attacks;   
    }   
};   
class arrow   
{   
    public:   
            int times;   
            int attacks;   
            arrow(int a,int b)   
            {   
                times = a;   
                attacks = b;   
            }   
            void used()   
            {   
                times--;   
            }   
            bool destroyed(){return (times ==0);}   
};    
class warrior   
{   
    public:   
        int color;   
        int warriorno;   
        int kind;   
        int hp;   
        int attack;   
        arrow *arrows;   
        sword *swords;   
        bool bomb;   
    public:    
        friend class city;   
        warrior(int a,int b,int c)   
        {   
            color = a;   
            warriorno = b;   
            kind = c;   
            hp = warriorlife[kind];   
            attack = warriorattack[kind];   
            totallife[color] -= warriorlife[kind];   
            printf("0%02d:00 %s %s %d born\n",hour,warriorcolor[color].c_str(),name[kind].c_str(),warriorno);   
            arrows = NULL;   
            swords = NULL;   
            bomb = false;   
            switch(c)   
            {   
                    case 0:case 2:   
                        if (b % 3 ==0)   
                        if ((int)(attack*0.2)!=0)   
                              swords = new sword((int)(attack * 0.2));     
                        if (b % 3 ==1)   
                            bomb = true;   
                        if (b % 3 == 2)   
                            arrows = new arrow(3,r);   
                        break;   
                    case 1:   
                        if (b % 3 ==0)   
                        {   
                                if ((int)(attack*0.2)!=0)   
                                    swords = new sword((int)(attack * 0.2));   
                                bomb = true;   
                        }   
                        if (b % 3 ==1)   
                        {   
                                bomb = true;   
                                arrows = new arrow(3,r);   
                        }   
                        if (b % 3 == 2)   
                        {   
                                arrows = new arrow(3,r);   
                                if ((int)(attack*0.2)!=0)   
                                    swords = new sword((int)(attack * 0.2));   
                        }   
                        break;   
                    default:   
                        break;   
                    }   
        }   
        ~warrior()     
        {     
            if (swords!=NULL) delete swords;     
            if (arrows!=NULL) delete arrows;     
        }    
        virtual bool escape() {return false;}    
        virtual double getmorale() {}     
        virtual void changemorale(int) {}   
        virtual void changeloyalty() {}   
        void get_hp(int a) {hp += a;}    
} ;  
class dragon:public warrior   
{   
    private:   
    double morale;   
    public:   
    dragon(int a,int b,int c):warrior(a,b,c)   
    {   
        morale = double (totallife[a])/warriorlife[0];   
        printf("Its morale is %.2lf\n",morale);   
    }   
    double getmorale( )   
    {   
        return morale;   
    }   
    void changemorale(int s)   
    {   
        if (s == 1)   
            morale += 0.2;   
        else   
            morale -= 0.2;   
    }    
};   
class lion:public warrior   
{   
    private:   
    int loyalty;   
    public:   
    lion(int a,int b,int c):warrior(a,b,c)   
    {   
        loyalty = totallife[a];   
        printf("Its loyalty is %d\n",loyalty);   
    }   
    bool escape()   
    {   
        if (loyalty <= 0)   
            return 1;   
        else   
            return 0;   
    }   
    void changeloyalty()   
    {   
        loyalty -= k;   
    }      
};   
class city   
{   
    private:   
        int no;   
        int color;   
        int life;   
        int lastwin;   
        int nowwin;    
    public:   
        warrior *ct[2];   
        ~city()     
        {     
        for (int i=0;i<=1;i++)     
            if (ct[i]!=NULL)     
                delete ct[i];     
        }     
        int getlastwin()   
        {   
            return nowwin;   
        }   
        void shootarrow(city *next,int color_)   
        {   
            if (ct[color_] == NULL)   
                return;   
            if (ct[color_] -> arrows!=NULL && next->ct[1-color_]!=NULL)   
            {   
                next->ct[1-color_]->hp -= ct[color_]->arrows->attacks;   
                ct[color_]->arrows -> used();   
                if (ct[color_]->arrows->destroyed())     
                {     
                    delete ct[color_]->arrows;     
                    ct[color_]->arrows=NULL;     
                }    
                printf("0%02d:35 %s %s %d shot",hour,warriorcolor[color_].c_str(),name[ct[color_]->kind].c_str(),ct[color_]->warriorno);   
                if (next->ct[1-color_]->hp<=0)     
                {     
                    //next.ct[1-color_]->hp=0;     
                    printf(" and killed %s %s %d",warriorcolor[1-color_].c_str(),name[next->ct[1-color_]->kind].c_str(),next->ct[1-color_]->warriorno);     
                }     
                printf("\n");   
            }   
                
        }   
        void bombuse()   
        {   
            int mark = 1;   
            int addattack = 0;   
            if (ct[0]==NULL||ct[1]==NULL||ct[0]->hp<=0||ct[1]->hp<=0)   
                return;   
            if (color == 0 ||(color == -1&&no%2==1))   
                mark = 0;   
            if (ct[mark]->swords!=NULL)     
                addattack = ct[mark]->swords->getattacks();     
            if (ct[1 - mark]->hp <= ct[mark]->attack + addattack)   
            {   
                if (ct[1 - mark] ->bomb)   
                {   
                    printf("0%02d:38 %s %s %d used a bomb and killed %s %s %d\n",hour,warriorcolor[1-mark].c_str(),     
                    name[ct[1-mark]->kind].c_str(),ct[1-mark]->warriorno,warriorcolor[mark].c_str(),name[ct[mark]->kind].c_str(),ct[mark]->warriorno);   
                    delete ct[0],ct[1];   
                    ct[0] = ct[1] = NULL;   
                }   
                return;   
            }   
            addattack=0;     
            if (ct[1-mark]->swords!=NULL)     
                addattack=ct[1-mark]->swords->getattacks();     
            if (ct[1-mark]->kind==1)     
                return;    
            if (ct[mark]->hp <= (ct[1 - mark]->attack) / 2 + addattack)   
            {   
                if (ct[mark] ->bomb)   
                {   
                    printf("0%02d:38 %s %s %d used a bomb and killed %s %s %d\n",hour,warriorcolor[mark].c_str(),     
                    name[ct[mark]->kind].c_str(),ct[mark]->warriorno,warriorcolor[1-mark].c_str(),name[ct[1-mark]->kind].c_str(),ct[1-mark]->warriorno);   
                    delete ct[0],ct[1];   
                    ct[0] = ct[1] = NULL;   
                }   
                return;   
            }                  
        }
        void battle()   
        {   
            int mark = 1;   
            nowwin = -1;   
            int leftlife = 0;   
            int addattack = 0;   
            if (color == 0 ||(color == -1&&no%2==1))   
                mark = 0;   
            if (ct[0]==NULL)     
            {     
                if (ct[1]!=NULL && ct[1]->hp<=0)     
                {     
                    delete ct[1];     
                    ct[1]=NULL;     
                }     
                    return;     
            }     
            if (ct[1]==NULL)     
            {     
                if (ct[0]!=NULL && ct[0]->hp<=0)     
                {     
                    delete ct[0];     
                    ct[0]=NULL;     
                }     
                    return;     
            }      
            if (ct[mark]->hp <= 0 && ct[1-mark]->hp <= 0)     
            {     
                delete ct[0];     
                delete ct[1];     
                ct[0] = ct[1] = NULL;     
                return;     
            }     
            if (ct[mark]->hp<=0)     
            {     
                killeffect(1-mark,0,0);     
                return;     
            }        
            if (ct[1-mark]->hp<=0)     
            {     
                killeffect(mark,0,1);     
                return;     
            }     
            printf("0%02d:40 %s %s %d ",hour,warriorcolor[mark].c_str(),name[ct[mark]->kind].c_str(),ct[mark]->warriorno);     
            printf("attacked %s %s %d in city %d with %d elements and force %d\n",warriorcolor[1-mark].c_str(),name[ct[1-mark]->kind].c_str(),ct[1-mark]->warriorno,no,ct[mark]->hp,ct[mark]->attack);     
            if (ct[1-mark]->kind==3)     
                leftlife=ct[1-mark]->hp;     
            addattack = get_attack(mark);     
            ct[1-mark]->hp -= ct[mark]->attack + addattack;     
            if (ct[1-mark]->hp<=0)     
            {     
                printf("%03d:40 %s %s %d was killed in city %d\n",hour,warriorcolor[ct[1-mark]->color].c_str(),name[ct[1-mark]->kind].c_str(),ct[1-mark]->warriorno,no);     
                killeffect(mark,leftlife,1);     
                return;     
            }     
            if (ct[1-mark]->kind!=1)     
            {     
                addattack=get_attack(1-mark);     
                printf("%03d:40 %s %s %d fought back against %s %s %d in city %d\n",hour,warriorcolor[1-mark].c_str(),     
                    name[ct[1-mark]->kind].c_str(),ct[1-mark]->warriorno,warriorcolor[mark].c_str(),name[ct[mark]->kind].c_str(),ct[mark]->warriorno,no);     
                if (ct[mark]->kind==3)     
                    leftlife = ct[mark]->hp;     
                else    
                    leftlife = 0;     
                ct[mark]->hp -= ct[1-mark] -> attack/2 + addattack;     
                if (ct[mark]->hp<=0)     
                {     
                    printf("%03d:40 %s %s %d was killed in city %d\n",hour,warriorcolor[ct[mark]->color].c_str(),name[ct[mark]->kind].c_str(),     
                        ct[mark]->warriorno,no);     
                    killeffect(1-mark,leftlife,0);     
                    return;     
                }     
            }
            ct[0]->changeloyalty();     
            ct[1]->changeloyalty();     
            ct[mark]->changemorale(0);     
            //ct[mark]->yell(no);     
            if (ct[mark]->getmorale() > 0.8)     
                printf("%03d:40 %s dragon %d yelled in city %d\n",hour,warriorcolor[mark].c_str(),ct[mark] ->warriorno,no);    
            lastwin=-1;    
        }   
        void killeffect(int color_,int lionhp,int zhudong)   
        {   
            if (ct[color_] ->kind == 4)   
            {   
                if (ct[color_]->swords == NULL && ct[1-color_]->swords!=NULL)     
                    ct[color_]->swords = new sword(ct[1-color_]->swords->getattacks());     
                if (ct[color_]->bomb ==0 && ct[1-color_]->bomb)     
                    ct[color_]->bomb = 1;     
                if (ct[color_]->arrows == NULL && ct[1-color_]->arrows != NULL)     
                    ct[color_]->arrows = new arrow(ct[1-color_]->arrows->times,ct[1-color_]->arrows->attacks);   
            }   
            delete ct[1 - color_];   
            ct[1 - color_] = NULL;   
            if (zhudong == 1)   
            {   
                ct[color_]->changemorale(1);   
                if (ct[color_] -> getmorale() > 0.8)     
                    printf("%03d:40 %s dragon %d yelled in city %d\n",hour,warriorcolor[color_].c_str(),ct[color_]->warriorno,no);    
            }   
            ct[color_]->hp += lionhp;     
            printf("%03d:40 %s %s %d earned %d elements for his headquarter\n",hour,     
            warriorcolor[color_].c_str(),name[ct[color_]->kind].c_str(),ct[color_]->warriorno,life);     
            templife[color_] += life;     
            life = 0;     
            nowwin=color_;     
            if (color!=color_ && lastwin==color_)     
            {     
                color=color_;     
                printf("%03d:40 %s flag raised in city %d\n",hour,warriorcolor[color_].c_str(),no);     
            }     
            lastwin=color_;     
        }   
        int get_attack(int _color)     
        {     
            int addattack=0;     
            if (ct[_color]->swords!=NULL)     
            {     
                addattack = ct[_color]->swords->getattacks();     
                ct[_color]->swords->getdull();     
                if (ct[_color]->swords->destroy())     
                {     
                    delete ct[_color]->swords;     
                    ct[_color]->swords=NULL;     
                }     
            }     
            return addattack;     
        }    
        void doescape(int color_)   
        {   
            if (ct[color_]!=NULL&&ct[color_]->escape())   
            {   
                printf("%03d:05 %s lion %d ran away\n",hour,warriorcolor[color_].c_str(),ct[color_]->warriorno);   
                delete ct[color_];   
                ct[color_] = NULL;   
            }   
        }   
        void createlife()   
        {   
            life += 10;   
        }   
        void go(city *next,int color_)   
        {   
            ct[color_] = next->ct[color_];   
            if (ct[color_]!=NULL && ct[color_]->kind==2)     
            {     
                if ((color_==0 && no%2==0) || (color_==1 && (n - no)%2==1))     
                {     
                    ct[color_]->hp-=9;     
                    if (ct[color_]->hp<=0)    
                        ct[color_]->hp=1;     
                    ct[color_]->attack+=20;     
                }     
            } 
        }   
        void printgo()   
        {   
            for (int i = 0; i <= 1;i++)   
                if (ct[i]!=NULL)     
                    printf("%03d:10 %s %s %d marched to city %d with %d elements and force %d\n",hour,     
                    warriorcolor[i].c_str(),name[ct[i]->kind].c_str(),ct[i]->warriorno,no,ct[i]->hp,ct[i]->attack);   
            return;   
        }   
        bool reachheadcity(int color_)   
        {   
            if (!lastcolor[color_])   
            return false;   
            printf("%03d:10 %s %s %d reached %s headquarter with %d elements and force %d\n",hour,     
        warriorcolor[color_].c_str(),name[ct[color_]->kind].c_str(),ct[color_]->warriorno,warriorcolor[1-color_].c_str(),ct[color_]->hp,ct[color_]->attack);   
            if (headnum[color_]) return true;     
            headnum[color_]=true;     
            return false;                                                                                                                                                   
        } 
        void init(int z)   
        {   
            lastwin = nowwin = color = -1;   
            no = z;   
            life = 0;   
            ct[0] = ct[1] = NULL;   
        }   
        void getlife()   
        {   
            if (ct[0]!=NULL&&ct[1]==NULL)   
            {   
                totallife[0] += life;   
                printf("%03d:30 %s %s %d earned %d elements for his headquarter\n",hour,warriorcolor[0].c_str(),name[ct[0]->kind].c_str(),ct[0]->warriorno,life);   
                life = 0;   
            }   
            if (ct[0]==NULL&&ct[1]!=NULL)   
            {   
                totallife[1] += life;   
                printf("%03d:30 %s %s %d earned %d elements for his headquarter\n",hour,warriorcolor[1].c_str(),name[ct[1]->kind].c_str(),ct[1]->warriorno,life);   
                life = 0;   
            }   
        }   
        void showweapon(int color_)   
        {   
            if (ct[color_]==NULL)   
                return;   
            bool hasweapon = 0;   
            printf("%03d:55 %s %s %d has ",hour,warriorcolor[color_].c_str(),name[ct[color_]->kind].c_str(),ct[color_]->warriorno);   
            if (ct[color_] ->arrows!=NULL)   
            {   
                hasweapon = 1;   
                printf("arrow(%d)",ct[color_]->arrows->times);   
            }   
            if (ct[color_] ->bomb)   
            {   
                if (hasweapon)   
                    printf(",");   
                hasweapon = 1;   
                printf("bomb");   
            }   
            if (ct[color_] ->swords!=NULL)   
            {   
                if (hasweapon)   
                    printf(",");   
                hasweapon = 1;   
                printf("sword(%d)",ct[color_]->swords->getattacks());   
            }   
            if (!hasweapon)   
                printf("no weapon");   
            printf("\n"); 
        }   
}citys[22];   
void produce()   
{   
    for (int s = 0; s <= 1; s++)   
    {   
        int list = makinglist[s][totalnum[s] % 5];   
        if (totallife[s] >= warriorlife[list])   
        {      
            totalnum[s]++;   
            warrior *p; 
            switch(list)   
            {   
                case 0:   
                    p = new dragon(s,totalnum[s],0);   
                    break;   
                case 1:   
                    p = new warrior(s,totalnum[s],1);   
                    break;   
                case 2:   
                    p = new warrior(s,totalnum[s],2);   
                    break;   
                case 3:   
                    p = new lion(s,totalnum[s],3);   
                    break;   
                case 4:   
                    p = new warrior(s,totalnum[s],4);   
                    break;   
            }   
            citys[(s==0)?0:(n+1)].ct[s] = p;   
        }   
    }   
}   
void dogo()   
{   
        
    lastcolor[0] = lastcolor[1]= 0;   
    if (citys[n].ct[0]!=NULL)     
    {     
        citys[n+1].go(&citys[n],0);     
        lastcolor[0]=true;     
    }     
    for (int i=n;i>=1;i--)     
        citys[i].go(&citys[i-1],0);     
    if (citys[1].ct[1]!=NULL)     
    {     
        citys[0].go(&citys[1],1);     
        lastcolor[1]=true;     
    }     
    for (int i=1;i<=n;i++)     
        citys[i].go(&citys[i+1],1);     
    citys[0].ct[0]=citys[n+1].ct[1]=NULL;     
    if (citys[0].reachheadcity(1))     
    {                                 
        printf("%.3d:10 red headquarter was taken\n",hour);     
        gameover=true;
    }     
    for (int i=1;i<=n;i++)     
        citys[i].printgo();     
    if (citys[n+1].reachheadcity(0))     
    {     
        printf("%.3d:10 blue headquarter was taken\n",hour);     
        gameover=true;
    }     
}   
void reward()   
{   
    for (int i=1;i<=n;i++)     
    {     
        if (totallife[1]<8) break;     
        if (citys[i].getlastwin()==1)     
        {
            citys[i].ct[1]->get_hp(8);     
            totallife[1]-=8;    
        }     
    }     
    for (int i=n;i>=1;i--)     
    {     
        if (totallife[0]<8)  break;     
        if (citys[i].getlastwin()==0)     
        { 
            citys[i].ct[0]->get_hp(8);     
            totallife[0]-=8;    
        }     
    }     
    for (int i=0;i<=1;i++)     
    {     
        totallife[i]+=templife[i];     
        templife[i]=0;     
    }     
}   
int main()   
{  
        int summ=0;   
        scanf("%d",&summ);   

        int z = 1;   
        while(1)   
        {   
                if (z > summ)   
                        break;   
                    m = n = r = k = t = 0;   
                scanf("%d %d %d %d %d",&m,&n,&r,&k,&t);   
                hour = 0;   
                gameover = 0;   
                totallife[0] = m;   
                totallife[1] = m;   
                headnum[0] = headnum[1] = 0;   
                lastcolor[0] = lastcolor[1] = 0;   
                totalnum[0] = totalnum[1] = 0;   
                templife[0] = templife[1] = 0;   
                for (int q = 0; q < n + 2; q++)   
                        citys[q].init(q);     
                for (int j = 0; j < 5; j++)   
                {   
                            warriorlife[j] = 0;   
                            scanf("%d",&warriorlife[j]);   
                }   
                for (int j = 0; j < 5; j++)   
                {   
                            warriorattack[j] = 0;   
                            scanf("%d",&warriorattack[j]);   
                }   
                printf("Case %d:\n",z++);   
                int time=0;   
                int min = 0;   
                for (time = 0; time <= t && gameover == 0; time++)   
                {   
                        hour = time/60;   
                        min = time % 60;   
                        switch (min)   
                        {   
                                case 0:   
                                    produce();   
                                    break;   
                                case 5:   
                                    citys[0].doescape(0);   
                                for (int q = 1; q <= n; q++)   
                                    for (int w = 0;w <= 1;w++)   
                                            citys[q].doescape(w);   
                                    citys[n + 1].doescape(1);   
                                    break;   
                                case 10:   
                                dogo();   
                                    break;   
                                case 20:
                                    for (int q = 0; q <= n + 1; q++)   
                                        citys[q].createlife();  
                                        break;   
                                case 30:   
                                    for (int q = 1; q <= n; q++)   
                                        citys[q].getlife();  
                                        break;   
                                case 35:   
                                    citys[1].shootarrow(&citys[2],0);     
                                    for (int i=2;i<=n-1;i++)     
                                    {     
                                        citys[i].shootarrow(&citys[i+1],0);     
                                        citys[i].shootarrow(&citys[i-1],1);     
                                    }     
                                    citys[n].shootarrow(&citys[n-1],1);   
                                    break;   
                                case 38:   
                                    for (int i = 1; i <= n; i++)   
                                        citys[i].bombuse();   
                                    break;   
                                case 40:   
                                    for (int i=1;i<=n;i++)     
                                        citys[i].battle();   
                                    reward();   
                                    break;   
                                case 50:   
                                    for (int i = 0; i <= 1; i++)     
                                        printf("%03d:50 %d elements in %s headquarter\n",hour,totallife[i],warriorcolor[i].c_str());    
                                    break;     
                                case 55:   
                                    for (int i = 0; i <= 1; i++)   
                                        for (int q = 0; q <= n+1; q++)   
                                            citys[q].showweapon(i);   
                                    break;
                        }   
                    }
        }   
        return 0;   
}  

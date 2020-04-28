#include <iostream>
#include <list>
#include <Windows.h>
#include <time.h>
using namespace std;
class Item;
class Pokemon
{
private:
	int ID;
	string name;
	int attackPoint;
	int defendPoint;
	int hitPoint;
	int curHitPoint;
	int skillPoint;
	int skillCost;
	int curSkillPoint;
	int experiencePoint;
	float skillPower;
	int level=1;
	int die;
	Item** items=new Item*[100];	//背包最大允许100件物品
	int itemNumber = 0;	//物品数量
public:
	string GetName();
	int GetID();
	int GetAttackPoint();
	int GetDefendPoint();
	int GetHitPoint();
	int GetCurHitPoint();
	int GetSkillPoint();
	int GetSkillCost();
	int GetCurSkillPoint();
	int GetLevel();
	int GetSkillPower();
	int SetID(int);
	int SetName(string);
	int SetAttackPoint(int);
	int SetDefendPoint(int);
	int SetHitPoint(int);
	int SetCurHitPoint(int);
	int SetSkillPoint(int);
	int SetSkillCost(int);
	int SetCurSkillPoint(int);
	int SetExpPoint(int);
	int SetLevel(int);
	int SetSkillPower(float);
	int ChangeCurHitPoint(const int&);
	int New();
	void SetItemNumber(int);
	int GetItemNumber();
	Item*& GetItem(int);
	virtual void Upgrade() = 0;
	virtual void SkillInfo() = 0;

};
#pragma once

void Pokemon::SetItemNumber(int num)
{
	itemNumber = num;
}
int Pokemon::GetItemNumber()
{
	return itemNumber;
}
Item*& Pokemon::GetItem(int id)
{
		return items[id];
}
string Pokemon::GetName()
{
	return name;
}
int Pokemon::GetID()
{
	return ID;
}
int Pokemon::GetAttackPoint()
{
	return attackPoint;
}
int Pokemon::GetDefendPoint()
{
	return defendPoint;
}
int Pokemon::GetHitPoint()
{
	return hitPoint;
}
int Pokemon::GetCurHitPoint()
{
	return curHitPoint;
}
int Pokemon::GetSkillPower()
{
	return skillPower;
}
int Pokemon::GetSkillPoint()
{
	return skillPoint;
}
int Pokemon::GetSkillCost()
{
	return skillCost;
}

int Pokemon::GetLevel()
{
	return level;
}
/* this part is set */
int Pokemon::SetName(string n)
{
	name = n;
	return 0;
}
int Pokemon::SetID(int id)
{
	ID = id;
	return ID;
}

int Pokemon::SetAttackPoint(int attack)
{
	attackPoint = attack;
	return attackPoint;
}
int Pokemon::SetDefendPoint(int defend)
{
	defendPoint = defend;
	return defendPoint;
}
int Pokemon::SetHitPoint(int hp)
{
	hitPoint = hp;
	return hitPoint;
}
int Pokemon::SetCurHitPoint(int curhp)
{
	curHitPoint = curhp;
	return curHitPoint;
}
int Pokemon::SetSkillPoint(int sp)
{
	skillPoint = sp;
	return skillPoint;
}
int Pokemon::SetSkillCost(int spcost)
{
	skillCost = spcost;
	return skillCost;
}
int Pokemon::SetSkillPower(float power)
{
	skillPower = power;
	return skillPower;
}
int Pokemon::SetCurSkillPoint(int cursp)
{
	curSkillPoint = cursp;
	return curSkillPoint;
}
int Pokemon::GetCurSkillPoint()
{
	return curSkillPoint;
}
int Pokemon::SetExpPoint(int exp)
{
	experiencePoint = exp;
	return experiencePoint;
}

int Pokemon::SetLevel(int ll)
{
	for (int i = level; i < ll; i++)
		Upgrade();
	level = ll;
	return level;
}

int Pokemon::ChangeCurHitPoint(const int& chp)
{
	curHitPoint += chp;
	/* check if curHitPoint is valid.*/
	if (curHitPoint < 0)
		curHitPoint = 0;
	if (curHitPoint > hitPoint)
		curHitPoint = hitPoint;
	return curHitPoint;
}


//#include "pokemon.h"
class Item
{
	string name;	//物品名称
	int number;		//物品数量
public:
	Pokemon* user;	//使用者
	Item(int num, Pokemon* u) { number = num; user = u; }
	void SetName(string input) { name = input; }
	string GetName() { return name; }
	void SetNumber(int num) { number = num; }
	int GetNumber() { return number; }
	virtual int function() = 0;	//定义一个纯虚类,表示物品功能
	virtual string statement(Pokemon& enemy) = 0;	//定义一个纯虚类，表示物品说明
};

class HPpotion :public Item
{
public:
	HPpotion(int num, Pokemon* u) :Item(num, u) { SetName("HP药"); }
	int function()
	{
		user->SetCurHitPoint(user->GetCurHitPoint() + 20);
		if (user->GetCurHitPoint() > user->GetHitPoint())
			user->SetCurHitPoint(user->GetHitPoint());	//如果超出最大值，让其等于最大值
		SetNumber(GetNumber() - 1);
		return 0;	//恢复系物品不会对对手造成伤害
	}	//定义HP药品类，使用一次补充20点HP,
	string statement(Pokemon& enemy) { return string("补充" + user->GetName() + "20点HP"); }
};
class SPpotion :public Item
{
public:
	SPpotion(int num, Pokemon* u) :Item(num, u) { SetName("SP药"); }
	int function()
	{
		user->SetCurSkillPoint(user->GetCurSkillPoint() + 10);
		if (user->GetCurSkillPoint() > user->GetSkillPoint())
			user->SetCurSkillPoint(user->GetSkillPoint());	//如果超出最大值，让其等于最大值
		SetNumber(GetNumber() - 1);
		return 0;		//恢复系物品不会对对手造成伤害
	}	//定义SP药品类，使用一次补充10点SP
	string statement(Pokemon& enemy) { return string("补充" + user->GetName() + "10点SP"); }
};
class Bomb :public Item
{
public:
	Bomb(int num, Pokemon* u) :Item(num, u) { SetName("炸药"); }
	int function() { SetNumber(GetNumber() - 1); return 30; }	//定义炸药类，使用一次伤害对手30点HP
	string statement(Pokemon& enemy) { return string("造成" + enemy.GetName() + "30点伤害"); }
};
int Pokemon::New()
{
	curHitPoint = hitPoint;
	curSkillPoint = skillPoint;
	SetItemNumber(3);	//初始携带3件物品
	GetItem(0) = new HPpotion(10, this);	//HP药10个
	GetItem(1) = new SPpotion(1, this);	//SP药10个
	GetItem(2) = new Bomb(10, this);	//炸药10个
	return curHitPoint;
}
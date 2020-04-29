/*
 * @Description: 
 * @Autor: GengchenXu
 * @Date: 2020-04-29 22:42:13
 * @LastEditTime: 2020-04-29 22:43:27
 */

#include "pokemon.h"
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
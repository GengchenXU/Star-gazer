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
	Item** items=new Item*[100];	//�����������100����Ʒ
	int itemNumber = 0;	//��Ʒ����
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
	string name;	//��Ʒ����
	int number;		//��Ʒ����
public:
	Pokemon* user;	//ʹ����
	Item(int num, Pokemon* u) { number = num; user = u; }
	void SetName(string input) { name = input; }
	string GetName() { return name; }
	void SetNumber(int num) { number = num; }
	int GetNumber() { return number; }
	virtual int function() = 0;	//����һ��������,��ʾ��Ʒ����
	virtual string statement(Pokemon& enemy) = 0;	//����һ�������࣬��ʾ��Ʒ˵��
};

class HPpotion :public Item
{
public:
	HPpotion(int num, Pokemon* u) :Item(num, u) { SetName("HPҩ"); }
	int function()
	{
		user->SetCurHitPoint(user->GetCurHitPoint() + 20);
		if (user->GetCurHitPoint() > user->GetHitPoint())
			user->SetCurHitPoint(user->GetHitPoint());	//����������ֵ������������ֵ
		SetNumber(GetNumber() - 1);
		return 0;	//�ָ�ϵ��Ʒ����Զ�������˺�
	}	//����HPҩƷ�࣬ʹ��һ�β���20��HP,
	string statement(Pokemon& enemy) { return string("����" + user->GetName() + "20��HP"); }
};
class SPpotion :public Item
{
public:
	SPpotion(int num, Pokemon* u) :Item(num, u) { SetName("SPҩ"); }
	int function()
	{
		user->SetCurSkillPoint(user->GetCurSkillPoint() + 10);
		if (user->GetCurSkillPoint() > user->GetSkillPoint())
			user->SetCurSkillPoint(user->GetSkillPoint());	//����������ֵ������������ֵ
		SetNumber(GetNumber() - 1);
		return 0;		//�ָ�ϵ��Ʒ����Զ�������˺�
	}	//����SPҩƷ�࣬ʹ��һ�β���10��SP
	string statement(Pokemon& enemy) { return string("����" + user->GetName() + "10��SP"); }
};
class Bomb :public Item
{
public:
	Bomb(int num, Pokemon* u) :Item(num, u) { SetName("ըҩ"); }
	int function() { SetNumber(GetNumber() - 1); return 30; }	//����ըҩ�࣬ʹ��һ���˺�����30��HP
	string statement(Pokemon& enemy) { return string("���" + enemy.GetName() + "30���˺�"); }
};
int Pokemon::New()
{
	curHitPoint = hitPoint;
	curSkillPoint = skillPoint;
	SetItemNumber(3);	//��ʼЯ��3����Ʒ
	GetItem(0) = new HPpotion(10, this);	//HPҩ10��
	GetItem(1) = new SPpotion(1, this);	//SPҩ10��
	GetItem(2) = new Bomb(10, this);	//ըҩ10��
	return curHitPoint;
}
class Pikachu : public Pokemon
{
public:
	Pikachu()
	{
		SetLevel(1);
		SetAttackPoint(10);
		SetDefendPoint(3);
		SetHitPoint(30);
		SetSkillPoint(20);
		SetSkillCost(2);
		SetSkillPower(20);
		SetName("?��?��??");
	}
	void SkillInfo()
	{
		cout << "?��?��?????������????????" << endl;
	}
	virtual void Upgrade()
	{
		SetAttackPoint(GetAttackPoint() + rand() % 3);
		SetHitPoint(GetHitPoint() + rand() % 3);
		SetDefendPoint(GetDefendPoint() + rand() % 2);
		SetSkillPoint(GetSkillPoint() + rand() % 2);
		
	}
};
class FireDragon : public Pokemon
{
public:
	FireDragon()
	{
		SetLevel(1);
		SetAttackPoint(13);
		SetDefendPoint(0);
		SetHitPoint(50);
		SetSkillPoint(20);
		SetSkillCost(2);
		SetSkillPower(20);
		SetName("?????��");
	}
	void SkillInfo()
	{
		cout << "?????��??????????????" << endl;
	}
	virtual void Upgrade()
	{
		SetAttackPoint(GetAttackPoint() + rand() % 4);
		SetHitPoint(GetHitPoint() + rand() % 5);
		SetDefendPoint(GetDefendPoint() + rand() % 2);
		SetSkillPoint(GetSkillPoint() + rand() % 2);
	}
};
class Squirtle : public Pokemon
{
public:
	Squirtle()
	{
		SetLevel(1);
		SetAttackPoint(10);
		SetDefendPoint(8);
		SetHitPoint(40);
		SetSkillPoint(20);
		SetSkillCost(2);
		SetSkillPower(20);
		SetName("???��?��");
	}
	void SkillInfo()
	{
		cout << "???��?��?????����???????" << endl;
	}
	virtual void Upgrade()
	{
		SetAttackPoint(GetAttackPoint() + rand() % 2);
		SetHitPoint(GetHitPoint() + rand() % 3);
		SetDefendPoint(GetDefendPoint() + rand() % 2);
		SetSkillPoint(GetSkillPoint() + rand() % 2);
	}
};
class FireRabbit : public Pokemon
{
public:
	FireRabbit()
	{
		SetLevel(1);
		SetAttackPoint(10);
		SetDefendPoint(8);
		SetHitPoint(40);
		SetSkillPoint(20);
		SetSkillCost(2);
		SetSkillPower(20);
		SetName("?��???��");
	}
	void SkillInfo()
	{
		cout << "?��???��????????????" << endl;
	}
	virtual void Upgrade()
	{
		SetAttackPoint(GetAttackPoint() + rand() % 3);
		SetHitPoint(GetHitPoint() + rand() % 3);
		SetDefendPoint(GetDefendPoint() + rand() % 2);
		SetSkillPoint(GetSkillPoint() + rand() % 2);
	}
};
class Frog : public Pokemon
{
public:
	Frog()
	{
		SetLevel(1);
		SetAttackPoint(10);
		SetDefendPoint(8);
		SetHitPoint(40);
		SetSkillPoint(20);
		SetSkillCost(2);
		SetSkillPower(20);
		SetName("??????��?");
	}
	void SkillInfo()
	{
		cout << "??????��????????��??????" << endl;
	}
	virtual void Upgrade()
	{
		SetAttackPoint(GetAttackPoint() + rand() % 3);
		SetHitPoint(GetHitPoint() + rand() % 3);
		SetDefendPoint(GetDefendPoint() + rand() % 2);
		SetSkillPoint(GetSkillPoint() + rand() % 2);
	}
};

#define BTL_ROLETURN 1
#define BTL_MONSTERTURN 0
void ext_print_line()
{
	for (int i = 0; i < 55; ++i)
		cout << '-';
	cout << endl;
}
int GetDemagePoint(Pokemon* role, Pokemon* pokemon, float skillpower=1)
{
	/* the random number that deceide miss or not between role and pokemon*/
	int rollMissOrNot;
	/* miss or not?*/
	//int missOrNot;
	/* a temporary number,may one more meaning*/
	int missNum;
	/* the temporary demage point in this function*/
	int tempDemagePoint;
	rollMissOrNot = rand() / 100;
	/*
	 * when pokemon attack role ,the miss will depend on the level between
	 * them,each level add 5%,and at most 40%, En...
	 */
	missNum = (pokemon->GetLevel() - role->GetLevel()) * 5;
	missNum = missNum > 40 ? 40 : missNum;
	if (rollMissOrNot < missNum) /* pokemon didn't hit role ,he miss!*/
		return -1;
	else
	{
		tempDemagePoint = role->GetAttackPoint()* skillpower - pokemon->GetDefendPoint();
		if (tempDemagePoint <= 0)
			tempDemagePoint = 1;
		return tempDemagePoint;
	}
}
int	Fight(Pokemon* attacker, Pokemon* defender)
{
	int damage;
	int select;
	int select_item;
	ext_print_line();
	cout << "1:��ͨ����  2:ʹ�ü���  3:ʹ����Ʒ" << endl;	//���²˵�
	while (true)
	{
		ext_print_line();
		cin >> select;
		if (select == 1 || select == 2  || select ==3)
		{
			if (select == 1)
			{

				damage = GetDemagePoint(attacker, defender);
				return damage;
			}
			else if (select == 2)
			{
				if (attacker->GetCurSkillPoint() < attacker->GetSkillCost())
				{
					cout << "SP �������㣡" << endl;
					continue;
				}
				damage = GetDemagePoint(attacker, defender, attacker->GetSkillPower());
				attacker->SkillInfo();
				attacker->SetCurSkillPoint(attacker->GetCurSkillPoint() - 2);
				return damage;
			}
			else if (select == 3)
			{
				if (attacker->GetItemNumber() > 0)
				{
					for (int i = 0; i < attacker->GetItemNumber(); i++)
					{
						cout<<i<<":"<< attacker->GetItem(i)->GetName() << "(" << attacker->GetItem(i)->GetNumber() << ")" << " ";
					}
					cout << "10:������һ���˵�" << endl;
					ext_print_line();
					cin >> select_item;
					if (select_item >= 0 && select_item < attacker->GetItemNumber())
					{
						cout << "ʹ����Ʒ" << attacker->GetItem(select_item)->GetName()<<endl;
						cout << attacker->GetItem(select_item)->statement(*defender) << endl;	//��ʾ��Ʒʹ��Ч��
						damage=attacker->GetItem(select_item)->function();	//ִ�й���
						if (attacker->GetItem(select_item)->GetNumber() == 0)	//�����Ʒ�ù���
						{
							for (int i = select_item; i < attacker->GetItemNumber(); i++)
							{
								attacker->GetItem(i) = (attacker->GetItem(i+1)); 	//������Ʒ���飬ȥ���ù����Ʒ
							}
							attacker->SetItemNumber(attacker->GetItemNumber() - 1);
						}
						Sleep(2000);
						return damage;
					}
					else// if (select_item == 10)
					{
						cout << "1:��ͨ����  2:ʹ�ü���  3:ʹ����Ʒ" << endl;
						continue;
					}
				}
			}
			else
				continue;
			break;
		}
			
	}
	
	return 0;
}

int Battle(Pokemon* role, Pokemon* pokemon, int stage)
{
	
	int whosTurnWhenAttack = BTL_ROLETURN;
	int temp;
	
	pokemon->New();

	while (true)
	{
		system("cls");
		cout << "��" << stage << "��" << endl;
		cout << "ս����...." << endl;

		cout << "  ʣ�༼�ܵ����� " << role->GetCurSkillPoint() << endl;
		cout << "   " << role->GetName() << ":";
		temp = int((float(role->GetCurHitPoint()) / float(role->GetHitPoint())) * 50);
		for (int i_hit = 0; i_hit < 50; ++i_hit)
			if (i_hit < temp)
				cout << '|';
			else
				cout << '.';
		cout << '(' << role->GetCurHitPoint() << ')';
		cout << endl << "   " << pokemon->GetName() << ":";
		temp = int((float(pokemon->GetCurHitPoint()) / float(pokemon->GetHitPoint())) * 50);
		for (int i_hit = 0; i_hit < 50; ++i_hit)
			if (i_hit < temp)
				cout << '|';
			else
				cout << '.';
		cout << '(' << pokemon->GetCurHitPoint() << ')';
		cout << endl;

		//role's turn
		if (whosTurnWhenAttack == BTL_ROLETURN)
		{
			int roletoPokemon = Fight(role, pokemon);
			if (roletoPokemon < 0) { 
				cout << role->GetName() << "û�л��У�" << endl;
			}
			else {
				pokemon->ChangeCurHitPoint(-roletoPokemon);
				cout << "���" << pokemon->GetName() << "�����" << roletoPokemon << "�˺�" << endl;
				if (pokemon->GetCurHitPoint() <= 0)
				{
					cout << pokemon->GetName() << "��������" << endl << "��ϲ���أ�" << endl;
					return 1;
				}
					
			}
			Sleep(2000);
			whosTurnWhenAttack = BTL_MONSTERTURN;
			
		}
		else
		{
			int pokemontoRole = GetDemagePoint(pokemon, role);
			if (pokemontoRole < 0) { 
				cout << pokemon->GetName() << "û�л��У�" << endl;
			}
			else {
				
				role->ChangeCurHitPoint(-pokemontoRole);
				cout << pokemon->GetName() << "���������" << pokemontoRole << "�˺�" << endl;
				if (role->GetCurHitPoint() <= 0)
				{
					cout << "���ź��㱻������" << endl << "��Ϸ������" << endl;
					return 0;
				}	
			}
			Sleep(2000);
			whosTurnWhenAttack = BTL_ROLETURN;
		}
	}
	return 1;
}
Pokemon* PokemonGenertor(int level)
{
	srand((unsigned)time(NULL));
	int pokemonId = rand() % 6;
	Pokemon* newPokemon;
	if (pokemonId == 1)
	{
		newPokemon = new Pikachu();
	}
	else if (pokemonId == 2)
	{
		newPokemon = new FireDragon();
	}
	else if (pokemonId == 3)
	{
		newPokemon = new Squirtle();
	}
	else if (pokemonId == 4)
	{
		newPokemon = new FireRabbit();
	}
	else
	{
		newPokemon = new Frog();
	}
	newPokemon->SetLevel(level);
	return newPokemon;
}
int main()
{
	ext_print_line();
	int userInput = 0;
	//cout << "��ѡ�����С���飺1:Ƥ����  2:С���� 3�������" << endl;
	cout << "��ѡ�����С���飺1:Ƥ����  2:С���� 3������� 4�����ö� 5����������" << endl;
	Pokemon* player;
	
	while (true)
	{
		cin >> userInput;
		if (userInput == 1 || userInput == 2 || userInput == 3 || userInput == 4 || userInput==5)
		{
			if (userInput == 1)
			{
				player = new Pikachu();
			}
			else if (userInput == 2)
			{
				player = new FireDragon();
			}
			else if (userInput == 3)
			{
				player = new Squirtle();
			}
			else if (userInput == 4)
			{
				player = new FireRabbit();
			}
			else //if (userinput == 4)
			{
				player = new Frog();
			}
			player->SetLevel(1);
			player->New();
			break;
		}
	}
	cout << "��Ϊ��ı�����ȡ����" << endl;
	string pokemonName;
	cin >> pokemonName;
	player->SetName(pokemonName);
	cout << "��ʼ��Ϸ��" << endl;
	Sleep(2000);
	int stage = 1;
	while (true)
	{
		Pokemon* enemy=PokemonGenertor(stage);	
		int result=Battle(player, enemy,stage);
		Sleep(2000);
		if(result==0)
			break;
		else
			stage++;
	}
	return 0;
}
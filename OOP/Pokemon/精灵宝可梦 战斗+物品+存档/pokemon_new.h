#include "pokemon.h"

class Pikachu : public Pokemon
{
public:
	Pikachu()
	{
		SetID(1);
		SetLevel(1);
		SetAttackPoint(10);
		SetDefendPoint(3);
		SetHitPoint(30);
		SetSkillPoint(20);
		SetSkillCost(2);
		SetSkillPower(20);
		SetName("Ƥ����");
	}
	void SkillInfo()
	{
		cout << "Ƥ����ʮ����أ�����" << endl;
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
		SetID(2);
		SetLevel(1);
		SetAttackPoint(13);
		SetDefendPoint(0);
		SetHitPoint(50);
		SetSkillPoint(20);
		SetSkillCost(2);
		SetSkillPower(20);
		SetName("С����");
	}
	void SkillInfo()
	{
		cout << "С������ɫ���棡����" << endl;
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
		SetID(3);
		SetLevel(1);
		SetAttackPoint(10);
		SetDefendPoint(8);
		SetHitPoint(40);
		SetSkillPoint(20);
		SetSkillCost(2);
		SetSkillPower(20);
		SetName("�����");
	}
	void SkillInfo()
	{
		cout << "�������ͷ鳣�����" << endl;
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
		SetID(4);
		SetLevel(1);
		SetAttackPoint(10);
		SetDefendPoint(8);
		SetHitPoint(40);
		SetSkillPoint(20);
		SetSkillCost(2);
		SetSkillPower(20);
		SetName("���ö�");
	}
	void SkillInfo()
	{
		cout << "���ö������ߣ�����" << endl;
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
		SetID(5);
		SetLevel(1);
		SetAttackPoint(10);
		SetDefendPoint(8);
		SetHitPoint(40);
		SetSkillPoint(20);
		SetSkillCost(2);
		SetSkillPower(20);
		SetName("��������");
	}
	void SkillInfo()
	{
		cout << "�������Ӽ��ܹ���������" << endl;
	}
	virtual void Upgrade()
	{
		SetAttackPoint(GetAttackPoint() + rand() % 3);
		SetHitPoint(GetHitPoint() + rand() % 3);
		SetDefendPoint(GetDefendPoint() + rand() % 2);
		SetSkillPoint(GetSkillPoint() + rand() % 2);
	}
};
class info
{
	int stage;
	Pokemon* enemy;
	Pokemon* player;
};
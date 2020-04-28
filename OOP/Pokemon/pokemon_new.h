#include "pokemon.h"

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
		SetName("Æ¤¿¨Çð");
	}
	void SkillInfo()
	{
		cout << "Æ¤¿¨ÇðÊ®Íò·üÌØ£¡£¡£¡" << endl;
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
		SetName("Ð¡»ðÁú");
	}
	void SkillInfo()
	{
		cout << "Ð¡»ðÁúÀ¶É«»ðÑæ£¡£¡£¡" << endl;
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
		SetName("½ÜÄá¹ê");
	}
	void SkillInfo()
	{
		cout << "½ÜÄá¹ê»ð¼ýÍ·é³£¡£¡£¡" << endl;
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
		SetName("Ñ×ÍÃ¶ù");
	}
	void SkillInfo()
	{
		cout << "Ñ×ÍÃ¶ù¶þ¶ÎÌß£¡£¡£¡" << endl;
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
		SetName("ÃîÍÜÖÖ×Ó");
	}
	void SkillInfo()
	{
		cout << "ÃîÍÜÖÖ×Ó¼¼ÄÜ¹¥»÷£¡£¡£¡" << endl;
	}
	virtual void Upgrade()
	{
		SetAttackPoint(GetAttackPoint() + rand() % 3);
		SetHitPoint(GetHitPoint() + rand() % 3);
		SetDefendPoint(GetDefendPoint() + rand() % 2);
		SetSkillPoint(GetSkillPoint() + rand() % 2);
	}
};
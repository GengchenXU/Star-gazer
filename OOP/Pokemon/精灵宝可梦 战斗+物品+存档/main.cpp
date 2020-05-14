#include "pokemon.h"
#include "pokemon_new.h"
#include <fstream>
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
void stage_save(ofstream& filestream, int stage)
{
	filestream << stage << endl;
}
int stage_load(ifstream& filestream)
{
	int stage;
	filestream >> stage;
	return stage;
}
int	Fight(Pokemon* attacker, Pokemon* defender,int stage)
{
	int damage;
	int select;
	int select_item;
	ext_print_line();
	cout << "1:普通攻击  2:使用技能  3:使用物品  4:保存进度  5:结束游戏" << endl;	//更新菜单
	while (true)
	{
		ext_print_line();
		cin >> select;
		if (select == 1 || select == 2  || select ==3 || select == 4 || select == 5)
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
					cout << "SP 点数不足！" << endl;
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
					cout << "10:返回上一级菜单" << endl;
					ext_print_line();
					cin >> select_item;
					if (select_item >= 0 && select_item < attacker->GetItemNumber())
					{
						cout << "使用物品" << attacker->GetItem(select_item)->GetName()<<endl;
						cout << attacker->GetItem(select_item)->statement(*defender) << endl;	//显示物品使用效果
						damage=attacker->GetItem(select_item)->function();	//执行功能
						if (attacker->GetItem(select_item)->GetNumber() == 0)	//如果物品用光了
						{
							for (int i = select_item; i < attacker->GetItemNumber(); i++)
							{
								attacker->GetItem(i) = (attacker->GetItem(i+1)); 	//调整物品数组，去掉用光的物品
							}
							attacker->SetItemNumber(attacker->GetItemNumber() - 1);
						}
						Sleep(2000);
						return damage;
					}
					else// if (select_item == 10)
					{
						cout << "1:普通攻击  2:使用技能  3:使用物品  4:保存进度  5：结束游戏" << endl;
						continue;
					}
				}
			}
			else if (select == 4)
			{
				ofstream save("save.dat");
				stage_save(save,stage);
				info_save(save, attacker);
				info_save(save, defender);
				save.close();
				cout << "保存成功！" << endl;
				cout << "1:普通攻击  2:使用技能  3:使用物品  4:保存进度  5：结束游戏" << endl;
				continue;
			}
			else if (select == 5)
			{
				return -10000;
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
		cout << "第" << stage << "关" << endl;
		cout << "战斗中...." << endl;

		cout << "  剩余技能点数： " << role->GetCurSkillPoint() << endl;
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
			int roletoPokemon = Fight(role, pokemon,stage);
			if (roletoPokemon == -10000) {
				return 0;
			}
			if (roletoPokemon < 0) { 
				cout << role->GetName() << "没有击中！" << endl;
			}
			else {
				pokemon->ChangeCurHitPoint(-roletoPokemon);
				cout << "你对" << pokemon->GetName() << "造成了" << roletoPokemon << "伤害" << endl;
				if (pokemon->GetCurHitPoint() <= 0)
				{
					cout << pokemon->GetName() << "被击败了" << endl << "恭喜过关！" << endl;
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
				cout << pokemon->GetName() << "没有击中！" << endl;
			}
			else {
				
				role->ChangeCurHitPoint(-pokemontoRole);
				cout << pokemon->GetName() << "对你造成了" << pokemontoRole << "伤害" << endl;
				if (role->GetCurHitPoint() <= 0)
				{
					cout << "很遗憾你被击败了" << endl << "游戏结束！" << endl;
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
void info_save(ofstream& filestream, Pokemon* pokemon)
{
	filestream << pokemon->GetID() << endl;
	filestream << pokemon->name << endl;
	filestream << pokemon->curHitPoint << endl;
	filestream << pokemon->hitPoint << endl;
	filestream << pokemon->curSkillPoint << endl;
	filestream << pokemon->skillPoint << endl;
	filestream << pokemon->attackPoint << endl;
	filestream << pokemon->defendPoint << endl;
	filestream << pokemon->experiencePoint << endl;
	filestream << pokemon->level << endl;
	filestream << pokemon->GetItemNumber() << endl;
	for (int i = 0; i < pokemon->GetItemNumber(); i++)
	{
		Item* item = pokemon->GetItem(i);
		filestream << item->GetID() << endl;
		filestream << item->GetName()<<endl;
		filestream << item->GetNumber() << endl;
	}
}

Pokemon* info_load (ifstream& filestream)
{
	Pokemon* pokemon;
	int pokemen_type;
	filestream >> pokemen_type;
	switch (pokemen_type)
	{
	case 1:
		pokemon = new Pikachu();
		break;
	case 2:
		pokemon = new FireDragon();
		break;
	case 3:
		pokemon = new Squirtle();
		break;
	case 4:
		pokemon = new FireRabbit();
		break;
	default:
		pokemon = new Frog();
		break;
	}
	filestream >> pokemon->name;
	filestream >> pokemon->curHitPoint;
	filestream >> pokemon->hitPoint;
	filestream >> pokemon->curSkillPoint;
	filestream >> pokemon->skillPoint;
	filestream >> pokemon->attackPoint;
	filestream >> pokemon->defendPoint;
	filestream >> pokemon->experiencePoint;
	filestream >> pokemon->level;
	int itemnumber = 0;
	filestream >> itemnumber;
	pokemon->SetItemNumber(itemnumber);
	
	for (int i = 0; i < itemnumber; i++)
	{
		int id = 0;
		filestream >> id;
		string name;
		filestream >> name;
		int number = 0;
		filestream >> number;
		switch (id)
		{
		case 1:
			pokemon->GetItem(i) = new HPpotion(number, pokemon);
			break;
		case 2:
			pokemon->GetItem(i) = new SPpotion(number, pokemon);
			break;
		case 3:
			pokemon->GetItem(i) = new Bomb(number, pokemon);
			break;
		}
		
	}
	return pokemon;
}

int main()
{
	ext_print_line();
	int userInput = 0;
	cout << "请输入你的选择："<< endl <<"1：开始新游戏" << endl <<
		"2：读取存档" << endl << "3: 游戏结束" << endl;
	Pokemon* player=NULL;
	while (true)
	{
		cin >> userInput;
		if (userInput == 1)
		{
			cout << "请选择你的小精灵：1:皮卡丘  2:小火龙 3：杰尼龟 4：炎兔儿 5：妙蛙种子" << endl;
			while (true)
			{
				cin >> userInput;
				if (userInput == 1 || userInput == 2 || userInput == 3 || userInput == 4 || userInput == 5)
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
			cout << "请为你的宝可梦取名字" << endl;
			string pokemonName;
			cin >> pokemonName;
			player->SetName(pokemonName);
			cout << "开始游戏！" << endl;
			Sleep(2000);
			int stage = 1;
			while (true)
			{
				Pokemon* enemy = PokemonGenertor(stage);
				int result = Battle(player, enemy, stage);
				Sleep(2000);
				if (result == 0)
					break;
				else
					stage++;
			}
		}
		else if (userInput == 2)
		{
			ifstream load("save.dat");
			int stage = stage_load(load);
			player=info_load(load);
			Pokemon* enemy = info_load(load);
			load.close();
			cout << "读取进度成功！开始游戏！" << endl;
			Sleep(2000);
			while (true)
			{
				enemy = PokemonGenertor(stage);
				int result = Battle(player, enemy, stage);
				Sleep(2000);
				if (result == 0)
				{
					userInput = 3;
					cout << "游戏结束！" << endl;
					return 0;
				}
				else
					stage++;
				delete enemy;
			}
		}
		else if (userInput == 3)
		{
			cout << "游戏结束！" << endl;
			return 0;
		}
		else
		{
			continue;
		}
		
	}
	
	
	return 0;
}

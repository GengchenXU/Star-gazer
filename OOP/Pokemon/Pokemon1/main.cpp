#include "pokemon.h"
#include "pokemon_new.h"
//#include "item.h"
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
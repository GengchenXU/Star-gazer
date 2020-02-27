
#include<stdio.h>

#include<string.h>

#include<windows.h>

#include<time.h>

#include<conio.h>

 

 

#define up 'w'

#define down 's'

#define left 'a'

#define right 'd'

#define stop 'p'

 

void welcome();               //55��ʼ����

void Finish();                //291��������

void creatgraph();            //69Χǽ��ӡ

void gotoxy(int x, int y);    //111�����ת����ΪX 0,1,2..

void gotoprint(int x, int y); //121��ת��ӡ

void gotodelete(int x, int y);//127��תɾ��

void creatfood();             //133ʳ�����

int ClickControl();           //157��ȡ�����ź�

int Judge();                  //270��Ϸ�����ж�

void MovingBody();      //172�ߵ��ƶ� 

void Eating();                //223�߳Ե�������Ĳ������쳤��

void ChangeBody(int a,int b); //245�ߵ�����任,��һ������ǰһ��STRUCT,a,bΪhead֮ǰ���� 

 

/*ȫ�ֱ��� + Ԥ����*/

typedef struct Snakes

{

	int x;

	int y;

	struct Snakes *next;

}snake;

 

snake *head,*tail;

 

struct Food

{

	int x;

	int y;

}food;

char name[20];

int score = 0;

char click = 1;

int speed;

 

/************************************************************/

 

int main()

{

	system("color 0B");

	welcome();

	creatgraph();

	creatfood();

	if (ClickControl() == 0) return 0;

	return 0;

}

 

/**********************************************************/

void welcome()

{

	gotoxy(15,10);

	printf("/**********************************************/");

	gotoxy(15, 20);

	printf("/**********************************************/");

	gotoxy(20, 13);

	printf("WELCOME TO THE GAME OF RETRO SNAKE");

	gotoxy(14, 16);

	printf("����Ӣ�����뷨�в����������ƶ���ͬ�ڳԵ��Լ���wasd����p��ͣ");

	gotoxy(20, 18);

	printf("PLEASE ENTER YOUR NAME:");

	scanf("%s", &name,10);

	system("cls");

}

/**********************************************************/

void creatgraph()             

{

	int i;

	for (i = 0; i<58; i += 2)//��ӡ���±߿�

	{

		gotoprint(i, 0);

		gotoprint(i, 26);

	}

	for (i = 1; i < 26; i++)

	{

		gotoprint(0, i);

		gotoprint(56, i);

	}

	gotoxy(63, 10);

	printf("hello %s,Welcome To Play",name);

	gotoxy(63, 15);

	printf("Your Score Is:%d    =���أ�= ",score);

	gotoxy(63, 20);

	printf("This Game Is Created By JOKER");

	head = (snake*)malloc(sizeof(snake));

	head->x = 16;

	head->y = 15;

	//gotoprint(head->x, head->y);

	tail = (snake*)malloc(sizeof(snake));

	snake *p = (snake*)malloc(sizeof(snake));

	snake *q = (snake*)malloc(sizeof(snake));

	p->x = 16;

	p->y = 16;

	q->x = 16;

	q->y = 17;

	head->next = p;

	p->next = q;

	q->next = tail;

	tail->next = NULL;	

}

/**********************************************************/

void gotoxy(int x, int y)

{

	COORD pos;

	HANDLE hOutput;

	pos.X = x;

	pos.Y = y;

	hOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleCursorPosition(hOutput, pos);

}

/**********************************************************/

void gotoprint(int x, int y)

{

	gotoxy(x, y);

	printf("��");

}

/**********************************************************/

void gotodelete(int x, int y)

{

	gotoxy(x, y);

	printf("  ");

}

/**********************************************************/

void creatfood()

{

	srand((int)time(NULL));

	lable:

	food.y = rand() % (25 - 1 + 1) + 1;

	food.x = rand() % (54 - 2 + 1) + 2;

	if (food.x % 2 != 0)

	{

		food.x = food.x+1;

	}

	snake *judge = head;

	while (1)  //�����ų������ظ�

	{

		if (judge->next == NULL) break;

		if (food.x == judge->x&&food.y == judge->y)

		{

			goto lable;

		}

		judge = judge->next;

	}

	gotoxy(food.x, food.y);

	printf("��");

}

/**********************************************************/

int ClickControl()

{

	char c;

	while (1)

	{

		if (Judge()==0) return 0;

		if (_kbhit())

		{

			click = _getch();

		}

		MovingBody();

		Eating();

	}

	return 1;

}

/**********************************************************/

void MovingBody()

{

	int count = 0;

	int a = head->x, b = head->y;

	snake *p = head;

	//ͨ������պ��ӡʵ�ֶ���Ч��

	while (1)

	{

		if (p->next == NULL) break;

		gotodelete(p->x, p->y);

		count++;

		p = p->next;

	}

	switch (click)

	{

		case up:

			head->y -= 1;

			ChangeBody(a,b);

			break;

		case down:

			head->y += 1;

			ChangeBody(a,b);

			break;

		case left:

			head->x -= 2;

			ChangeBody(a,b);

			break;

		case right:

			head->x += 2;

			ChangeBody(a,b);

			break;

		case stop:

			break;

	}

	p = head;

	while (1)

	{

		if (p->next == NULL) break;

		gotoprint(p->x, p->y);

		p = p->next;

	}

	p = head;

	gotoxy(0, 28);

	if (count <= 10) speed = 150;

	else if (count > 10 && count <= 20) speed = 100;

	else if (count > 20 && count <= 40) speed = 50;

	else speed = 10;

	Sleep(speed);

}

/**********************************************************/

void Eating()

{

	if (head->x == food.x&&head->y == food.y)

	{

		creatfood();

		snake *_new = (snake*)malloc(sizeof(snake));

		snake *p;

		p = head;

		while (1)

		{

			if (p->next->next == NULL) break;

			p = p->next;

		}

		p->next = _new;

		_new->next = tail;

		score += 10;

		gotoxy(77, 15);

		printf("%d", score);

	}

}

/**********************************************************/

void ChangeBody(int a,int b)

{

	snake *p = head->next;

	int mid1, mid2,_mid1,_mid2;

	mid1 = p->x;

	mid2 = p->y;

	while (1)

	{

		if (p->next->next == NULL) break;

		_mid1 = p->next->x;

		_mid2 = p->next->y;

		p->next->x = mid1;

		p->next->y = mid2;

		mid1 = _mid1;

		mid2 = _mid2; 

		p = p->next;

	}

	p = head->next;

	//if (p->next!= NULL)

	{

		p->x = a;

		p->y = b;

	}

}

/**********************************************************/

int Judge()

{

	if (head->x == 0|| head->x == 56 || head->y == 0 || head->y == 26)

	{

		Finish();

		return 0;

	}

	snake *p = head->next;

	while (1)

	{

		if (p->next == NULL) break;

		if (head->x == p->x&&head->y == p->y)

		{

			Finish();

			return 0;

		}

		p = p->next;

	}

	return 1;

}

/**********************************************************/

void Finish()

{

	system("cls");

	gotoxy(15, 10);

	printf("/**********************************************/");

	gotoxy(15, 20);

	printf("/**********************************************/");

	gotoxy(18, 14);

	printf("GAME   OVER      o(*������*)o");

	gotoxy(20, 16);

	printf("Your Score is %d    hiahiahia", score);

	gotoxy(18, 18);

	printf("������Ŷ��     ����Ŭ��O(��_��)O");

	gotoxy(0, 27);

	system("pause");

}

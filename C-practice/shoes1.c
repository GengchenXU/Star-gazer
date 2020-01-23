#include<stdio.h>
#define ADJUST 7.31
int main()
{
	const double SCALE= 0.33;
	double shoe,foot;
	scanf("%d",&shoe);
	foot=SCALE*shoe+ADJUST;
	printf("Shoe size (men's') foot length\n");
	printf("%15.2f inches\n",foot);
	return 0;
}

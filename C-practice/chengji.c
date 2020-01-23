#include <stdio.h>
int main()
{
	int g;
	scanf("%d",&g);
	if(g<=100&&g>=95){
		printf("%d\n",1);
	}
	if(g<95&&g>=90){
		printf("%d\n",2);
	}
	if(g<90&&g>=85){
		printf("%d\n",3);
	}
	if(g<85&&g>=80){
		printf("%d\n",4);
	}
	if(g<80&&g>=70){
		printf("%d\n",5);
	}
	if(g<70&&g>=60){
		printf("%d\n",6);
	}
	else if(g<60){
		printf("%d\n",7);
	}
			return 0;
}
		

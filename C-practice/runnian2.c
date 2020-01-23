#include<stdio.h>
int main()
{
	int year,leap;
	scanf("%d",&year);
	if(year%4==0)
	{
		if(year%100==0)
		{
			if(year%400==0)
				leap=1;
				else
					leap=0;
					}
					else
						leap=1;
	}
						else
							leap=0;
						if(leap==1)
								printf("Y");
								else
									printf("N");
																	return 0;
		
	}


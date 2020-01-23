#include<stdio.h>
int main(){
	int year,month,m,day,d,leap;
	scanf("%d-%d-%d",&year,&month,&day);
	if(year%4==0&&year%100!=0||year%400==0){
		leap=1;
	}
	else{
		leap=0;
	}
	if(month==2){
		if(leap=0&&day==28){
			day =1;
			month ++;

		}
		else if(leap=1&&day==29){
			day =1;
			month++;
		}
		else{
			day++;
		}
		}
if ((month == 1 || month == 3 || month == 5 || month == 7
	 || month == 8 || month == 10||month==12)){
	if(day==31){
		day=1;
		month++;
            }
	    else{
		    day++;
	    }

	}
	else if((month == 4 || month == 6 || month == 9 || month == 11)){
		if(day==30){
			day=1;month++;
		}
		else{
			day++;
		}

	}
	if(month>12){
		month=1;
		year++;
	}
	printf("%d-%02d-%02d",year,month,day);
	return 0;

}

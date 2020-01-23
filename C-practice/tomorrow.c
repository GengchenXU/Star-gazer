#include<stdio.h>
int main(){
	int year,month,day;
	char m,n;
	scanf("%d-%d-%d",&year,&month,&day);
	int leap=0;
	int special=0;
	if(year%4==0&&year%100!=0||year%400==0){
		leap =1;
}
if(month==2){

	if(leap==1&&day==29){
       month+=1;
       day=1;special=1;
        }
	if(leap==0&&day==28){
		month+=1;
	day=1;
	special=1;
}
}
if(0<month<=12){
	if(month==12&&day==31){
       year+=1;
       month=1;
       day=1;
       special=1;}
       if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10) && day == 31) {
			month += 1;
			day = 1;
			special = 1;
		}
		if ((month == 4 || month == 6 || month == 9 || month == 11) && day == 30) {
			month += 1;
			day = 1;
			special = 1;
		}
if (special == 0) {
			day += 1;
		}
}
printf("%d-%02d-%02d\n",year,month,day);
return 0;}

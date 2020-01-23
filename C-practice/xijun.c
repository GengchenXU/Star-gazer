#include<stdio.h>
int main()
{
int n;
int id[100];
double rate[100];
scanf("%d",&n);
for (int i=0;i<n;i++){
int initial,final;
scanf("%d %d %d",&id[i],&initial,&final);
rate[i]=(double)final/initial;
}
for(int i=0;i<n;i++){
	for (int j=0;j<n-i-1;j++){
		if(rate[j+1]>rate[j]){
			int templd=id[j];
			id[j]=id[j+1];
			id[j+1]=templd;
			double tmpRate=rate[j];
			rate[j]=rate[j+1];
			rate[j+1]=tmpRate;
		}
	}
}
double maxdiff=0;
int maxdiffIndex=0;
for (int i=0;i<n-1;i++){
	double diff=rate[i]-rate[i+1];
	if(maxdiff<diff){
		maxdiff=diff;
		maxdiffIndex=i;
}
}
printf("%d\n",maxdiff+1);
for(int i=maxdiffIndex;i>=0;i--){
	printf("%d\n",id[i]);}
printf("%d\n",n-maxdiffIndex-1);
for(int i=n-1;i>=maxdiffIndex+1;i--){
	printf("%d\n",id[i]);
}
return 0;	
}

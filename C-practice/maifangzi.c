#include<stdio.h>
int main()
{
	int i=1,n,k;
	double p=200;
		scanf("%d%d",&k,&n);
		double q=k;
     while(q<p&&i<=20)
           {
		   i++;
	 q=q+k;
	 p=p*(1+n*1.0/100);
	 }
	 if(i<=20)
	 {
		 printf("%d\n",i);
		 }
		 		 else{
					 
			 printf("Impossible\n");
			 }
       	 
	  	 
       
       return 0;	

	
}

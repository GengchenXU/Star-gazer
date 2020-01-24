#include<stdio.h> 
#include<math.h> 
int main(){    
int n,N,i,t=0,num;      
int a[10];   
 scanf("%d%d", &N,&num);   
  n = (int)log10(N) + 1;   
   for (i = 0; i < n; i++)
	 {   
	 a[i] = (int)(N / (int)pow(10, n - i - 1)) % 10;    
	 }    
	 for(i=0;i<n;i++){
	 	if(a[i]==3){
	 		t++;
		 }
	 } 
	 if(t==num&&N%19==0)
	 printf("YES");
	 else printf("NO");
	 return 0;}


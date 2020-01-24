#include<iostream>
using namespace std;
int main(){
int n;
while(cin>>n){
if (n%3!=0&&n%5!=0&&n%7!=0)   
     {printf("n\n");
     return 0;
     }
     else{
	     
   	    if (n%3==0) 
	    printf("3 ");  
            if (n%5==0) 
	    printf("5 ");  
            if (n%7==0) 
	    printf("7"); }
	    printf("\n");
	    }
	     
    return 0;  
}  




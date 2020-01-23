#include<stdio.h>  
int main ()  
{  
    int a[10]; 
        for(int i=0;i<5;i++)	 
		scanf("%d",&a[i]); 
		for (int i=0;i<5;i++) {
			
    if (a[i]%3!=0&&a[i]%5!=0&&a[i]%7!=0)   
     {printf("n\n");
     
     return 0;
     }  
    else{
	    if (a[i]%3==0) 
	    printf("3 ");  
            if (a[i]%5==0) 
	    printf("5 ");  
            if (a[i]%7==0) 
	    printf("7"); 
	    printf("\n");}
	    
	    } 
    return 0;  
}  


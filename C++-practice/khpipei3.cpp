#include <stdio.h>  
int main(){  
    int ch;  
    int count1=0;   //大括号{}
    int count2=0;   //中括号[] 
    int count3=0;   //小括号() 
    while((ch=getchar())!=	EOF){  
        if(ch=='{'){            //{}
            count1++;  
        }else if(ch=='['){      //[] 
            count2++;  
        }else if(ch=='('){      //()
            count3++;  
        } 
        if(ch=='}'&&count1==0){     //{}{}{}}
            printf("0");  
            return 0;  
        }else if(ch==']'&&count2==0){   //[[][]]
            printf("0");  
            return 0;  
        }else if(ch==')'&&count3==0){   //(()()())
            printf("0");  
            return 0;  
        }       

        if(ch=='}'&&count1!=0){  
            count1--;  
        }else if(ch==']'&&count2!=0){  
            count2--;  
        }else if(ch==')'&&count3!=0){  
            count3--;  
        }         
       
    }
    if(count1==0&&count2==0&&count3==0){          
        printf("1");
    }else{  
        printf("0\n");  
        
    }
    
    return 0;  
}


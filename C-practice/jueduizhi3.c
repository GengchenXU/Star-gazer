#include <stdio.h>
#include <stdlib.h>
int main(void) {
int min = 100;     
   int max = 0;        
   int i, j;
for(i = 0; i < 6; ++i) {

       scanf("%d", &j);
if(j% 2 == 0) {

           if(min > j)
               min = j; 
       }
else {
if(max < j)
 max = j;
       }
}
printf("%d\n",abs(max - min));
return 0;
}



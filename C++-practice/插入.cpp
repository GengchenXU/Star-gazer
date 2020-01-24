#include <stdio.h>
#include <string.h>
int main() {
   int i, n, max= 0;
   char a[10], b[10];
   char N=a[0];
        //while(1) {
        scanf("%s%s",a, b);
        n = strlen(a);
        for(i=1;i<n;i++){
            if(a[i]>N) {
            N=a[i];
            max=i;
        }
    }
    
        for(i=0;i<n;i++){
            printf("%c", a[i]);
            if(i == max)
            printf("%s", b);
    }
    //}
        return 0;
    }

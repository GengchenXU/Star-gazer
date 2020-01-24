#include <stdio.h>
int main()
{
    char p; 
    int move;
          scanf("%c%*c%d",&p,&move);
          //printf("%c%d",p,move);
        	if(p >= 'A' && p <= 'Z')
            {
                p = ((p-'A')+move)%26+'A';
            }
            else if(p >= 'a' && p <= 'z')
            {
                p = ((p-'a')+move)%26+'a';
            }
               printf("%c",p);
        printf("\n");
    return 0;
}
/*#include <stdio.h>
int main()
{
    char p; 
    int move;
          scanf("%c%*c%d",&p,&move);
          printf("%c%d\n",p,move);
        	if(p >= 'A' && p <= 'Z')
            {
                p = ((p-'A')+move)%26+'A';
            }
            else if(p >= 'a' && p <= 'z')
            {
                p = ((p-'a')+move)%26+'a';
            }
               printf("%c",p);
        printf("\n");
    return 0;
}*/


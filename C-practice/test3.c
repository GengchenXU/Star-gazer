#include <stdio.h>
int main()
{
    int k;
    scanf("%d", &k);
    int n1 = 0, n5 = 0, n10 = 0;
    for(int i=0;i<k;i++)
    {
        int n;
        scanf("%d", &n);
        if (n == 1) n1++;
        if (n == 5) n5++;
        if (n == 10) n10++;
    }
    printf("%d\n%d\n%d",n1,n5,n10);
    return 0;
}


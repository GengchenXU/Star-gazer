#include <stdio.h>
int main()
{
    int m, n, result = 0;
    scanf("%d %d", &m, &n);
    while (m <= n) {
        if (m % 2 == 1)
            result += m;
        m ++;
    }
    printf("%d\n", result);
    return 0;
}


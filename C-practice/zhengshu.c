#include <stdio.h>
int main()
{
    int n, a[1000];
    scanf("%d",&n);
    for (int i = 0; i < n; i ++)
        scanf("%d", &a[i]);
    for (int i = 0; i < n - 1; i ++)
        for (int j = 1; j < n - i; j ++)
        	if (a[j - 1] > a[j]) {
        		int temp = a[j];
        		a[j] = a[j - 1];
        		a[j - 1] = temp;
    		}
    for (int i = 0; i < n; i ++)
       printf("%d\n",a[i]);
    return 0;
}


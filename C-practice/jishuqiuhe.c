#include <stdio.h>
int main()
{
    int m, n, result = 0;
    scanf("%d,%d", &m, &n);
    if  (m <= n) 
    {
	    for (int i=m;i<=n;i++)
	    {
	    if(m%2==1)
		    result +=m;
		    m ++;
    }
    }
   else  if(n<=m)
    {
	    for(int i=n;i<=m;i++)
    {
if (n % 2 == 1)
            result += n;
        n ++;
    }
    }
    printf("%d\n", result);
    return 0;
}


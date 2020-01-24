#include<iostream>
using namespace std;
int main()
{
    char boy, x;
    int end = 0, num = 0;
    char a[55];
    scanf("%c", &boy);
    a[0] = 0;
    while (cin>>x)
    {
        if (x == boy)
        {
            end++;
            num++;
            a[end] = num;
        }
        else if(x!=boy)
        {
            num++;
            printf("%d %d\n", a[end], num);
            end--;
            if (end < 0) 
			return 0;
        }
    }
    return 0;
}

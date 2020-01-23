#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 在start与end中搜索匹配 
int fun(char *str, int start, int end)
{
    char chLeft;        // 左括号
    char chRight;       // 右括号
    while ((start <= end) && (str[start] != '\0'))
    {
        switch (str[start])
        {
        case '(':
            chLeft = str[start];
            chRight = ')';
            break;
        case '[':
            chLeft = str[start];
            chRight = ']';
            break;
        case '{':
            chLeft = str[start];
            chRight = '}';
            break;

        case ')':
        case ']':
        case '}':
            return 0;
        default:
            chLeft = '\0';
            break;
        }
        if (str[start] == chLeft)
        {
            int a = 1;
            int b = 0;
            int t = start + 1;
            while ((t <= end) && (str[t] != '\0')) // 搜索匹配的右括号 
            {
                if (str[t] == chLeft)
                    ++a;
                if (str[t] == chRight)
                    ++b;
                if (b>a)
                    return 0;
                if (a == b)      // 再对匹配括号里面的括号进行匹配 
                {
                    if (0 == fun(str, start + 1, t - 1)) // 递归调用 
                        return 0;
                    start = t;
                    break;
                }
                ++t;
            }
            if (a>b)
                return 0;
        }
        ++start;
    }
    return 1;
}

int main(void) {
    char str[1024];
    gets(str);
    int length = strlen(str);
    int i = fun(str, 0, length - 1);
    if (i == 1) {
        printf("1\n");
    }
    else {
        printf("0\n");
    }
    return 0;
}

#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
 
int main()
{
                char s1[85], s2[85];
                fgets(s1,85,stdin);
                fgets(s2,85,stdin);
                int a, i;
                for(i = 0; s1[i] != '\0'; i++)
                                if(s1[i] >= 'A' && s1[i] <= 'Z')
                                                s1[i] += 'a'-'A';
                for(i = 0; s2[i] != '\0'; i++)
                                if(s2[i] >= 'A' && s2[i] <= 'Z')
                                                s2[i] += 'a'-'A';
                if(strcmp(s1, s2) == 0)
                                cout << "=\n";
                else if(strcmp(s1, s2) > 0)
                                cout << ">\n";
                else
                                cout << "<\n";
                return 0;
}

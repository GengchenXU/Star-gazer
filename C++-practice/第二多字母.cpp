#include<iostream>
using namespace std;
struct charandnum {
    char ch;
    int count;
};
int main() {
    struct charandnum s[501], max, second;
    char a[501];
    cin>>a;
    int i, j, l = 0;
    for (i = 0; a[i] != '\0'; i++) {
        if ((a[i] >= 'A' && a[i] <= 'Z') || (a[i] >= 'a' && a[i] <= 'z')) {
            char temp;
            if (a[i] >= 'a')
                temp = a[i] - 32;
            else
                temp = a[i];
            bool found = false;
            for (j = 0; j< l; j++) {
                if (s[j].ch == temp) {
                    s[j].count++;
                    found = true;
                }
            }
            if (!found) {
                s[l].ch = temp;
                s[l].count = 1;
                l++;	//不管特殊符号
            }
        }
    }
    max = s[0];
    bool foundSecond = false;
    i = 0;
    while (!foundSecond) {
        if (s[i].count > max.count) {
            second = max;
            max = s[i];
            foundSecond = true;
        }
        else if (s[i].count < max.count) {
            second = s[i];
            foundSecond = true;
        }
        i++;
    }
   for (i; i<l - 1; i++) {
        if (s[i].count > max.count) {
            second = max;
           // max = s[i];
        } 
	else if (s[i].count < max.count && s[i].count > second.count) {
            second = s[i];
        }
   }
    printf("%c+%c:%d\n", second.ch, second.ch + 32, second.count);
    return 0;
}

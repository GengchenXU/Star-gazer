#include<cstdio>
#include<string>
#include<cstring>

using namespace std;

int ans_flag=1,len_1,len_2;

char word_1[81],word_2[81];

inline char char_(char char__)
{
    if(char__>='a'&&char__<='z') char__-=32;
    return char__;
}

int main()
{
    gets(word_1);
    gets(word_2);
    len_1=strlen(word_1),len_2=strlen(word_2);
/*    if(len_1<len_2)
    {
        printf("<\n");
        return 0;
    }
    else
    {
        if(len_1>len_2)
        {
            printf(">\n");
            return 0;
        }
    }*/
    for(int i=0;i<80;i++) word_1[i]=tolower(word_1[i]);
    for(int i=0;i<80;i++) word_2[i]=tolower(word_2[i]);
    ans_flag=strcmp(word_1,word_2);
    if(ans_flag>0) printf(">\n");
    else if(ans_flag<0) printf("<\n");
    else printf("=\n");
    return 0;
}

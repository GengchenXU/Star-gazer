#include <iostream>
using namespace std;
int main()
{
    int maxlen=0;//用来记录最长单词
    char s[80];
    cin.getline(s,80);
    int tmplen=0;//记录当前单词的长度
    int last=0;//记录最长单词结束时的下标
    for(int i=0;s[i]!='\0';i++)
    {
        if(s[i]=='.')//判断遇到句点的情况
        {
            if(maxlen<tmplen)
            {
                maxlen=tmplen;
                tmplen=0;
                last=i;
            }
            break;
        }
        else if(s[i]!=' ')
            tmplen++;
        else
        {
            if(maxlen<tmplen)
            {
                maxlen=tmplen;
                                last=i;
            }
	    tmplen=0;
        }
    }
    //上面这部分无法处理最后一个和句点连接的单词
    //输出结果
         for(int i=last-maxlen;i<last;i++)
        cout << s[i] ;
    return 0;
}


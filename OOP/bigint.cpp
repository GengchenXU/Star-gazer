
#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>
using namespace std;
class BigInt
{
private:
    string value;//保存所有位上的数字
    bool flag;//true表示正数，false表示负数，0默认为正数
    inline int compare(string s1, string s2)
    {
        if(s1.size() < s2.size())
            return -1;
        else if(s1.size() > s2.size())
            return 1;
        else
            return s1.compare(s2);
    }
public:
    BigInt():value("0"),flag(true){};
    BigInt(string str)
    {
        value = str;
        flag = true;
    }
public:
    friend ostream& operator << (ostream& os, const BigInt& bigInt);//重载输出操作符
    friend istream& operator >> (istream& is, BigInt& bigInt);//输入操作符重载
    friend BigInt operator+(const BigInt &lhs, const BigInt& rhs);//加法操作重载
    friend BigInt operator-(const BigInt &lhs, const BigInt& rhs);//减法操作重载
    friend BigInt operator*(const BigInt &lhs, const BigInt& rhs);//乘法操作重载
    BigInt operator/(const BigInt& rhs);//除法操作重载
};
ostream& operator << (ostream& os, const BigInt& bigInt)
{
    if (!bigInt.flag)
    {
        os << '-';
    }
    os << bigInt.value;
    return os;
}
istream& operator >> (istream& is, BigInt& bigInt)
{
    string str;
    is >> str;
    bigInt.value = str;
    bigInt.flag = true;
    return is;
}
/*
两个正整数相加
*/
BigInt operator+(const BigInt &lhs,const BigInt& rhs)
{
    BigInt ret;
    ret.flag = true;
    string value1(lhs.value), value2(rhs.value);
    //处理特殊情况
    if (value1 == "0")
    {
        ret.value = value2;
        return ret;
    }
    if (value2 == "0")
    {
        ret.value = value1;
        return ret;
    }
    //调整s1与s2的长度
    unsigned int i, size1, size2;
    size1 = value1.size();
    size2 = value2.size();
    if (size1 < size2)
    {
        for (i = 0; i < size2 - size1; i++)//在value1左边补零
        {
            value1 = "0" + value1;
        }
    }
    else
    {
        for (i = 0; i < size1 - size2; i++)//在value2左边补零
        {
            value2 = "0" + value2;
        }
    }
    //处理本质情况
    int n1, n2;
    n2 = 0;
    size1 = value1.size();
    string res = "";
    reverse(value1.begin(), value1.end());//颠倒字符串，以方便从低位算起计算
    reverse(value2.begin(), value2.end());
    for (i = 0; i < size1; i++)
    {
        n1 = (value1[i] - '0' + value2[i] - '0' + n2) % 10;//n1代表当前位的值
        n2 = (value1[i] - '0' + value2[i] - '0' + n2) / 10;//n2代表进位
        res = res + char(n1 + '0');
    }

    if (n2 == 1)
    {
        res = res + "1";
    }
    reverse(res.begin(), res.end());
ret.value = res;
    return ret;
}
/*
两个正整数相减
*/
BigInt operator-(const BigInt& lhs, const BigInt& rhs)
{
    BigInt ret;
    string value1(lhs.value), value2(rhs.value);
    //处理特殊情况
    if (value2 == "0")
    {
        ret.value = value1;
        ret.flag = true;
        return ret;
    }
    if (value1 == "0")
    {
        ret.value = value2;
        ret.flag = false;
        return ret;
    }
    //调整s1与s2的长度
    unsigned int i, size1, size2;
    size1 = value1.size();
    size2 = value2.size();
    if (size1 < size2)
    {
        for (i = 0; i < size2 - size1; i++)//在value1左边补零
        {
            value1 = "0" + value1;
        }
    }
    else
    {
        for (i = 0; i < size1 - size2; i++)//在value2左边补零
        {
            value2 = "0" + value2;
        }
    }
    //调整使‘-’号前边的数大于后边的数
    int t = value1.compare(value2);//相等返回0，str1<str2返回负数，str1>str2返回正数
    if (t < 0)
    {
        ret.flag = false;
        string tmp = value1;
        value1 = value2;
        value2 = tmp;      
    }
    else if (t == 0)
    {
        ret.value = "0";
        ret.flag = true;
        return ret;
    }
    else
    {
        ret.flag = true;
    }
    unsigned int j;
    size1 = value1.size();
    string res = "";
    reverse(value1.begin(), value1.end());//颠倒字符串，以方便从低位算起计算
    reverse(value2.begin(), value2.end());
    for (i = 0; i < size1; i++)
    {
        if (value1[i] < value2[i])//不足，向前借一维
        {
            j = 1;
            while(value1[i+j] == '0')
            {
                value1[i+j] = '9';
                j++;
            }
            value1[i+j] -= 1;
            res = res + char(value1[i] + ':' - value2[i]);
        } 
        else
        {
            res = res + char(value1[i] - value2[i] + '0');
        }
    }
    reverse(res.begin(), res.end());
    res.erase(0, res.find_first_not_of('0'));//去掉前导零
    ret.value = res;   
    return ret;
}
/*
两个正整数相乘
*/
BigInt operator*(const BigInt&lhs, const BigInt& rhs)
{
    BigInt ret;
    string value1(lhs.value), value2(rhs.value);
    //处理特殊情况
    if (value1 == "0" || value2 == "0")
    {
        ret.value = "0";
        ret.flag = true;
        return ret;
    }
    unsigned int size1, size2;
    size1 = value1.size();
    size2 = value2.size();
    string temp;
    BigInt res, itemp;
    if (value1 < value2)
    {
        temp = value1; 
        value1 = value2; 
        value2 = temp;
        size1 = value1.size(); 
        size2 = value2.size();
    }
    int i, j, n1, n2, n3, t;
    reverse(value1.begin(), value1.end());//颠倒字符串
    reverse(value2.begin(), value2.end());
    for (i = 0; i < size2; i++)
    {
        temp = "";
        n1 = n2 = n3 = 0;
        for (j = 0; j < i; j++)
        {
            temp = temp + "0";
        }
        n3 = value2[i] - '0';
        for (j = 0; j < size1; j++)
        {
            t = (n3*(value1[j] - '0') + n2);
            n1 = t % 10;//n1记录当前位置的值
            n2 = t / 10;//n2记录进位的值
            temp = temp + char(n1 + '0');
        }
        if (n2)
        {
            temp = temp + char(n2 + '0');
        }
        reverse(temp.begin(), temp.end());
        itemp.value = temp;
        res = res + itemp;
    }
    ret = res;
    return ret;
}
/*
两个正整数相除
*/
BigInt BigInt:: operator/(const BigInt& rhs)
{
    BigInt ret;
    string value1(value), value2(rhs.value);
    string quotient;
    //处理特殊情况
    if(value2 == "0")
    {
        ret.value = "error";//输出错误
        ret.flag = true;
        return ret;
    }
    if(value1 == "0")
    {
        ret.value = "0";
        ret.flag = true;
        return ret;
    }
    if(compare(value1, value2) < 0)
    {
        ret.value = "0";
        ret.flag = true;
        return ret;
    }
    else if(compare(value1, value2) == 0)
    {
        ret.value = "1";
        ret.flag = true;
        return ret;
    }
    else
    {
        string temp;
        unsigned int size1, size2;
        size1 = value1.size();
        size2 = value2.size();
        int i;
        if(size2 > 1) temp.append(value1, 0, size2-1);
        for(i = size2 - 1; i < size1; i++)
        {
            temp = temp + value1[i];
            //试商
            for(char c = '9'; c >= '0'; c--)
            {
                BigInt t = (BigInt)value2 * (BigInt)string(1, c);
                BigInt s = (BigInt)temp - t;
                if(s.flag == true)
                {
                    temp = s.value;
                    quotient = quotient + c;
                    break;
                }
            }
        }
    }
    //去除前导零
    quotient.erase(0, quotient.find_first_not_of('0'));
    ret.value = quotient;
    ret.flag = true;
    return ret;
}
int main()
{
    BigInt a,b,result;
    char op;
    cin >> a >> op >> b;
    switch(op)
    {
        case '+':result = a + b; break;
        case '-':result = a - b; break;
        case '*':result = a * b; break;
        case '/':result = a / b; break;
        default:break;
    }
    cout << result << endl;
    return 0;
}

#include <iostream>
#include<cstring>
using namespace std;
int countnum(int **city, int numsSize) 
{
    int a[numsSize+1]={0};
    int temp;

    for (int i = 1; i < numsSize + 1; i++)
    {
      int counts = 0;
        for (int j = 1; j < numsSize + 1; j++)
        {
            if (city[i][j] == 1)
            {
                counts++;
                temp = j;
            }
        }
        if (counts > 1)
            continue;
        else
        {
            a[temp] = 1;
        }
    }
     int counts1 = 0;
    for (int i = 1; i < numsSize + 1; i++)
        if (a[i] == 1)
            counts1++;
    return counts1;
}

 
int CountCitys(int numsSize) 
{
    int **City = new int *[numsSize + 1];
    for (int i = 0; i < numsSize + 1; i++)
        City[i] = new int[numsSize + 1];
    //int City[100][100];
    memset(City,0,sizeof(City));

    int head_num;
    bool Ishead = true;
    while (1)
        {
            char temp;
            temp = cin.get();
            if (temp == '\n')
            {
                Ishead = true;
                continue;
            }
            if (temp > 48 && temp <= 57)
            {
                if (!Ishead)
                {
                    City[head_num][temp - 48] = 1;
                    City[temp - 48][head_num] = 1;
                    continue;
                }
                else if (Ishead)
                {
                    head_num = temp - 48;
                    Ishead = false;
                }
            }
            if (temp == '0')
                break;
        }
    int result = countnum(City, numsSize);

    return result;
}
 
int main()
{
    int n = 1;
    int count = 0;
    while (n != 0)
    {
        cin >> n;
        if (n != 0)
            count++;
        getchar();
        if (n == 0)
            break;
        int result;
        result = CountCitys(n);
        cout << result << "\n";
    }
    return 0;
}
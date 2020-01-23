#include<stido.h>
void Swap(int*number1,int*number2)
{
        int tmp=(*number1);
        (*number1)=(*number2);
        (*number2)=tmp;
}

int main()
{
        int x=2;
        int y=3;
        printf("%d,%d\n",x,y);
        Swap(&x,&y);
        printf("%d,%d\n",x,y);
        return 0;
}

include<iostream>
using namespace std;

int main(){

    int n;
    cin >> n;
    int sumn = 0; int sumd = 1;
        while (n--){
        int num, deno;
        char slash;//输入/的
        cin >> num >> slash >> deno;

        //先相加 a/b+c/d =(a*d+b*c)/(b*d)
        sumn = sumn*deno + num*sumd;
        sumd = sumd*deno;
    }
    //后约分
    //先求最大公约数gcd,这里用的是欧几里得法
    int a = sumd, b = sumn, c;
    while (a != 0){
        c = a;
        a = b%a; 
        b = c;
    }
    int gcd = b;
    //分子分母同时除以gcb约分
    sumd = sumd / gcd;
    sumn = sumn / gcd;

    if (sumd > 1)
        cout << sumn << "/" << sumd << endl;
    else
        cout << sumn << endl;
	       return 0;
}


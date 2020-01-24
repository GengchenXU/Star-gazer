#include<iostream>
using namespace std;
int i=0;
char word[500];

int reverse() {
	char m = word[i];
	i++;
	if (m == ' ') {
		//如果遇到的是空格，那就返回一个值，来表示是空格
		return 1;
	}
	if (m !=' ' && m != '\0') {//特别注意是右斜杠，否则会出错
		reverse();
		cout << m;
		return 1;//这里的返回值也需要为1，为什么？
		//因为递归的过程，相当于层层嵌套，如果这里没有return或者return=0，那么当这个函数结束返回时，就会少一次空格的记录。
	}
	
}
 
int main() {
	cin.getline(word, 500);
	while (word[i] != '\0') {
		if (reverse() == 1) {
			cout << ' ';//如果第二个为return 0，结果会少一个空格
		}
	}
 
	return 0;
}


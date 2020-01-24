#include<iostream>
#include <cstring>
using namespace std;
char input[101];
char output[101];
bool in=false;
int check(bool in,int s) {	
	for (int i = s; i < 100; i++) {
		if (output[i] == ')') {
			if (in == false) {
				output[i] = '?';
							}
			if (in == true) {
				output[i] = ' ';
				output[s-1] = ' ';
				return 0;
			}
		}
		if (output[i] == '(') { 
			output[i] = '$';
			check(true, i + 1);
		}
		if (output[i] != '('&&output[i] != ')'&&output[i] != '?'&&output[i] != '$') {
			if (output[i] == '\0' || i == 99)
				return 0;
			else
				output[i] = ' ';
		}
	}
}
int main(){
	while (cin.getline(input, 101)) {
		memcpy(output, input, sizeof(input));
		check(false, 0);
		for (int i = 0; i < 100; i++) {
			if (input[i] != '\0') {
				cout << input[i];
				if (i == 99) {
					cout << endl;
					break;
				}
			}
			else {
				cout << endl;
				break;
			}
		}
		for (int i = 0; i < 100; i++) {
			if (output[i] != '\0') {
				cout << output[i];
				if (i == 99) {
					cout << endl;
					break;
				}
			}
			else {
				cout << endl;
				break;
			}
		}
	}
	return 0;
}


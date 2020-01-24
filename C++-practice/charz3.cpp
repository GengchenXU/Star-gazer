# include <iostream>
#include<cstring>
using namespace std;
int main() {
	int n=0;
	char str[14] = { 0 };
	char substr[4] = { 0 };
	while (cin >> str >> substr) {
		int i = 0, posMax = 0;
		char strMax = 0;
			while (str[i]) { n = strlen(str);
			if (str[i] > strMax) {
				posMax = i;
				strMax = str[i];
			}
			i++;
		}
		
		 for(i=0;i<n;i++){
    		printf("%c", str[i]);

    		if(i == posMax)

    		printf("%s",substr);
    

 
	}
	printf("\n");
	}
	return 0;

}

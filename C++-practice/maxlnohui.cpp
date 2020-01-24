#include <iostream>
#include <sstream>
#include <string>
#include<cstring>
using namespace std;
int main () {
    string s;
    char t[600];
    int b;
    fgets(t,80,stdin);
 b =strlen(t);
  t[b-1]='\0';
    s=t;
    s[s.size()-1]=' ';    
    stringstream ss(s);
    string a;
    int l=0;
    while (ss>>s) 
	    if (s.size()>l) {
		    l=s.size();a=s;
		    }
    cout<<a<<endl;
    return 0;
}

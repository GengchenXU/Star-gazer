#include <iostream>
#include <cstring>
#include <stack>
using namespace std;
 
//判断括号是否匹配
bool isMatch(string s) {
    stack<char> st;
    int len = s.size();
    for (int i = 0; i < len; i++) {
        if (s[i] == '{') {
 
            st.push('{');
 
        } else if (s[i] == '[') {
 
            st.push('[');
 
        } else if (s[i] == '(') {
 
            st.push('(');
 
        } else if (s[i] == '}') {
 
            if (st.empty()) {
                return false;
            } else {
                char ch = st.top();
                st.pop();
                if (ch != '{') {
                    return false;
                }
            }
 
        } else if (s[i] == ']') {
            if (st.empty()) {
                return false;
            } else {
                char ch = st.top();
                st.pop();
                if (ch != '[') {
                    return false;
                }
            }
 
        } else if (s[i] == ')') {
            if (st.empty()) {
                return false;
            } else {
                char ch = st.top();
                st.pop();
                if (ch != '(') {
                    return false;
                }
            }
 
        } else {
            //continue;
        }
    }
 
    if (st.size() != 0) {
        return false;
    }
    return true;
}
 
int main() {
 
    string s;
    getline(cin, s);
    if (isMatch(s)) {
        cout << "1" << endl;
    } else {
        cout << "0" << endl;
    }
 
    return 0;
}


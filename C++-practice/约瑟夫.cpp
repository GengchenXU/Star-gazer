/*
 * @Description: 
 * @Sample Intput: 
 * @Output: 
 * @Author: GengchenXu
 * @CreateDate: 2020-11-04 10:59:14
 * @LastEditTime: 2020-11-04 10:59:23
 */
#include<iostream>
using namespace std;
int succedent[300];
int precedent[300];
int main() {
	int n, m;
	while (true) {
		cin >> n >> m;
        if (n == 0 && m == 0)
			break;
        for (int i = 0; i < n - 1; i++) {
			succedent[i] = i + 1;
			precedent[i + 1] = i;
		}
        succedent[n - 1] = 0;
        precedent[0] = n - 1;
        int current = 0;
        while (1) {
			for (int count = 0; count < m-1; count++)
				current = succedent[current];
			int pre = precedent[current];
			int suc = succedent[current];
            succedent[pre] = suc;
			precedent[suc] = pre;
			if (pre == suc) {
				cout << pre+1 << endl;
				break;
			}
			current = suc;
		}
	}
	return 0;
}
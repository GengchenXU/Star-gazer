/*ÿ����ֱ��ĸ������ߣ��ȵ��ļ�Ϊ���*/
#include <iostream>
using namespace std;
struct dot{
 	int x;
	int y;};
char s[100][100];
int walk(char s[][100], int start, int si, int sj, int ti, int tj, int m, int n) {
	dot d[1000];//�����߹��ĵ�
	int num = 0, flag[101][101] = { 0 }, e = 1, steps = 0;//num��¼������ĵ�����flag��������ĵ��ǣ��´�������ĩβ�㣬steps��¼����
	d[0].x = si; d[0].y = sj;//�������
	flag[si][sj] = 1;//�߹����
	while (1) {
		int i = 0;//�˴����������
		start = num + 1;//�´���������ʼ��
		while (i<e) {
			if ((s[d[i].x + 1][d[i].y] != '#') && (d[i].x + 1 < m) && (d[i].x + 1 != ti || d[i].y != tj)) {//��������
				if (flag[d[i].x + 1][d[i].y] == 0) {
					++num;
					d[num].x = d[i].x + 1; 
					d[num].y = d[i].y;
					flag[d[i].x + 1][d[i].y] = 1;
				}
			}
			else if (!(d[i].x + 1 != ti || d[i].y != tj)) {//�ҵ��˳���
				return steps;
			}
			if ((s[d[i].x - 1][d[i].y] != '#') && (d[i].x - 1 >= 0) && (d[i].x - 1 != ti || d[i].y != tj)) {//��������
				if (flag[d[i].x - 1][d[i].y] == 0) { 
				++num; 
				d[num].x = d[i].x - 1; 
				d[num].y = d[i].y; 
				flag[d[i].x - 1][d[i].y] = 1; 
				}
			}
			else if (!(d[i].x - 1 != ti || d[i].y != tj)) {//�ҵ��˳���
				return steps;
			}
			if ((s[d[i].x][d[i].y + 1]) != '#' && (d[i].y + 1 < n) && (d[i].x != ti || d[i].y + 1 != tj)) {//��������
				if (flag[d[i].x][d[i].y + 1] == 0) { 
				++num; d[num].x = d[i].x;
				d[num].y = d[i].y + 1; 
				flag[d[i].x][d[i].y + 1] = 1; 
				}
			}
			else if (!(d[i].x != ti || d[i].y + 1 != tj)) {//�ҵ��˳���
				return steps;
			}
			if ((s[d[i].x][d[i].y - 1] != '#') && (d[i].y - 1 >= 0) && (d[i].x != ti || d[i].y - 1 != tj)) {//��������
				if (flag[d[i].x][d[i].y - 1] == 0) {
					++num; 
					d[num].x = d[i].x;
					d[num].y = d[i].y - 1; 
					flag[d[i].x][d[i].y - 1] = 1; 
				}
			}
			else if (!(d[i].x != ti || d[i].y - 1 != tj)) {//�ҵ��˳���
				return steps;
			}
			i++;
		}
		steps++;//һ������������������1
		e = num + 1;
	}
}
int main() {
	int m, n, si, sj, ti, tj;
	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> s[i][j];
			if (s[i][j] == 'S') { 
			si = i; sj = j; 
			}
			if (s[i][j] == 'T') { 
			ti = i; tj = j; 
			}
		}
	}
	int steps;
	/*if (m == 1 && n == 1) {
		cout << 0 << endl; 
		return 0;
	}
	else */steps = walk(s, 0, si, sj, ti, tj, m, n);
	cout << steps + 1 << endl;
	return 0;
}


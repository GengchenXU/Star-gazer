/*每个点分别朝四个方向走，先到的即为最短*/
#include <iostream>
using namespace std;
struct dot{
 	int x;
	int y;};
char s[100][100];
int walk(char s[][100], int start, int si, int sj, int ti, int tj, int m, int n) {
	dot d[1000];//收入走过的点
	int num = 0, flag[101][101] = { 0 }, e = 1, steps = 0;//num记录已收入的点数，flag给已收入的点标记，下次搜索的末尾点，steps记录步数
	d[0].x = si; d[0].y = sj;//收入起点
	flag[si][sj] = 1;//走过标记
	while (1) {
		int i = 0;//此次搜索的起点
		start = num + 1;//下次搜索的起始点
		while (i<e) {
			if ((s[d[i].x + 1][d[i].y] != '#') && (d[i].x + 1 < m) && (d[i].x + 1 != ti || d[i].y != tj)) {//向下搜索
				if (flag[d[i].x + 1][d[i].y] == 0) {
					++num;
					d[num].x = d[i].x + 1; 
					d[num].y = d[i].y;
					flag[d[i].x + 1][d[i].y] = 1;
				}
			}
			else if (!(d[i].x + 1 != ti || d[i].y != tj)) {//找到了出口
				return steps;
			}
			if ((s[d[i].x - 1][d[i].y] != '#') && (d[i].x - 1 >= 0) && (d[i].x - 1 != ti || d[i].y != tj)) {//向上搜索
				if (flag[d[i].x - 1][d[i].y] == 0) { 
				++num; 
				d[num].x = d[i].x - 1; 
				d[num].y = d[i].y; 
				flag[d[i].x - 1][d[i].y] = 1; 
				}
			}
			else if (!(d[i].x - 1 != ti || d[i].y != tj)) {//找到了出口
				return steps;
			}
			if ((s[d[i].x][d[i].y + 1]) != '#' && (d[i].y + 1 < n) && (d[i].x != ti || d[i].y + 1 != tj)) {//向右搜索
				if (flag[d[i].x][d[i].y + 1] == 0) { 
				++num; d[num].x = d[i].x;
				d[num].y = d[i].y + 1; 
				flag[d[i].x][d[i].y + 1] = 1; 
				}
			}
			else if (!(d[i].x != ti || d[i].y + 1 != tj)) {//找到了出口
				return steps;
			}
			if ((s[d[i].x][d[i].y - 1] != '#') && (d[i].y - 1 >= 0) && (d[i].x != ti || d[i].y - 1 != tj)) {//向左搜索
				if (flag[d[i].x][d[i].y - 1] == 0) {
					++num; 
					d[num].x = d[i].x;
					d[num].y = d[i].y - 1; 
					flag[d[i].x][d[i].y - 1] = 1; 
				}
			}
			else if (!(d[i].x != ti || d[i].y - 1 != tj)) {//找到了出口
				return steps;
			}
			i++;
		}
		steps++;//一次搜索结束，步数加1
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


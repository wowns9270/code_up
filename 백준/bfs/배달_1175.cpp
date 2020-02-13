#include<bits/stdc++.h>
using namespace std;
#define inf 899999
int n, m,st,ed;
int e[2][2];

vector<string> arr;

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int visit[5][51][51][2][2];

struct edge {
	int dir;
	int x;
	int y;
	int c1;
	int c2;
};




int main() {
	cin >> n >> m;
	arr.resize(n);

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int a = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 'S') {
				st = i, ed = j;
				arr[i][j] = '.';
			}
			if (arr[i][j] == 'C') {
				e[a][0] = i, e[a++][1] = j;
			}
		}
	}

	memset(visit, -1, sizeof(visit));
	queue<edge> q;
	q.push({ 4,st,ed,0,0 });
	visit[4][st][ed][0][0] = 0;

	while (!q.empty()) {

		int d = q.front().dir;
		int x = q.front().x;
		int y = q.front().y;
		int cc1 = q.front().c1;
		int cc2 = q.front().c2;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ux = x + dx[i];
			int uy = y + dy[i];

			if (ux < 0 || uy < 0 || ux >= n || uy >= m || arr[ux][uy] == '#')continue;

			if (d == i) continue;

			if (arr[ux][uy] == '.') {
				if (visit[i][ux][uy][cc1][cc2] == -1) {
				visit[i][ux][uy][cc1][cc2] = visit[d][x][y][cc1][cc2] + 1;
				q.push({ i,ux,uy,cc1,cc2 });
				}
			}
			else {
				if (ux == e[0][0] && uy == e[0][1]) {
					if (visit[i][ux][uy][1][cc2] == -1) {
						visit[i][ux][uy][1][cc2] = visit[d][x][y][cc1][cc2] + 1;
						q.push({ i,ux,uy,1,cc2 });
					}
				}
				if (ux == e[1][0] && uy == e[1][1]) {
					if (visit[i][ux][uy][cc1][1] == -1) {
						visit[i][ux][uy][cc1][1] = visit[d][x][y][cc1][cc2] + 1;
						q.push({ i,ux,uy,cc1,1 });
					}
				}
			}
		}
	}
	int ret = inf;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j <= 1; j++) {
			if (visit[i][e[j][0]][e[j][1]][1][1] == -1) {
				continue;
			}

			ret = min(ret, visit[i][e[j][0]][e[j][1]][1][1]);
		}
	}
	if (ret >= inf) cout << -1;
	else cout << ret;
	return 0;
}
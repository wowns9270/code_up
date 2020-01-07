#include<bits/stdc++.h>
using namespace std;
ifstream in("go.inp");
ofstream out("go.out");
char chess[20][20];
int n;
int bw[2], ir_bw[2], r_bw[2];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int ret; //점의 개수
void bfs(int x, int y) {
	chess[x][y] = 1;
	queue<pair<int, int> > q;
	q.push(make_pair(x, y));
	while (!q.empty()) {
		int nx = q.front().first;
		int ny = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int kx = nx + dx[i];
			int ky = ny + dy[i];
			if (kx >= 0 && ky >= 0 && kx < n && ky < n) {
				if (chess[kx][ky] == 'B')bw[0]++;
				else if (chess[kx][ky] == 'W')bw[1]++;
				else if (chess[kx][ky] == '.') {
					ret++;
					chess[kx][ky] = 1;
					q.push(make_pair(kx, ky));
				}
			}
		}
	}
}
int main() {
	in >> n;
	for (int i = 0; i < n; i++) {
		in >> chess[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (chess[i][j] == '.') {
				ret = 1;
				bw[0] = 0, bw[1] = 0;
				bfs(i, j);
				if (bw[0] > 0 && bw[1] > 0) continue;
				else if (bw[0] > 0) r_bw[0] += ret;
				else r_bw[1] += ret;
			}
		}
	}
	out << r_bw[0] << " " << r_bw[1];
	return 0;
}
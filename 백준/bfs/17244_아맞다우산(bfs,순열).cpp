#include<bits/stdc++.h>
using namespace std;

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int n, m, st_x, st_y, ed_x, ed_y, ret = 19999999;
char arr[51][51];
vector<pair<int, int>> point;

int bfs(int x, int y, int k_x, int k_y) {
	int visit[51][51];
	memset(visit, -1, sizeof(visit));
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	visit[x][y] = 0;

	while (!q.empty()) {
		int ux = q.front().first;
		int uy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = ux + dx[i];
			int ny = uy + dy[i];

			if (arr[nx][ny] != '#' && visit[nx][ny] == -1) {
				visit[nx][ny] = visit[ux][uy] + 1;
				q.push(make_pair(nx, ny));
			}
		}
	}

	return visit[k_x][k_y];

}
int main() {
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'X') { point.push_back(make_pair(i, j)); }
			if (arr[i][j] == 'S') { st_x = i, st_y = j; }
			if (arr[i][j] == 'E') { ed_x = i, ed_y = j; }
		}
	}
	sort(point.begin(), point.end());
	do {
		int sum = 0;
		int st = st_x, ed = st_y;
		for (int i = 0; i < point.size(); i++) {
			int temp = bfs(st, ed, point[i].first, point[i].second);
			sum += temp;
			st = point[i].first;
			ed = point[i].second;
		}
		int temp = bfs(st, ed, ed_x, ed_y);
		sum += temp;

		ret = min(ret, sum);

	} while (next_permutation(point.begin(), point.end()));

	cout << ret;
	return 0;
}
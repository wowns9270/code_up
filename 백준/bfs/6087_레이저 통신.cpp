#include<iostream>
#include<queue>
using namespace std;

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };


char arr[103][103];
int arr_ret[103][103];
bool visit[103][103];
int n, m;

vector<pair<int, int>> c;

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	arr_ret[x][y] = 0;
	visit[x][y] = true;

	while (!q.empty()) {
		int nx = q.front().first;
		int ny = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ux = nx + dx[i];
			int uy = ny + dy[i];


			while (1) {
				if (ux < 0 || uy < 0 || ux >= n || uy >= m) break;
				if (arr[ux][uy] == '*') break;

				if (visit[ux][uy] == false) {

					visit[ux][uy] = true;
					arr_ret[ux][uy] = arr_ret[nx][ny] + 1;
					q.push(make_pair(ux, uy));
				}
				ux += dx[i];
				uy += dy[i];
			}
		}
	}
}
//각 방향으로 다 바꿔버리면 되는 문제 였는데.
//돌이 아니라 숫자가 있으면 지나가야하는데 안지나가게 해서 애먹었다, ㅜㅜ

int main() {
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'C') {
				c.push_back(make_pair(i, j));
			}
		}
	}
	bfs(c[0].first, c[0].second);


	cout << arr_ret[c[1].first][c[1].second] - 1 << "\n";
	return 0;
}
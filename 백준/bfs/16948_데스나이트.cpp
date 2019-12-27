#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

int arr[200][200];
int n;
int dx[] = { -2,-2,0,0,2,2 };
int dy[] = { -1,1,-2,2,-1,1 };


void bfs(int x, int y) {
	queue<pair<int, int>>q;
	q.push(make_pair(x, y));
	arr[x][y] = 0;
	while (!q.empty()) {
		int ux = q.front().first;
		int uy = q.front().second;
		q.pop();

		for (int i = 0; i < 6; i++) {
			int nx = ux + dx[i];
			int ny = uy + dy[i];

			if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
				if (arr[nx][ny] == -1) {
					arr[nx][ny] = arr[ux][uy] + 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
}
int main() {
	cin >> n;
	int a, b, c, d; cin >> a >> b >> c >> d;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arr[i][j] = -1;
		}
	}
	bfs(a, b);
	cout << arr[c][d];
	return 0;
}
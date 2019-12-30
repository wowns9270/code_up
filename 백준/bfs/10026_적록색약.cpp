#include<bits/stdc++.h>
using namespace std;

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

char arr[101][101];
int visit1[101][101];
int visit2[101][101];
int cnt1, cnt2;
int n;

void bfs1(int x, int y) {
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	visit1[x][y] = 0;

	while (!q.empty()) {
		int ux = q.front().first;
		int uy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = ux + dx[i];
			int ny = uy + dy[i];

			if (nx < 0 || uy < 0 || ux >= n || uy >= n) continue;

			if (arr[ux][uy] == arr[nx][ny] && visit1[nx][ny] == -1) {
				visit1[nx][ny] = 0;
				q.push(make_pair(nx, ny));
			}
		}
	}
}
void bfs2(int x, int y) {
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	visit2[x][y] = 0;

	while (!q.empty()) {
		int ux = q.front().first;
		int uy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = ux + dx[i];
			int ny = uy + dy[i];

			if (nx < 0 || uy < 0 || ux >= n || uy >= n) continue;
			if (arr[ux][uy] == 'R' || arr[ux][uy] == 'G') {

				if (arr[nx][ny] == 'G' || arr[nx][ny] == 'R') {
					if (visit2[nx][ny] == -1) {
						visit2[nx][ny] = 0;
						q.push(make_pair(nx, ny));
					}
				}
			}
			else {
				if (arr[ux][uy] == arr[nx][ny] && visit2[nx][ny] == -1) {
					visit2[nx][ny] = 0;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
}


int main() {
	memset(visit1, -1, sizeof(visit1));
	memset(visit2, -1, sizeof(visit2));

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visit1[i][j] == -1) {
				cnt1++;
				bfs1(i, j);
			}
			if (visit2[i][j] == -1) {
				cnt2++;
				bfs2(i, j);
			}
		}
	}
	cout << cnt1 << " " << cnt2;
	return 0;
}
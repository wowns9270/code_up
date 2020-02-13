#include<bits/stdc++.h>
using namespace std;
int arr[1001][1001];
int visit[1001][1001];
int n, m, h, w, sr, sc, fr, fc;
int dx[] = { 1,-1,0,0 }; // 남 북 동 서
int dy[] = { 0,0,1,-1 };

//처음에는 이동하는 직사각형을 모두 검사했는데 시간초과가 났다.
//이동하는 방향으로 한 라인만 검사하면 통과된다ㅡ.
bool check(int x, int y , int dir) {

	if (x<1 || y<1 || x>n || y>m) return false;

	if (x + h -1 > n || y + w - 1  > m) return false;

	
	if (dir == 0) { // 남
		for (int i = y; i < y + w; i++) {
			if (arr[x + h - 1][i] == 1) return false;
		}
	}
	else if (dir == 1) {
		for (int i = y; i < y + w; i++) {
			if (arr[x][i] == 1) return false;
		}
	}
	else if (dir == 2) { // 동
		for (int i = x; i < x + h; i++) {
			if (arr[i][y + w - 1] == 1) return false;
		}
	}
	else {
		for (int i = x; i < x + h; i++) {
			if (arr[i][y] == 1) return false;
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(0), cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
		}
	}
	cin >> h >> w >> sr >> sc >> fr >> fc;
	memset(visit, -1, sizeof(visit));
	visit[sr][sc] = 0;
	queue<pair<int, int>> q;
	q.push({ sr,sc });
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ux = x + dx[i];
			int uy = y + dy[i];

			if (ux<1 || uy<1 || ux>n || uy>m) continue;

			if (check(ux, uy,i) == false) {
				continue;
			}
			if (visit[ux][uy] == -1) {
				visit[ux][uy] = visit[x][y] + 1;
				q.push({ ux,uy });
			}
		}
	}
	if (visit[fr][fc] == -1) cout << -1;
	else cout << visit[fr][fc];
	return 0;
}
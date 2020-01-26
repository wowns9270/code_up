#include<bits/stdc++.h>
using namespace std;

int arr[201][201];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int dx2[] = { 2,2,1,1,-1,-1,-2,-2 };
int dy2[] = { -1,1,-2,2,-2,2,-1,1 };
int k,n,m;
int visit [31][201][201];
struct horse {
	int cnt;
	int x;
	int y;
};
int main() {
	cin >> k >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	queue<horse> q;
	memset(visit, -1, sizeof(visit));
	q.push({ 0, 0, 0 });
	visit[0][0][0] = 0;
	while (!q.empty()) {
		int cnt = q.front().cnt;
		int x = q.front().x;	
		int y = q.front().y;
		q.pop();
		for (int i = 0; i < 4; i++) {

			int ux = x + dx[i];
			int uy = y + dy[i];

			if (ux < 0 || uy < 0 || ux >= n || uy >= m) continue;

			if (arr[ux][uy] == 0) {
				if (visit[cnt][ux][uy] == -1) {
					visit[cnt][ux][uy] = visit[cnt][x][y] +1;
					q.push({ cnt,ux,uy });
				}
			}
		}
		for (int i = 0; i < 8; i++) {
			int ux = x + dx2[i];
			int uy = y + dy2[i];

			if (ux < 0 || uy < 0 || ux >= n || uy >= m) continue;

			if (arr[ux][uy] == 0 && cnt < k) {
				if (visit[cnt+1][ux][uy] == -1) {
					visit[cnt + 1][ux][uy] = visit[cnt][x][y] + 1;
					q.push({ cnt+1,ux,uy});
				}
			}
		}
	}
	int ans = 1999999;
	for (int i = 0; i <= k; i++) {
		if (visit[i][n - 1][m - 1] == -1) continue;
		ans = min(ans, visit[i][n-1][m-1]);
	}
	if (ans == 1999999) cout << "-1";
	else {
		cout << ans;
	}
	return 0;
}
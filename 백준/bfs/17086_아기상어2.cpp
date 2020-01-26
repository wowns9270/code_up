#include<bits/stdc++.h>
using namespace std;
int dx[] = { -1,-1,-1,0,0,1,1,1 };
int dy[] = { 1,0,-1,-1,1,-1,0,1 };
int n, m, arr[51][51],visit[51][51];
vector<pair<int, int>> llist;
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) {
				llist.push_back({ i,j });
			}
		}
	}
	memset(visit, -1, sizeof(visit));
	queue<pair<int, int>> q;
	for (int i = 0; i < llist.size(); i++) {
		q.push({ llist[i].first,llist[i].second });
		visit[llist[i].first][llist[i].second] = 0;
	}
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 8; i++) {
			int ux = x + dx[i];
			int uy = y + dy[i];
			if (ux < 0 || ux >= n || uy < 0 || uy >= m) continue;
			if (arr[ux][uy] == 0) {

				if (visit[ux][uy] == -1) {
					visit[ux][uy] = visit[x][y] + 1;
					q.push({ ux,uy });
				}
			}
		}
	}
		int ans = -1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				ans = max(ans, visit[i][j]);
			}
		}
		cout << ans;
		return 0;
}
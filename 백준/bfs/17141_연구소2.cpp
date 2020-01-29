#include<bits/stdc++.h>
using namespace std;
#define INF 19999999
int n, m,arr[51][51],ret=INF;
vector<pair<int, int>> llist; //바이러스 리스트
vector<int> sell; // 바이러스 번호
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int virus() {
	//바이러스를 퍼트린다.
	int visit[51][51];
	memset(visit, -1, sizeof(visit));
	queue<pair<int, int>> q;
	for (int i = 0; i < sell.size(); i++) {
		visit[llist[sell[i]].first][llist[sell[i]].second] = 0;
		q.push({ llist[sell[i]].first,llist[sell[i]].second });
	}
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ux = x + dx[i];
			int uy = y + dy[i];

			if (ux < 0 || uy < 0 || ux >= n || uy >= n) continue;

			if (arr[ux][uy] != 1 && visit[ux][uy] == -1) {
				visit[ux][uy] = visit[x][y] + 1;
				q.push({ ux,uy });
			}
		}
	}
	int k = -1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 1) continue;
			else {
				if (visit[i][j] == -1) return INF;
				else {
					k = max(k, visit[i][j]);
				}
			}
		}
	}
	return k;
}
void gogo(int idx, int cnt) {
	//바이러스 개수가 되면 퍼트린다.
	if (cnt == m) {
		int k = virus();

		ret = min(ret, k);
		return;
	}
	if (idx >= llist.size()) return;
	//바이러스를 담을지 말지 선택
	sell.push_back(idx);
	gogo(idx + 1, cnt + 1);
	sell.pop_back();
	gogo(idx + 1, cnt);

}
int main() {
	cin >> n >> m;
	//입력 그리고 바이러스를 담는다
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];

			if (arr[i][j] == 2) {
				llist.push_back({ i,j });
			}
		}
	}
	gogo(0, 0);
	if (ret == INF) cout << "-1";
	else
	cout << ret;
	return 0;
}
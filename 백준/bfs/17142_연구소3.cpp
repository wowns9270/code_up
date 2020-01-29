#include<bits/stdc++.h>
using namespace std;
#define INF 19999999
int n, m, arr[51][51], ret = INF;
vector<pair<int, int>> llist;
vector<int> sell;

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

//이걸 우예 이해할까 생각했다.
//활성바이러스와 비활성바이러스 간의 무엇인가 있긴한데..
//설명만 하자면 비활성 바이러스는 그냥 시간 제는거에서 제외된다.
//즉 빈칸이였던 0이 가장 높은 값이 정답이라고 할 수 있다.
//비활성산소는 그냥 지나간다..
int virus() {
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
	int k = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if(arr[i][j] ==0){
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
	if (cnt == m) {
		int k = virus();

		ret = min(ret, k);
		return;
	}
	if (idx >= llist.size()) return;

	sell.push_back(idx);
	gogo(idx + 1, cnt + 1);
	sell.pop_back();
	gogo(idx + 1, cnt);

}
int main() {
	cin >> n >> m;
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
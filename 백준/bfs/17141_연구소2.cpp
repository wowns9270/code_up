#include<bits/stdc++.h>
using namespace std;
#define INF 19999999
int n, m,arr[51][51],ret=INF;
vector<pair<int, int>> llist; //���̷��� ����Ʈ
vector<int> sell; // ���̷��� ��ȣ
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int virus() {
	//���̷����� ��Ʈ����.
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
	//���̷��� ������ �Ǹ� ��Ʈ����.
	if (cnt == m) {
		int k = virus();

		ret = min(ret, k);
		return;
	}
	if (idx >= llist.size()) return;
	//���̷����� ������ ���� ����
	sell.push_back(idx);
	gogo(idx + 1, cnt + 1);
	sell.pop_back();
	gogo(idx + 1, cnt);

}
int main() {
	cin >> n >> m;
	//�Է� �׸��� ���̷����� ��´�
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
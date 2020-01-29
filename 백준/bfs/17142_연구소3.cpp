#include<bits/stdc++.h>
using namespace std;
#define INF 19999999
int n, m, arr[51][51], ret = INF;
vector<pair<int, int>> llist;
vector<int> sell;

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

//�̰� �쿹 �����ұ� �����ߴ�.
//Ȱ�����̷����� ��Ȱ�����̷��� ���� �����ΰ� �ֱ��ѵ�..
//���� ���ڸ� ��Ȱ�� ���̷����� �׳� �ð� ���°ſ��� ���ܵȴ�.
//�� ��ĭ�̿��� 0�� ���� ���� ���� �����̶�� �� �� �ִ�.
//��Ȱ����Ҵ� �׳� ��������..
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
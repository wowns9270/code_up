//�� ������������ ����Ÿ��� ���� ���Ѵ�.
#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;
int n, m,st,ed;
vector<vector<pair<int, int>>> arr;
vector<vector<pair<int, int>>> arr2;
int dist[10001];
int dist2[10001];
int cost[10001];
bool check[10001];
int main() {
	cin >> n >> m;
	arr.resize(n + 1);
	arr2.resize(n + 1);

	for (int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;
		arr[a].push_back({ b,c });
		arr2[b].push_back({ a,c });
		dist[b]++;
		dist2[a]++;
	}//���������� �޾Ҵ�.

	cin >> st >> ed; //���۰� ���� �޴´�.
	queue<int> q;

	q.push(st);

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int i = 0; i < arr[x].size(); i++) { // ������ִ°�
			int ux = arr[x][i].first; //����� ���� 
			int costt = arr[x][i].second; //�װ��� ���

			dist[ux]--;
			if (cost[ux] < cost[x] + costt) {
				cost[ux] = cost[x] + costt;
			}
			if (dist[ux] == 0) { //
				q.push(ux);
			}
		}
	}
	cout << cost[ed] << "\n"; //���������� �ִ���
	check[ed] = true;
	queue<int> q2;
	
	q2.push(ed);
	int ret = 0;
	while (!q2.empty()) {

		int x = q2.front();
		q2.pop();
		for (int i = 0; i < arr2[x].size(); i++) {

			int ux = arr2[x][i].first; //����� ����
			int costt = arr2[x][i].second; // ����ġ

			if (check[x] ==true && cost[x] - cost[ux] == costt) {
				check[ux] = true;
				ret++;
			}
			dist2[ux]--;
			if (dist2[ux] == 0) {
				q2.push(ux);
			}
		}
	}
	cout << ret;
	return 0;
}
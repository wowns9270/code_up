//각 정점까지가는 최장거리를 먼저 구한다.
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
	}//간선정보를 받았다.

	cin >> st >> ed; //시작과 끝을 받는다.
	queue<int> q;

	q.push(st);

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int i = 0; i < arr[x].size(); i++) { // 연결되있는거
			int ux = arr[x][i].first; //연결된 정점 
			int costt = arr[x][i].second; //그간선 비용

			dist[ux]--;
			if (cost[ux] < cost[x] + costt) {
				cost[ux] = cost[x] + costt;
			}
			if (dist[ux] == 0) { //
				q.push(ux);
			}
		}
	}
	cout << cost[ed] << "\n"; //도착지에서 최대비용
	check[ed] = true;
	queue<int> q2;
	
	q2.push(ed);
	int ret = 0;
	while (!q2.empty()) {

		int x = q2.front();
		q2.pop();
		for (int i = 0; i < arr2[x].size(); i++) {

			int ux = arr2[x][i].first; //연결된 정점
			int costt = arr2[x][i].second; // 가중치

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
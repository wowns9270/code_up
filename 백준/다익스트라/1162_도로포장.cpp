//k개의 이하의 도로를 포장
//도로를 포장하면 도로를 지나는데 걸리는 시간이 0이다.
#include<bits/stdc++.h>	
#define INF 9999999999999
using namespace std;
int n, m, k;
long long dist[10001][21];
vector < vector<pair<int, int>>> arr;
struct edge {
	long long cost;
	int i;
	int t;
};
bool operator <(edge x, edge y) {
	if (x.cost < y.cost) return true;
	return false;
}
int main() {
	cin >> n >> m >> k;
	arr.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;

		arr[a].push_back({ b,c });
		arr[b].push_back({ a,c });
	} // 양방향 정보를 입력

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			dist[i][j] = INF;
		}
	}
	dist[1][0] = 0; // 첫 정점에서 포장을 안한상태
	priority_queue<edge> pq;
	pq.push({ 0,1,0 });
	while (!pq.empty()) {

		int x = pq.top().i;
		int tt = pq.top().t;
		pq.pop();

		for (int i = 0; i < arr[x].size(); i++) {

			int ux = arr[x][i].first;
			int costt = arr[x][i].second;

			if (tt < k) {
				if (dist[ux][tt + 1] > dist[x][tt]) {
					dist[ux][tt + 1] = dist[x][tt];
					pq.push({ -dist[ux][tt + 1],ux,tt + 1 });
				}
			}

			if (dist[ux][tt] > dist[x][tt] + costt) {
				dist[ux][tt] = dist[x][tt] + costt;
				pq.push({ -dist[ux][tt],ux,tt });
			}
		}
	}
	long long ret = INF;
	for (int i = 0; i <= k; i++) {
		if (ret > dist[n][i]) {
			ret = dist[n][i];
		}
	}
	cout << ret;
	return 0;
}
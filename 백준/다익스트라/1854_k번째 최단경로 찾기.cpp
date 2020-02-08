#include<bits/stdc++.h>
using namespace std;


int n, m, k;
vector < vector<pair<int, int>>> arr;

int main() {
	cin >> n >> m >> k;

	priority_queue<int> dist[10001];

	arr.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;
		arr[a].push_back({ b,c });
	}

	priority_queue<pair<int, int>> pq;
	dist[1].push(0);
	pq.push({ 0,1 });

	while (!pq.empty()) {

		int a_cost = -pq.top().first;
		int x = pq.top().second; 
		pq.pop();
		for (int i = 0; i < arr[x].size(); i++) {

			int ux = arr[x][i].first;
			int costt = arr[x][i].second;

			if (dist[ux].size() < k) {
				dist[ux].push(a_cost + costt);
				pq.push({ -(a_cost + costt),ux });
			}
			else {
				if (dist[ux].top() > a_cost + costt) {
					dist[ux].pop();
					dist[ux].push(a_cost + costt);
					pq.push({ -(a_cost + costt),ux });
				}
		
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (dist[i].size() != k) {
			cout << "-1\n";
		}
		else cout << dist[i].top() << "\n";
	}
	return 0;

}
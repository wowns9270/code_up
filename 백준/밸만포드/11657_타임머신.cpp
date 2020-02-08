#include<bits/stdc++.h>
using namespace std;
#define INF 999999999
struct edge {
	int from;
	int to;
	int cost;
};
int dist[501], n, m;

vector<edge> arr;

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;
		arr.push_back({ a,b,c });
	}

	for (int i = 1; i <= n; i++) dist[i] = INF;
	dist[1] = 0;

	bool cycle = false;
	for (int i = 1; i <= n; i++) {

		for (int j = 0; j < arr.size(); j++) {

			int x = arr[j].from;
			int y = arr[j].to;
			int z = arr[j].cost;

			if (dist[x] != INF && dist[y] > dist[x] + z) {
				dist[y] = dist[x] + z;

				if (i == n) {
					cycle = true;
				}
			}
		}
	}

	if (cycle == true) cout << "-1";
	else {
		for (int i = 2; i <= n; i++) {
			if (dist[i] == INF) cout << "-1\n";
			else cout << dist[i] << "\n";
		}
	}
	return 0;


}
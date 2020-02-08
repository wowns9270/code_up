#include<bits/stdc++.h>
using namespace std;
#define INF 9999999

int dist[502], t, n, m, w;
struct edge {
	int from;
	int to;
	int cost;
};
vector<edge> arr;

int main() {
	cin >> t;
	while (t--) {
		arr.clear();
		cin >> n >> m >> w;

		for (int i = 0; i < m; i++) {
			int a, b, c; cin >> a >> b >> c;
			arr.push_back({ b,a,c });
			arr.push_back({ a,b,c });
		}
		for (int i = 0; i < w; i++) {
			int a, b, c; cin >> a >> b >> c;
			arr.push_back({ a,b,-c });
		}


		for (int i = 1; i <= n; i++) dist[i] = INF;
		dist[n] = 0;
		bool check = false;

		for (int i = 1; i <= n; i++) {

			for (int j = 0; j < arr.size(); j++) {

				int x = arr[j].from;
				int y = arr[j].to;
				int z = arr[j].cost;

				if (dist[x] != INF && dist[y] > dist[x] + z) {
					dist[y] = dist[x] + z;

					if (i == n) {
						check = true;
					}
				}
			}

		}
		if (check == true) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define INF 99999999


int n,m,st,ed; //도시와 버스

vector < vector<pair<int, int>>> arr;

int dist[10001]; //거리정보
bool check[10001]; // 확인정보
int from[10001];


int main() {
	cin >> n >> m;

	arr.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;
		arr[a].push_back({ b,c }); // 인접리스트 정보
	}
	cin >> st >> ed; //출발 지점과 도착지점

	for (int i = 1; i <= n; i++) dist[i] = INF;

	dist[st] = 0;
	from[st] = -1;
	for (int i = 1; i <= n; i++) {
		int dist_m = INF + 1;
		int idx = -1;

		for (int j = 1; j <= n; j++) { //체크안된 정점중 가장 cost 작은거

			if (check[j] == false && dist_m > dist[j] ) {
				dist_m = dist[j];
				idx = j;
			}
		}
		check[idx] = true;
		for (int j = 0; j < arr[idx].size(); j++) {
			int to = arr[idx][j].first;
			int costt = arr[idx][j].second;

			if (dist[to] > dist[idx] + costt) {
				dist[to] = dist[idx] + costt;
				from[to] = idx;
			}
		}
	}
	cout << dist[ed]<<"\n";

	vector<int>llist;

	llist.push_back(ed);
	int k = ed;
	while (1) {
		k = from[k];
		if (k == -1) break;

		llist.push_back(k);
	}
	cout << llist.size()<<"\n";
	reverse(llist.begin(), llist.end());
	for (int a : llist) {
		cout << a << " ";
	}
	return 0;
}
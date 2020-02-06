#include<bits/stdc++.h>
using namespace std;
bool check[1001];
int n, m;
vector<vector<pair<int, int> > > arr;
struct compp {

	int cost;
	int x;
	int y;
};
bool operator <(compp a, compp b) {
	
	if (a.cost < b.cost) return true;
	return false;
}
int main() {
	cin >> n >> m;
	arr.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;
		arr[b].push_back({ a,c });
		arr[a].push_back({ b,c });
	}

	priority_queue<compp> pq;
	check[1] = true; //첫 정점을 방문표시 
	for (int i = 0; i < arr[1].size(); i++) {
		pq.push({ -arr[1][i].second, 1, arr[1][i].first });
	}
	int ret = 0;
	while (!pq.empty()) {
		int costt = -pq.top().cost; //비용
		int yy = pq.top().y; // 어디정점으로 가는
		if (check[yy] == true) {
			pq.pop();
			continue;
		}
		pq.pop();
		check[yy] = true;
		ret += costt;
		for (int i = 0; i < arr[yy].size(); i++) {
			pq.push({ -arr[yy][i].second,yy,arr[yy][i].first });
		}
	}
	cout << ret;
	return 0;
}
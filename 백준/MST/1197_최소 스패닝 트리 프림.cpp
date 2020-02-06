#include<bits/stdc++.h>
using namespace std;


struct copp {
	int x, y, cost;
};

bool operator<(copp x, copp y) {
	if (x.cost < y.cost) {
		return true;
	}
	return false;
}

int n, m;
vector<vector<pair<int, int>>> arr;
int check[10001];

int main() {
	cin >> n >> m;
	arr.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;
		arr[b].push_back({ a, c });
		arr[a].push_back({ b, c });
	}
	check[1] = true;
	priority_queue<copp> pq;
	for (int i = 0; i < arr[1].size(); i++) {
		pq.push({ 1,arr[1][i].first,-arr[1][i].second });
	}

	int ret = 0;
	while (!pq.empty()) {

		int uy = pq.top().y;
		int costt = -pq.top().cost;

		pq.pop();
		if (check[uy] == true) continue;

		check[uy] = true;
		for (int i = 0; i < arr[uy].size(); i++) {
			pq.push({ uy,arr[uy][i].first,-arr[uy][i].second });
		}
		ret += costt;
	}
	cout << ret;
	return 0;
}
#include<bits/stdc++.h>
using namespace std;

int n, m;
int degree[32001];

vector<vector<int>> arr;

int main() {
	cin >> n >> m;
	arr.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		arr[a].push_back(b); //간선 넣고
		degree[b]++;
	}

	priority_queue<int> pq;
	for (int i = 1; i <= n; i++) {
		if (degree[i] == 0) {
			pq.push(-i);
		}
	}

	while (!pq.empty()) {

		int x = -pq.top();
		cout << x << " ";
		pq.pop();

		for (int i = 0; i < arr[x].size(); i++) {
			int kx = arr[x][i];
			degree[kx]--;

			if (degree[kx] == 0) {
				pq.push(-kx);
			}
		}
	}
	return 0;
}
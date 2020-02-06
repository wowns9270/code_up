#include<bits/stdc++.h>
using namespace std;

int n, m;

int degree[32001];
vector<vector<int>> arr;

int main() {
	cin >> n >> m;
	arr.resize(n+1);

	//간선 정보를 넣고
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		arr[a].push_back(b); //가는 정보만
		degree[b]++; //들어오는정보
	}

	//큐에 자신으로 들어오는게 없는 정점을 넣어준다.
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (degree[i] == 0) {
			q.push(i);
		}
	}

	while (!q.empty()) {
		int x = q.front(); //in-degree 가 0 이다.
		cout << x<<" ";
		q.pop();
		for (int i = 0; i < arr[x].size(); i++) {
			int kx = arr[x][i];
			degree[kx]--;

			if (degree[kx] == 0) {
				q.push(kx);
			}
		}
	}
	return 0;
}
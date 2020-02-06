#include<bits/stdc++.h>
using namespace std;

int n;
int cost[10001];
int degree[10001];
int timee[10001];
vector<vector<int>> arr;

int main() {
	cin >> n;
	arr.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> cost[i]; //비용받고
		int a; cin >> a;
		for (int j = 0; j < a; j++) {
			int b; cin >> b;
			arr[b].push_back(i);
			degree[i]++;
		}
	}
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (degree[i] == 0) {
			q.push(i);
			timee[i] = cost[i];
		}
	}
	while (!q.empty()) {
		int x = q.front();
		int x_cost = timee[x];
		q.pop();

		for (int i = 0; i < arr[x].size(); i++) {
			int kx = arr[x][i];
			degree[kx]--;

			//여기서 선행작업이 있을 때 선행작업이 완료된 가장
			//늦은시간을 선택해줘야한다.
			if (degree[kx] == 0) {
				timee[kx] = max(timee[kx], x_cost + cost[kx]);
				q.push(kx);
			}
			else {
				timee[kx] = max(timee[kx], x_cost + cost[kx]);
			}
		}
	}

	int ret = 0;
	for (int i = 1; i <= n; i++) {
		ret = max(ret, timee[i]);
	}
	cout << ret;
	return 0;
}
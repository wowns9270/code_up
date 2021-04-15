#include<bits/stdc++.h>
using namespace std;

ifstream in("flow.inp");
ofstream out("flow.out");

int n , ret;

int c[10003][10003];
int f[10003][10003];
int visited[100003];

vector<vector<int> > arr;

int bfs(int s, int t) {

	memset(visited, -1, sizeof(visited));

	queue<int> q;

	q.push(0);

	while (!q.empty()) {

		int x = q.front();
		q.pop();


		for (int i = 0; i < arr[x].size(); i++) {
			
			int y = arr[x][i];


			if (c[x][y] - f[x][y] <= 0) continue;
			if (visited[y] != -1) continue;


			visited[y] = x;
			q.push(y);

			if (y == t) break;
		}
	}

	if (visited[t] == -1) return 0;

	int flow = 99999999;
	int k = t;
	while (k) {
			
		flow = min(flow, c[visited[k]][k] - f[visited[k]][k]);
		k = visited[k];
	}
	k = t;

	while (k) {

		f[visited[k]][k] += flow;
		f[k][visited[k]] -= flow;

		k = visited[k];
	}


	return flow;
}

int main() {


	in >> n;

	arr.resize(n + 1);
	
	while (1) {

		int a, b, w; in >> a >> b >> w;

		if (a == -1) break;

		c[a][b] = w;
		c[b][a] = w;


		arr[a].push_back(b);
		arr[b].push_back(a);
	}

	while (1) {
		int k = bfs(0, n - 1);

		ret += k;
		if (k == 0) break;
	}

	out << ret;
	return 0;
}
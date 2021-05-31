#include<bits/stdc++.h>
using namespace std;

ifstream in("service.inp");
ofstream out("service.out");

//봉사팀 개수 1 ~ 51

//

int test, n, p, m, e;

int sum[101]; //봉사기간 합

vector<vector<int> > arr;

int c[10000][10000]; //용량
int f[10000][10000];

int arr_check[10000][10000];

int level[10000];
int visited[10000];

int bfs() {

	memset(level, -1, sizeof(level));
	level[0] = 0;
	queue<int> q;
	q.push(0);

	while (!q.empty() && level[e] == -1) {

		int x = q.front();
		q.pop();

		for (int i = 0; i < arr[x].size(); i++) {

			int y = arr[x][i];

			//못흘리거나 방문 했거나
			if (c[x][y] - f[x][y] <= 0) continue;
			if (level[y] != -1) continue;

			level[y] = level[x] + 1;
			q.push(y);

			if (y == e) break;
		}
	}

	if (level[e] == -1) return 0;
	else return 1;
}


int dfs(int s, int e, int flow) {

	if (s == e) return flow;


	for (int& i = visited[s]; i < arr[s].size(); i++) {
		int ne = arr[s][i];

		if (level[ne] == level[s] + 1 && c[s][ne] - f[s][ne] > 0) {

			int df = dfs(ne, e, min(c[s][ne] - f[s][ne], flow));
			if (df > 0) {
				f[s][ne] += df;
				f[ne][s] -= df;
				return df;
			}
		}
	}
	// 증가 경로를 찾지 못함: 유량 0 흘림
	return 0;
}

int main() {


	in >> test;

	while (test--) {

		ios_base::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		in >> n >> p >> m;

		arr.clear();
		memset(c, 0, sizeof(c));
		memset(f, 0, sizeof(f));

		for (int i = 1; i <= p; i++) {
			int k; in >> k;
			sum[i] = sum[i - 1] + k;
		}

		arr.resize(2 + n + n * p + sum[p] + 1);

		int idx = n + (n * p);
		int cn = n;
		for (int i = 1; i <= n; i++) {
			arr[i].push_back(0);
			arr[0].push_back(i);
			c[0][i] = m;


			int gg; in >> gg;

			for (int j = 0; j < gg; j++) {
				int a, b; in >> a >> b;

				int r1 = cn + a;

				int r2 = idx + sum[a - 1] + b;

				arr[r1].push_back(r2);
				arr[r2].push_back(r1);
				c[r1][r2] = 1;


				c[i][r1] = 1;
				arr[i].push_back(r1);
				arr[r1].push_back(i);

			}
			cn += p;
		}

		e = 1 + n + n * p + sum[p];
		for (int i = 1 + n + n * p; i < e; i++) {

			arr[e].push_back(i);
			arr[i].push_back(e);
			c[i][e] = 1;
		}

		int ret = 0;
		while (bfs()) {

			memset(visited, 0, sizeof(visited));

			while (1) {
				int flow = dfs(0, e, 9999999);

				if (flow == 0) break;

				ret += flow;
			}


		}

		if (ret == sum[p]) out << 1 << "\n";
		else out << 0 << "\n";
	}
	return 0;
}
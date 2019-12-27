#include<iostream>
#include<algorithm>
#include<queue>
#define next _next
using namespace std;


int dx[] = { 1,2,3,4,5,6 };

int next[101];
int dist[101];

void bfs(int cnt) {
	queue<int> q;
	q.push(cnt);
	dist[1] = 0;


	while (!q.empty()) {
		int ux = q.front();	q.pop();

		for (int i = 0; i < 6; i++) {
			int nx = ux + dx[i];

			if (nx > 100) continue;

			nx = next[nx];

			if (dist[nx] == -1) {
				dist[nx] = dist[ux] + 1;
				q.push(nx);
			}

		}


	}
}
int main() {
	int n, m; cin >> n >> m;


	for (int i = 1; i <= 100; i++) {
		next[i] = i;
		dist[i] = -1;
	}

	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		next[a] = b;
	}
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		next[a] = b;
	}
	bfs(1);
	cout << dist[100] << "\n";
	return 0;

}

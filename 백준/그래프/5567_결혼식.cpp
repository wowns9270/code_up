#include<bits/stdc++.h>
using namespace std;

int n , m;

vector<vector<int>> arr;

//관계에 대한 정보
int check[501];


void bfs(int x) {

	check[x] = 1;
	queue<int> q;
	q.push(x);

	while (!q.empty()) {
		int nx = q.front();
		q.pop();
		for (int i = 0; i < arr[nx].size(); i++) {

			int ux = arr[nx][i];

			if (check[ux] == 0) {
				check[ux] = check[nx] + 1;
				q.push(ux);
			}
		}
	}
}


int main() {

	//그래프의 연결관계를 통해 정보를 얻는 문제
	//그래프 탐색 -> bfs dfs 여기서는 bfs로 탐색이 수월

	//상근이는 1번이다/

	cin >> n >> m;

	arr.resize(n + 1);

	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;

		arr[a].push_back(b);
		arr[b].push_back(a);
	}


	//상근이는 1   관계없는사람은 0
	//상근이의 친구와 친구의 친구 check == 2 or 3 인경우
	bfs(1);

	int cnt = 0;
	for (int i = 2; i <= n; i++) {
		if (check[i] == 2 || check[i] == 3) {
			cnt++;
		}
	}

	cout << cnt;
	return 0;

}
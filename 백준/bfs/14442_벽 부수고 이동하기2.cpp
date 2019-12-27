#include<iostream>
#include<algorithm>
#include<queue>
#include<cstdio>
#pragma warning(disable:4996)
using namespace std;


int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

int arr[1000][1000];
int arr_ret[1000][1000][11];




int main() {
	//k개의 벽을 놓거나 말거나 가장 빨리 도착할 수 있는 경우를 찾는 문제
	//이게 잘 이해가 안가는 부분이 있었는데
	//먼저 일차원적으로 벽이 막혀있으면
	//다른 차원(한층 위라고 생각)이라 생각하면 벽하나 부수고 들어가는
	//경우 이렇게 생각했는데 어렵긴하다...
	int n, m, k; cin >> n >> m >> k;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}

	queue<pair<pair<int, int>, int>> q;
	q.push(make_pair(make_pair(0, 0), 0));
	arr_ret[0][0][0] = 1;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int z = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ux = x + dx[i];
			int uy = y + dy[i];


			if (ux < 0 || uy < 0 || ux >= n || uy >= m) continue;

			if (arr[ux][uy] == 0 && arr_ret[ux][uy][z] == 0) {
				arr_ret[ux][uy][z] = arr_ret[x][y][z] + 1;
				q.push(make_pair(make_pair(ux, uy), z));
			}

			//벽을 부술 기회가 있고 벽이라면 그 위의 차원에서
			//부셔버린적 없으면 부셔보자 최단거리로.....
			if (z + 1 <= k && arr[ux][uy] == 1 && arr_ret[ux][uy][z + 1] == 0) {
				arr_ret[ux][uy][z + 1] = arr_ret[x][y][z] + 1;
				q.push(make_pair(make_pair(ux, uy), z + 1));
			}
		}
	}

	int ret = 1000000;
	//각 층에서 도착점에 도착했을경우 최소 가장 최단으로 
	//도착한 경우를 찾는다.
	//모든 경우에 답이없으면 벽을 부셔도 갈수없다는거다.
	for (int i = 0; i <= k; i++) {
		if (arr_ret[n - 1][m - 1][i] == 0) continue;

		ret = min(ret, arr_ret[n - 1][m - 1][i]);
	}

	if (ret == 1000000) cout << "-1";
	else cout << ret;


	return 0;
}
#include<iostream>
#include<algorithm>
#include<memory.h>
#include<queue>
using namespace std;

int arr[21][21];
int visit[21][21];
int dx[] = { -1,0,0,1 };
int dy[] = { 0,-1,1,0 };
int shark_x, shark_y, cnt, n, sum;
int shark_size = 2;

bool cmp(pair<int, pair<int, int>> x, pair<int, pair<int, int>> y) {

	if (x.first < y.first) {
		return true;
	}
	else if (x.first == y.first) {
		if (x.second.first < y.second.first) {
			return true;
		}
		else if (x.second.first == y.second.first) {
			if (x.second.second < y.second.second) {
				return true;
			}
		}
	}
	return false;
}
int bfs(int x, int y) {
	int copy_arr[21][21] = { 0, };
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	visit[x][y] = true;
	vector<pair<int, pair<int, int>>> list;
	bool check = false;
	while (!q.empty()) {
		int nx = q.front().first;
		int ny = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ux = nx + dx[i];
			int uy = ny + dy[i];
			if (ux < 0 || uy < 0 || ux >= n || uy >= n) continue;
			if (arr[ux][uy] == 0 && visit[ux][uy] == false) {
				visit[ux][uy] = true;
				copy_arr[ux][uy] = copy_arr[nx][ny] + 1;
				q.push(make_pair(ux, uy));
			}

			if (arr[ux][uy] != 0 && visit[ux][uy] == false) {

				if (shark_size < arr[ux][uy]) continue;

				else if (shark_size == arr[ux][uy]) {
					visit[ux][uy] = true;
					copy_arr[ux][uy] = copy_arr[nx][ny] + 1;
					q.push(make_pair(ux, uy));
				}
				else if (shark_size > arr[ux][uy]) {
					visit[ux][uy] = true;
					copy_arr[ux][uy] = copy_arr[nx][ny] + 1;

					list.push_back(make_pair(copy_arr[ux][uy],
						(make_pair(ux, uy))));

				}
			}
		}
	}
	if (list.size() != 0) {
		sort(list.begin(), list.end(), cmp);
		shark_x = list[0].second.first;
		shark_y = list[0].second.second;
		int k = copy_arr[shark_x][shark_y];
		arr[shark_x][shark_y] = 0;
		cnt++;
		return k;
	}
	return -1;
}
//조건이 까다로웠던 문제
//상어 사이즈 만큼 물고기를 먹어야 사이즈가 늘어나고.
//방문할 수있는 먹이중 가까우면서 위 왼 순으로 먹는 조건
//귀차나 그냥
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 9) {
				shark_x = i;
				shark_y = j;
				arr[i][j] = 0;
			}
		}
	}
	while (1) {
		memset(visit, false, sizeof(visit));
		int kkk = bfs(shark_x, shark_y);
		if (kkk == -1) break;
		else sum += kkk;

		if (shark_size == cnt) {
			shark_size++;
			cnt = 0;
		}
	}
	cout << sum;
	return 0;
}
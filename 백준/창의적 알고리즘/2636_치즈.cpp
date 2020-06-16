#include<bits/stdc++.h>
using namespace std;

int n, m;

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int arr[101][101];

vector<pair<int, int>> llist;

void bfs(int x, int y) {

	arr[x][y] = 2;
	queue<pair<int, int>> q;
	q.push({ x,y });

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ux = x + dx[i];
			int uy = y + dy[i];

			if (ux < 0 || uy < 0 || ux >= n || uy >= m) continue;

			if (arr[ux][uy] == 0) {
				arr[ux][uy] = 2;
				q.push({ ux,uy });
			}
		}
	}
}


int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];

			if (arr[i][j] == 1) {
				llist.push_back({ i,j });
			}
		}
	}
	bfs(0, 0);
	int k = llist.size(); // 첫 치즈 개수
	int time = 0;
	while (1) {
		//공기와 접한 치즈를 녹인다 .
		int a = 0;
		for (int i = 0; i < llist.size(); i++) {

			//치즈 후보
			int x = llist[i].first;
			int y = llist[i].second;

			for (int j = 0; j < 4; j++) {
				//치즈의 4방향을 본다
				int ux = x + dx[j];
				int uy = y + dy[j];
				//일단 치즈는 테두리에 존재하지 않는다.

				if (arr[ux][uy] == 2) {// 공기와 접한다
					arr[x][y] = 3; //치즈를 녹이고 그자리는 공기가된다
					a++;
					break;
				}
			}
		}
		for (int i = 0; i < llist.size(); i++) {

			int x = llist[i].first;
			int y = llist[i].second;

			if (arr[x][y] == 3) {
				bfs(x, y);
				llist.erase(llist.begin() + i);
				i--;
			}
		}
		if (k - a == 0) {
			cout << time + 1 << " ";
			cout << k;
			return 0;
		}
		k -= a;
		time++;
	}
	return 0;
}
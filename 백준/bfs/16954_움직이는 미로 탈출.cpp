#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

int dx[] = { -1,-1,-1 };
int dy[] = { -1,0,1 };


char arr[8][8];
int arr_ret[8][8];

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	arr_ret[x][y] = 1;

	while (!q.empty()) {
		int nx = q.front().first;
		int ny = q.front().second;
		q.pop();

		//벽이 내려오는것은 즉 캐릭터가 위로 가는것과 같다고 생각
		for (int i = 0; i < 3; i++) {
			int ux = nx + dx[i];
			int uy = ny + dy[i];
			if (ux < 0 || uy < 0 || ux >= 8 || uy >= 8) continue;
			

			//내가 대각선 위로 이동하려고 할때
			//내옆이 벽이고 이동하려는 곳 위도 벽이면 거기로 이동할수없다.
			if (arr[ux - 1][uy] == '#' && arr[ux + 1][uy] == '#') continue;



			if (arr[ux][uy] == '.' && arr_ret[ux][uy] == 0) {
				arr_ret[ux][uy] = 1;
				q.push(make_pair(ux, uy));
			}

		}
	}
}
//벽이 밑으로 내려오는 문제
int main() {
	//입력
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> arr[i][j];
		}
	}
	//시작
	bfs(7, 0);
	bool check = false;
	for (int i = 0; i < 8; i++) {
		if (arr_ret[0][i] == 1) {
			check = true;
			break;
		}
	}

	if (check) cout << "1";
	else cout << "0";
	return 0;
}
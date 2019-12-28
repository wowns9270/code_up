#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int dx[] = { 1,-1,0,0, };
int dy[] = { 0,0,1,-1 };

char arr[56][56];
//물이 사방으로 퍼지는 것과
//고슴도치가 이동하는 곳을 별도로 두어서
//물이 먼저 퍼지고 그곳은 고슴도치가 가지 못하게 하였다.
int arr_ret[56][56][2];
int des_x, des_y;
int s_x, s_y;
vector<pair<int, int>> water;
int n, m;

void bfs() {
	//인자를 3개를 받아야 해서 (구조체를 이용하는게 좋다)
	queue<pair<pair<int, int>, int>> q;

	//물인곳부터 먼저 큐에 넣어준다.
	for (int i = 0; i < water.size(); i++) {
		arr_ret[water[i].first][water[i].second][0] = -1;
		q.push(make_pair(make_pair(water[i].first, water[i].second), 0));
	}

	//고슴도치
	arr_ret[s_x][s_y][1] = 0;
	q.push(make_pair(make_pair(s_x, s_y), 1));


	while (!q.empty()) {
		int ux = q.front().first.first;
		int uy = q.front().first.second;
		int z = q.front().second;
		q.pop();


		for (int i = 0; i < 4; i++) {
			int nx = ux + dx[i];
			int ny = uy + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

			//물이 이동할 때는 돌과 도착점이 아니면 흐르니까
			//조건 잡아주면 된다.
			if (z == 0 && arr_ret[nx][ny][z] == 0) {
				if (arr[nx][ny] != 'X' && arr[nx][ny] != 'D') {
					arr_ret[nx][ny][z] = arr_ret[ux][uy][z];
					q.push(make_pair(make_pair(nx, ny), z));
				}
			}
			//고슴도치일때는 물이 이동한 장소이면 갈수없다고 
			//설정해주고 돌이 아니면 그곳으로 이동한다
			if (z == 1 && arr_ret[nx][ny][z] == 0 && arr_ret[nx][ny][z - 1] != -1) {
				if (arr[nx][ny] != 'X') {
					arr_ret[nx][ny][z] = arr_ret[ux][uy][z] + 1;
					q.push(make_pair(make_pair(nx, ny), z));
				}
			}
		}
	}
}
int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			//도착해야할곳
			if (arr[i][j] == 'D') {
				des_x = i;
				des_y = j;
			}
			//물은 하나가 아니였다 문제를 잘읽자.
			if (arr[i][j] == '*') {
				int w_x = i;
				int w_y = j;
				water.push_back(make_pair(w_x, w_y));
			}
			//고슴도치 위치
			if (arr[i][j] == 'S') {
				s_x = i;
				s_y = j;
			}

		}
	}
	// 탐색시작
	bfs();

	//고슴도치가 도착점에 왔으면 0이 아닐테니까 출력
	if (arr_ret[des_x][des_y][1] != 0) cout << arr_ret[des_x][des_y][1];
	else {
		cout << "KAKTUS";
	}
	return 0;
}
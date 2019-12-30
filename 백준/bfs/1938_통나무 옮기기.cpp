#include<bits/stdc++.h>
using namespace std;

int n;
char arr[55][55];
int arr_ret[55][55][2];
int dx[] = { 1,-1,0,0 };  //아래 위 오 왼
int dy[] = { 0,0,1,-1 };
int center_x, center_y;
int des_x, des_y;
vector<pair<int, int>> bb;
vector<pair<int, int>> ee;
int state;

void bfs(int x, int y, int state) {
	queue<pair<pair<int, int>, int>> q;
	q.push(make_pair(make_pair(x, y), state));
	arr_ret[x][y][state] = 0;

	while (!q.empty()) {
		int nx = q.front().first.first;
		int ny = q.front().first.second;
		int z = q.front().second;
		q.pop();


		if (z == 0) { //세로

			for (int i = 0; i < 4; i++) {
				int ux = nx + dx[i];
				int uy = ny + dy[i];


				if (uy < 0 || uy >= n || ux - 1 < 0 || ux + 1 >= n) continue;

				if (arr[ux - 1][uy] == '1' || arr[ux][uy] == '1' || arr[ux + 1][uy] == '1')
					continue;

				if (arr_ret[ux][uy][z] == -1) {
					arr_ret[ux][uy][z] = arr_ret[nx][ny][z] + 1;
					q.push(make_pair(make_pair(ux, uy), z));
				}

			}

			if (nx - 1 < 0 || nx + 1 >= n || ny - 1 < 0 || ny + 1 >= n) continue;
			else {

				if (arr[nx + 1][ny + 1] == '1' ||
					arr[nx][ny + 1] == '1' ||
					arr[nx - 1][ny + 1] == '1' ||
					arr[nx + 1][ny] == '1' ||
					arr[nx][ny] == '1' ||
					arr[nx - 1][ny] == '1' ||
					arr[nx + 1][ny - 1] == '1' ||
					arr[nx][ny - 1] == '1' ||
					arr[nx - 1][ny - 1] == '1') continue;
				else {
					if (arr_ret[nx][ny][1] == -1) {
						arr_ret[nx][ny][1] = arr_ret[nx][ny][0] + 1;
						q.push(make_pair(make_pair(nx, ny), 1));

					}
				}

			}
		}
		else { //가로

			for (int i = 0; i < 4; i++) {
				int ux = nx + dx[i];
				int uy = ny + dy[i];


				if (ux < 0 || ux >= n || uy - 1 < 0 || uy + 1 >= n) continue;

				if (arr[ux][uy - 1] == '1' || arr[ux][uy] == '1' || arr[ux][uy + 1] == '1')
					continue;

				if (arr_ret[ux][uy][z] == -1) {
					arr_ret[ux][uy][z] = arr_ret[nx][ny][z] + 1;
					q.push(make_pair(make_pair(ux, uy), z));
				}

			}

			if (nx - 1 < 0 || nx + 1 >= n || ny - 1 < 0 || ny + 1 >= n) continue;
			else {

				if (arr[nx + 1][ny + 1] == '1' ||
					arr[nx][ny + 1] == '1' ||
					arr[nx - 1][ny + 1] == '1' ||
					arr[nx + 1][ny] == '1' ||
					arr[nx][ny] == '1' ||
					arr[nx - 1][ny] == '1' ||
					arr[nx + 1][ny - 1] == '1' ||
					arr[nx][ny - 1] == '1' ||
					arr[nx - 1][ny - 1] == '1') continue;
				else {
					if (arr_ret[nx][ny][0] == -1) {
						arr_ret[nx][ny][0] = arr_ret[nx][ny][1] + 1;
						q.push(make_pair(make_pair(nx, ny), 0));

					}
				}

			}
		}
	}
}

//중심점을 이용하고 세로 가로 각각 따로 처리했는데 
//코드가 난잡하다 최적화가 필요함
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];

			if (arr[i][j] == 'B') {
				bb.push_back(make_pair(i, j));
				center_x += i;
				center_y += j;
			}

			if (arr[i][j] == 'E') {
				ee.push_back(make_pair(i, j));
				des_x += i;
				des_y += j;
			}
		}
	}
	memset(arr_ret, -1, sizeof(arr_ret));
	center_x /= 3;
	center_y /= 3;
	if (bb[0].first == bb[1].first)  state = 1; // 가로로
	else state = 0; // 세로로

	bfs(center_x, center_y, state);

	des_x /= 3;
	des_y /= 3;


	if (ee[0].first == ee[1].first) { // 가로
		if (arr_ret[des_x][des_y][1] == -1) cout << "0";
		else
			cout << arr_ret[des_x][des_y][1];
	}
	else {
		if (arr_ret[des_x][des_y][0] == -1) cout << "0";
		else
			cout << arr_ret[des_x][des_y][0];
	};


	return 0;
}
#include<iostream>
#include<cstdio>
#include<queue>
#include<set>
#pragma warning(disable:4996)
using namespace std;

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

int n, m;
int arr[1000][1000];
int copy_arr[1000][1000];

int arr_ret[1000000];
vector<pair<int, int>> wall;
int kk = 2;

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	arr[x][y] = kk;
	arr_ret[kk]++;

	while (!q.empty()) {
		int nx = q.front().first;
		int ny = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ux = nx + dx[i];
			int uy = ny + dy[i];

			if (ux < 0 || uy < 0 || ux >= n || uy >= m) continue;

			if (arr[ux][uy] == 0) {
				arr[ux][uy] = arr[nx][ny];
				q.push(make_pair(ux, uy));
				arr_ret[kk]++;
			}
		}
	}
}
//벽을 부셨을 경우 자기를포함해서 이동할수있는 곳은 몇개인지
//세어보라는 문제
int main() {
	cin >> n >> m;
	//입력
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &arr[i][j]);

			//벽인 곳을 따로 저장
			if (arr[i][j] == 1) {
				wall.push_back(make_pair(i, j));
			}
		}
	}

	//벽이아닌 공간의 번호를 붙여준다(단지함 찾기랑 비슷함)
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 0) {
				bfs(i, j);
				kk++;
			}
		}
	}

	//그러면 벽 주변에 이제 단지 번호가 적혀있을것이고
	//번호로 연결된 개수만큼 벽주변을 더해주는 것 이다.

	//나는 벽이 아닌 공간을 2부터 시작해서 단지를 만들어 줬는데
	//2로 연결된 개수가 8이고 벽 상하좌우에 2가 있으면
	//자기자신 + 2로 연결된 수(8)을 더해준다.
	//모든 방향으로
	for (int i = 0; i < wall.size(); i++) {
		set<int> s;
		int x = wall[i].first;
		int y = wall[i].second;
		int sum = 1;
		for (int i = 0; i < 4; i++) {
			int ux = x + dx[i];
			int uy = y + dy[i];

			if (ux < 0 || uy < 0 || ux >= n || uy >= m) continue;

			if (arr[ux][uy] != 1) s.insert(arr[ux][uy]);
		}

		//set을 활용한 이유는 중복 제거를 위해서이다.
		//위도 2 아래도 2 면 두번 더하는게 아니라 한번만 더해준다.
		set<int>::iterator it;
		for (it = s.begin(); it != s.end(); it++) {
			sum += arr_ret[*it];
		}
		copy_arr[x][y] = sum % 10;
		//이렇게 하고 copy_arr이였던곳만 저장 시켜주고
		// 맵을 출력하면 된다.
		//그냥 arr는 이미 색칠해서 사용하기 힘들다.
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << copy_arr[i][j];
		}
		cout << "\n";
	}
	return 0;
}
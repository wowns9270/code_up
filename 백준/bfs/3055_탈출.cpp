#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int dx[] = { 1,-1,0,0, };
int dy[] = { 0,0,1,-1 };

char arr[56][56];
//���� ������� ������ �Ͱ�
//����ġ�� �̵��ϴ� ���� ������ �ξ
//���� ���� ������ �װ��� ����ġ�� ���� ���ϰ� �Ͽ���.
int arr_ret[56][56][2];
int des_x, des_y;
int s_x, s_y;
vector<pair<int, int>> water;
int n, m;

void bfs() {
	//���ڸ� 3���� �޾ƾ� �ؼ� (����ü�� �̿��ϴ°� ����)
	queue<pair<pair<int, int>, int>> q;

	//���ΰ����� ���� ť�� �־��ش�.
	for (int i = 0; i < water.size(); i++) {
		arr_ret[water[i].first][water[i].second][0] = -1;
		q.push(make_pair(make_pair(water[i].first, water[i].second), 0));
	}

	//����ġ
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

			//���� �̵��� ���� ���� �������� �ƴϸ� �帣�ϱ�
			//���� ����ָ� �ȴ�.
			if (z == 0 && arr_ret[nx][ny][z] == 0) {
				if (arr[nx][ny] != 'X' && arr[nx][ny] != 'D') {
					arr_ret[nx][ny][z] = arr_ret[ux][uy][z];
					q.push(make_pair(make_pair(nx, ny), z));
				}
			}
			//����ġ�϶��� ���� �̵��� ����̸� �������ٰ� 
			//�������ְ� ���� �ƴϸ� �װ����� �̵��Ѵ�
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
			//�����ؾ��Ұ�
			if (arr[i][j] == 'D') {
				des_x = i;
				des_y = j;
			}
			//���� �ϳ��� �ƴϿ��� ������ ������.
			if (arr[i][j] == '*') {
				int w_x = i;
				int w_y = j;
				water.push_back(make_pair(w_x, w_y));
			}
			//����ġ ��ġ
			if (arr[i][j] == 'S') {
				s_x = i;
				s_y = j;
			}

		}
	}
	// Ž������
	bfs();

	//����ġ�� �������� ������ 0�� �ƴ��״ϱ� ���
	if (arr_ret[des_x][des_y][1] != 0) cout << arr_ret[des_x][des_y][1];
	else {
		cout << "KAKTUS";
	}
	return 0;
}
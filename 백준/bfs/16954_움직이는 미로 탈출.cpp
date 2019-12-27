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

		//���� �������°��� �� ĳ���Ͱ� ���� ���°Ͱ� ���ٰ� ����
		for (int i = 0; i < 3; i++) {
			int ux = nx + dx[i];
			int uy = ny + dy[i];
			if (ux < 0 || uy < 0 || ux >= 8 || uy >= 8) continue;
			

			//���� �밢�� ���� �̵��Ϸ��� �Ҷ�
			//������ ���̰� �̵��Ϸ��� �� ���� ���̸� �ű�� �̵��Ҽ�����.
			if (arr[ux - 1][uy] == '#' && arr[ux + 1][uy] == '#') continue;



			if (arr[ux][uy] == '.' && arr_ret[ux][uy] == 0) {
				arr_ret[ux][uy] = 1;
				q.push(make_pair(ux, uy));
			}

		}
	}
}
//���� ������ �������� ����
int main() {
	//�Է�
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> arr[i][j];
		}
	}
	//����
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
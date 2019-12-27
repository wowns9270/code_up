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
//���� �μ��� ��� �ڱ⸦�����ؼ� �̵��Ҽ��ִ� ���� �����
//������ ����
int main() {
	cin >> n >> m;
	//�Է�
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &arr[i][j]);

			//���� ���� ���� ����
			if (arr[i][j] == 1) {
				wall.push_back(make_pair(i, j));
			}
		}
	}

	//���̾ƴ� ������ ��ȣ�� �ٿ��ش�(������ ã��� �����)
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 0) {
				bfs(i, j);
				kk++;
			}
		}
	}

	//�׷��� �� �ֺ��� ���� ���� ��ȣ�� �����������̰�
	//��ȣ�� ����� ������ŭ ���ֺ��� �����ִ� �� �̴�.

	//���� ���� �ƴ� ������ 2���� �����ؼ� ������ ����� ��µ�
	//2�� ����� ������ 8�̰� �� �����¿쿡 2�� ������
	//�ڱ��ڽ� + 2�� ����� ��(8)�� �����ش�.
	//��� ��������
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

		//set�� Ȱ���� ������ �ߺ� ���Ÿ� ���ؼ��̴�.
		//���� 2 �Ʒ��� 2 �� �ι� ���ϴ°� �ƴ϶� �ѹ��� �����ش�.
		set<int>::iterator it;
		for (it = s.begin(); it != s.end(); it++) {
			sum += arr_ret[*it];
		}
		copy_arr[x][y] = sum % 10;
		//�̷��� �ϰ� copy_arr�̿������� ���� �����ְ�
		// ���� ����ϸ� �ȴ�.
		//�׳� arr�� �̹� ��ĥ�ؼ� ����ϱ� �����.
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << copy_arr[i][j];
		}
		cout << "\n";
	}
	return 0;
}
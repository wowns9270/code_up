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
	//k���� ���� ���ų� ���ų� ���� ���� ������ �� �ִ� ��츦 ã�� ����
	//�̰� �� ���ذ� �Ȱ��� �κ��� �־��µ�
	//���� ������������ ���� ����������
	//�ٸ� ����(���� ����� ����)�̶� �����ϸ� ���ϳ� �μ��� ����
	//��� �̷��� �����ߴµ� ��Ʊ��ϴ�...
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

			//���� �μ� ��ȸ�� �ְ� ���̶�� �� ���� ��������
			//�μŹ����� ������ �μź��� �ִܰŸ���.....
			if (z + 1 <= k && arr[ux][uy] == 1 && arr_ret[ux][uy][z + 1] == 0) {
				arr_ret[ux][uy][z + 1] = arr_ret[x][y][z] + 1;
				q.push(make_pair(make_pair(ux, uy), z + 1));
			}
		}
	}

	int ret = 1000000;
	//�� ������ �������� ����������� �ּ� ���� �ִ����� 
	//������ ��츦 ã�´�.
	//��� ��쿡 ���̾����� ���� �μŵ� �������ٴ°Ŵ�.
	for (int i = 0; i <= k; i++) {
		if (arr_ret[n - 1][m - 1][i] == 0) continue;

		ret = min(ret, arr_ret[n - 1][m - 1][i]);
	}

	if (ret == 1000000) cout << "-1";
	else cout << ret;


	return 0;
}
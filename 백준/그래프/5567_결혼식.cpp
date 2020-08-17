#include<bits/stdc++.h>
using namespace std;

int n , m;

vector<vector<int>> arr;

//���迡 ���� ����
int check[501];


void bfs(int x) {

	check[x] = 1;
	queue<int> q;
	q.push(x);

	while (!q.empty()) {
		int nx = q.front();
		q.pop();
		for (int i = 0; i < arr[nx].size(); i++) {

			int ux = arr[nx][i];

			if (check[ux] == 0) {
				check[ux] = check[nx] + 1;
				q.push(ux);
			}
		}
	}
}


int main() {

	//�׷����� ������踦 ���� ������ ��� ����
	//�׷��� Ž�� -> bfs dfs ���⼭�� bfs�� Ž���� ����

	//����̴� 1���̴�/

	cin >> n >> m;

	arr.resize(n + 1);

	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;

		arr[a].push_back(b);
		arr[b].push_back(a);
	}


	//����̴� 1   ������»���� 0
	//������� ģ���� ģ���� ģ�� check == 2 or 3 �ΰ��
	bfs(1);

	int cnt = 0;
	for (int i = 2; i <= n; i++) {
		if (check[i] == 2 || check[i] == 3) {
			cnt++;
		}
	}

	cout << cnt;
	return 0;

}
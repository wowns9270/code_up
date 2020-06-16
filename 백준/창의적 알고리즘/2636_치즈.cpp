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
	int k = llist.size(); // ù ġ�� ����
	int time = 0;
	while (1) {
		//����� ���� ġ� ���δ� .
		int a = 0;
		for (int i = 0; i < llist.size(); i++) {

			//ġ�� �ĺ�
			int x = llist[i].first;
			int y = llist[i].second;

			for (int j = 0; j < 4; j++) {
				//ġ���� 4������ ����
				int ux = x + dx[j];
				int uy = y + dy[j];
				//�ϴ� ġ��� �׵θ��� �������� �ʴ´�.

				if (arr[ux][uy] == 2) {// ����� ���Ѵ�
					arr[x][y] = 3; //ġ� ���̰� ���ڸ��� ���Ⱑ�ȴ�
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
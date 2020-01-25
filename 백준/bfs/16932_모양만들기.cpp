#include<bits/stdc++.h>
using namespace std;
int n, m,a=2;
int arr[1001][1001];
int cnt[1000001],ans;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int bfs(int x, int y) {
	int ret = 0;
	queue<pair<int, int>> q;
	q.push({ x,y });
	arr[x][y] = a;
	while (!q.empty()) {
		int ux = q.front().first;
		int uy = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = ux + dx[i];
			int ny = uy + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

			if (arr[nx][ny] == 1) {
				arr[nx][ny] = a;
				ret++;
				q.push({ nx,ny });
			}
		}
	}
	return ret;
}
int main() {
	cin >> n >> m;
	//�Է�
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	//������ ��ȣó�� ��ȣ�� �����ְ� 
	// �׹�ȣ �������� ���� cnt[]�� �����Ų��,
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 1) {
				cnt[a] = 1;
				int k = bfs(i, j);
				cnt[a] += k;
				a++;
			}
		}
	}

	// 0�϶� �� �ֺ��� ������ ������
	// �� �ֺ��� ���� ���� �����ְ� ������ �����ش�
	// �̶� �ߺ��� �߻��� �� �����Ƿ� set�� �̿��Ѵ�.
	// �ִ밪 ans�� ���Ͽ� �ִ밪�� ã�´�
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 0) {
				set<int>llist;
				for (int k = 0; k < 4; k++) {
					int kx = i + dx[k];
					int ky = j + dy[k];
					if (kx < 0 || ky < 0 || kx >= n || ky >= m) continue;
					if (llist.count(arr[kx][ky]) == 0) {
						llist.insert(arr[kx][ky]);
					}
				}
				int cnt2 = 1;
				for (auto it = llist.begin(); it != llist.end(); it++) {
					int k = *it;
					cnt2 += cnt[k];
				}
				ans = max(ans, cnt2);
			}
		}
	}
	cout << ans;
	return 0;
}
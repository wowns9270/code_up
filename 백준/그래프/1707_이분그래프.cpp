#include<bits/stdc++.h>
using namespace std;
int test,n,m;
int visit[20001];
vector<vector<int>> arr;
bool check2() {

	//1���� ����� ������ ���ؼ�
	//�ڽŰ� ���� ������ �ִ��� Ȯ���� 
	// �̺б׷������� �Ǻ��Ѵ�.
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j< arr[i].size(); j++) {
			
			int x = arr[i][j];

			if (visit[i] == visit[x]) {
				return false;
			}
		}
	}
	return true;
}
void bfs(int x) {
	visit[x] = 1;
	queue<int > q;
	q.push(x);
	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int i = 0; i < arr[x].size(); i++) {
			int ux = arr[x][i];

			//�湮���� �������� �ڽŰ� �ٸ� ���� ĥ�Ѵ�.
			if (visit[ux] == 0) {
				visit[ux] = 3 - visit[x];
				q.push(ux);
			}
			else continue;
		}
	}
	return;
}
int main() {
	cin >> test;
	while (test--) {
		memset(visit, 0, sizeof(visit));
		cin >> n >> m;
		
		//clear ���� ������ ���� ������ ������� �ʾƼ�
		// ������ ���� �� �� �� �ִ�.
		arr.clear();
		arr.resize(n + 1);
		for (int i = 0; i < m; i++) {
			int a, b; cin >> a >> b;
			arr[a].push_back(b);
			arr[b].push_back(a);
		}
		//�׷����� ��������ش�.
		

		//����Ǿ����� �ʴ� �׷����� �׷����� 
		//�̺κ��� �����ؾ��Ѵ�
		for (int i = 1; i <= n; i++) {

			//bfs�� ���ؼ� ����� ���� �ڽŰ� �ٸ� �����
			//ĥ�Ѵ�.
			if (visit[i] == 0) {
				bfs(i);
			}

		}

		if (check2() == true ) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}
	return 0;
}
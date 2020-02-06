#include<bits/stdc++.h>
using namespace std;

int n, m;

int degree[32001];
vector<vector<int>> arr;

int main() {
	cin >> n >> m;
	arr.resize(n+1);

	//���� ������ �ְ�
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		arr[a].push_back(b); //���� ������
		degree[b]++; //����������
	}

	//ť�� �ڽ����� �����°� ���� ������ �־��ش�.
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (degree[i] == 0) {
			q.push(i);
		}
	}

	while (!q.empty()) {
		int x = q.front(); //in-degree �� 0 �̴�.
		cout << x<<" ";
		q.pop();
		for (int i = 0; i < arr[x].size(); i++) {
			int kx = arr[x][i];
			degree[kx]--;

			if (degree[kx] == 0) {
				q.push(kx);
			}
		}
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define INF 99999999


int n, m, st, ed; //���ÿ� ����

vector < vector<pair<int, int>>> arr;

int dist[10001]; //�Ÿ�����
bool check[10001]; // Ȯ������


int main() {
	cin >> n >> m;

	arr.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;
		arr[a].push_back({ b,c }); // ��������Ʈ ����
	}
	cin >> st >> ed; //��� ������ ��������

	for (int i = 1; i <= n; i++) dist[i] = INF;

	dist[st] = 0;
	for (int i = 1; i <= n; i++) {
		int dist_m = INF + 1;
		int idx = -1;

		for (int j = 1; j <= n; j++) { //üũ�ȵ� ������ ���� cost ������

			if (check[j] == false && dist_m > dist[j]) {
				dist_m = dist[j];
				idx = j;
			}
		}
		check[idx] = true;
		for (int j = 0; j < arr[idx].size(); j++) {
			int to = arr[idx][j].first;
			int costt = arr[idx][j].second;

			if (dist[to] > dist[idx] + costt) {
				dist[to] = dist[idx] + costt;
			}
		}
	}
	cout << dist[ed];
	return 0;
}
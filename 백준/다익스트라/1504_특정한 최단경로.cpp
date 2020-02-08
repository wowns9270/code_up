//���⼺ x
// �ΰ��� ����
// ���Ƿ� �־��� �� ������ �ݵ�� ���
#include<bits/stdc++.h>
#define INF	99999999
using namespace std;
int n, m,e1,e2;
vector<vector<pair<int, int>>> arr;
vector<int> gogo(int st) {
	vector<int> ret;
	ret.resize(n + 1);

	for (int i = 1; i <= n; i++) {
		ret[i] = INF;
	}
	ret[st] = 0;
	priority_queue<pair<int, int>>pq;
	pq.push({ 0,st }); //ù ����

	while (!pq.empty()) {

		int x = pq.top().second;
		pq.pop();

		for (int i = 0; i < arr[x].size(); i++) {
			int ux = arr[x][i].first;
			int costt = arr[x][i].second;

			if (ret[ux] > ret[x] + costt) {
				ret[ux] = ret[x] + costt;

				pq.push({ -ret[ux] , ux });
			}
		}
	}
	return ret;
}

int main() {
	cin >> n >> m;
	arr.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;
		arr[a].push_back({ b,c });
		arr[b].push_back({ a,c });
	}//����� �׷���
	cin >> e1 >> e2;
	vector<int> a1 = gogo(1);
	//1���� e1�� e2�� �ִܰŸ��� �� �� �ְ�
	int k1 = a1[e1];
	int k2 = a1[e2];
	//a���� b�ΰ��� �ִܰ��(b->a�� ���°Ͱ� ����)
	vector<int> a2 = gogo(e1);
	vector<int> a3 = gogo(e2);
	int k3 = a2[e2]; // �ϳ��� ���Ѵ� a->b ��
	int k4 = a3[e1]; //b-> a
	int k5 = a2[n]; //a->n
	int k6 = a3[n]; // b->n
	int ret1 = k1 + k3 + k6;
	int ret2 = k2 + k4 + k5;
	int ret3 = min(ret1, ret2);
	if (ret3 >= INF) cout << -1;
	else cout << ret3;
	return 0;
}
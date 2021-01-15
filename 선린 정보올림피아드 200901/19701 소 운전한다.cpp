#include<bits/stdc++.h>
using namespace std;

int n, m;

struct mm {
	int x;
	int cost;
	int don;
};

vector<vector<mm>> arr;

int dp[100001][2];

priority_queue<mm> q;

bool operator<(mm x, mm y) {

	if (x.cost > y.cost) return true;

	return false;

}

int main() {

	cin >> n >> m;

	arr.resize(n + 1);

	memset(dp, 0x27, sizeof(dp));

	for (int i = 0; i < m; i++) {

		int a, b, c, d; cin >> a >> b >> c >> d;

		arr[a].push_back({ b,c,d });
		arr[b].push_back({ a,c,d });
	}

	dp[1][0] = 0; //������ �� �������
	dp[1][1] = 0; //��� �������

	q.push({ 1, 0 , 0 });

	while (!q.empty()) {

		int x = q.top().x;
		int y = q.top().cost; //���ݱ��� ���
		int z = q.top().don; //��� ����?

		q.pop();

		for (int i = 0; i < arr[x].size(); i++) {


			int ux = arr[x][i].x;   //����
			int uy = arr[x][i].cost; //x �� ux �� ����� ���
			int uz = arr[x][i].don;  //x �� ux �� ����� ���


			if (z == 0) { // ����� �ȸԾ��� ��

				if (dp[ux][0] > y + uy) { // �ȸ԰� ����
					dp[ux][0] = y + uy;
					q.push({ ux , y + uy , 0 });
				}

				if (dp[ux][1] > y + uy - uz) {
					dp[ux][1] = y + uy - uz;
					q.push({ ux , dp[ux][1] , 1 });
				}
			}
			else { // ����� �Ծ�����
				if (dp[ux][1] > y + uy) {
					dp[ux][1] = y + uy;
					q.push({ ux, dp[ux][1] , 1 });
				}
			}
		}
	}

		for (int i = 2; i <= n; i++) {
			cout << dp[i][1] << "\n";
		}
		return 0;

}
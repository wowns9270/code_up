#include<bits/stdc++.h>
using namespace std;
int n, m,test;
int dp[31][31];


//  x���� y���� ���� ��츦 ���ϸ�ȴ�
// ���⼭ x �� 0���� �����ϰ� y �� 1���� �����Ѵ�.

int gogo(int x, int y) {
	if (y > m) return 0;
	if (x == n) return 1;
	int& ret = dp[x][y];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = y+1; i <= m; i++) {
		ret += gogo(x + 1, i);
	}
	return ret;
}
int main() {
	cin >> test;
	while (test--) {
		cin >> n >> m;
		memset(dp, -1, sizeof(dp));
		cout<< gogo(0, 0) <<"\n";
	}
	return 0;
}
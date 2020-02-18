#include<bits/stdc++.h>
#define inf 999999999
using namespace std;

int n;
string a, b;
int dp[100001][11];

int gogo(int idx, int turn) {

	if (idx == n) {
		return 0;
	}

	int& ret = dp[idx][turn];
	if (ret != -1) return ret;

	ret = inf;
	//왼쪽으로 간다.
	//왼쪽으로 가는비용
	int cur = ((a[idx] - 48) + turn) % 10;


	int left_c = ((b[idx] - 48) + 10 - cur) % 10;
	ret = min(ret, gogo(idx + 1, (turn + left_c) % 10) + left_c);
	int right_c = (cur + 10 - (b[idx] - 48)) % 10;
	ret = min(ret, gogo(idx + 1, turn) + right_c);

	return ret;
}
int main() {
	cin >> n;
	cin >> a >> b;
	memset(dp, -1, sizeof(dp));
	cout << gogo(0, 0);
	return 0;
}
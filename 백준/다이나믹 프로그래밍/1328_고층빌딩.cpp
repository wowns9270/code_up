#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;

long long dp[101][101][101];

long long gogo(int num, int right, int left) {
	long long& ret = dp[num][right][left];

	if (num <= 0) return 0;
	else if (right <= 0 || left <= 0) return 0;

	if (ret != -1) return ret;

	ret = gogo(num - 1, right - 1, left) % mod;

	ret = (ret + gogo(num - 1, right, left - 1) % mod) % mod;
	ret = (ret + gogo(num - 1, right, left) % mod * (num - 2)) % mod;

	return ret;
}
int main() {
	int a, b, c; cin >> a >> b >> c;
	memset(dp, -1, sizeof(dp));
	dp[1][1][1] = 1;

	cout << gogo(a, b, c) << "\n";
	return 0;
}
#include<bits/stdc++.h>
#define mod 1000000009
using namespace std;

long long dp[1001][1001]; //수를 만들 때  수의 개수

long long gogo(int n, int m) {
	if (n == 0) {
		if (m == 0) return 1;
		else return 0;
	}
	if (n < 0) return 0;
	long long& ret = dp[n][m];
	if (ret != -1) return ret;
	ret = 0;
	ret = (ret % mod + gogo(n - 1, m - 1) % mod) % mod;
	ret = (ret % mod + gogo(n - 2, m - 1) % mod) % mod;
	ret = (ret % mod + gogo(n - 3, m - 1) % mod) % mod;
	return ret % mod;
}


int main() {
	int test; cin >> test;
	memset(dp, -1, sizeof(dp));
	while (test--) {
		int  n, m; cin >> n >> m;

		cout << gogo(n, m) << "\n";
	}
	return 0;
}
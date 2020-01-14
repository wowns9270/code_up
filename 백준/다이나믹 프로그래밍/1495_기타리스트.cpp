#include<bits/stdc++.h>
using namespace std;
#define INF -1293233
int arr[110], n, s, m;
int dp[110][1010];
int gogo(int idx, int sum) {
	if (sum > m || sum < 0) return INF;
	if (idx == n + 1) {
		return dp[idx][sum] = sum;
	}
	int& ret = dp[idx][sum];
	if (ret != -1) return ret;
	int a = gogo(idx + 1, sum + arr[idx]);
	int b = gogo(idx + 1, sum - arr[idx]);
	return ret = max(a, b);
}
int main() {
	cin >> n >> s >> m;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	memset(dp, -1, sizeof(dp));
	dp[0][s] = s;

	int a = gogo(1, dp[0][s]);
	if (a == INF) cout << "-1";
	else
		cout << gogo(1, dp[0][s]);
	return 0;
}
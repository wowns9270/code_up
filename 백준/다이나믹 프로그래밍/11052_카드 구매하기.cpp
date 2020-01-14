/*#include<bits/stdc++.h>
using namespace std;

int n;
int arr[1001];
int dp[1001];
int gogo(int idx) {
	if (idx <= 0) return 0;
	int& ret = dp[idx];
	if (ret != -1) return dp[idx];
	for (int i = 1; i <= idx; i++) {
		ret = max(ret, gogo(idx - i) + arr[i]);
	}
	return ret;
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];

	memset(dp, -1, sizeof(dp));
	dp[0] = 0;
	cout << gogo(n);
}*/
#include<bits/stdc++.h>
using namespace std;
int arr[1001];
int dp[1001];
int main() {
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	dp[0] = 0;
	dp[1] = arr[1];
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i] = max(dp[i], dp[i - j] + arr[j]);
		}
	}
	cout << dp[n];
	return 0;
}
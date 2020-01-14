//#include<bits/stdc++.h>
//using namespace std;
//int t[1500001], p[1500001], n;
//int dp[1500001];
//int main() {
//	cin >> n;
//	for (int i = 0; i < n; i++) { cin >> t[i] >> p[i]; }
//	for (int i = 0; i < n; i++) {
//		dp[i + t[i]] = max(dp[i + t[i]], dp[i] + p[i]);
//		dp[i + 1] = max(dp[i + 1], dp[i]);
//	}
//	cout << dp[n];
//	return 0;
//}
#include<bits/stdc++.h>
using namespace std;
#define INF -19237322
int n;
int t[1500000];
int p[1500000];
int dp[1500001];
int gogo(int idx) {
	if (idx > n) return INF;
	if (idx == n) return 0;
	int& ret = dp[idx];
	if (ret != -1) return ret;
	int a = gogo(idx + t[idx]) + p[idx];
	int b = gogo(idx + 1);
	ret = max(a, b);
	return ret;
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> t[i] >> p[i];
	}
	memset(dp, -1, sizeof(dp));
	cout << gogo(0);
	return 0;
}
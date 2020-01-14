//#include<bits/stdc++.h>
//using namespace std;
//#define INF 19999999
//int n;
//int arr[1010];
//int dp[1010];
//int gogo(int idx) {
//	if (idx >= n) return INF;
//	if (idx == n - 1) return 0;
//	int& ret = dp[idx];
//	if (ret != -1) return ret;
//	ret = INF;
//	for (int i = idx; i <= idx + arr[idx]; i++) {
//		ret = min(ret,1+gogo(i));
//	}
//	return ret;
//}
//
//
//
//int main() {
//	cin >> n;
//	for (int i = 0; i < n; i++) cin >> arr[i];
//	memset(dp, -1, sizeof(dp));
//	int a = gogo(0);
//	if (a >= INF) cout << "-1";
//	else
//	cout<<gogo(0);
//	return 0;
//}
#include<bits/stdc++.h>
using namespace std;
int arr[1010];
int dp[1010];
int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	for (int i = 0; i <= 1010; i++) dp[i] = 1099999;
	dp[0] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j <= i + arr[i]; j++) {
			dp[j] = min(dp[j], dp[i] + 1);
		}
	}
	if (dp[n - 1] == 1099999) cout << "-1";
	else
		cout << dp[n - 1];
	return 0;
}

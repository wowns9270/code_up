#include<bits/stdc++.h>
using namespace std;

int arr[1001][1001];
int dp[1001][1001];
int n, m;
int gogo(int i, int j) {
	// 예외를 처리한다
	if (i < 1 || j < 1) return 0;
	//이미 왔던 곳이라면 거기서 부터 시작
	if (dp[i][j] >= 0) {
		return dp[i][j];
	}
	dp[i][j] = max(gogo(i - 1, j), gogo(i, j - 1)) + arr[i][j];
	return dp[i][j];
}

int main() {
	cin >> n >> m;
	memset(dp, -1, sizeof(dp));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
		}
	}
	cout << gogo(n, m);
	return 0;
}
#include<bits/stdc++.h>
using namespace std;

int n, m;
int arr[501][501];
int dp[501][501];

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

int gogo(int x, int y) {

	if (x == n && y == m) return 1;

	int& ret = dp[x][y];
	if (ret != -1) return ret;
	ret = 0;

	for (int i = 0; i < 4; i++) {
		int ux = x + dx[i];
		int uy = y + dy[i];

		if (ux < 1 || uy < 1 || ux > n || uy > m) continue;

		if (arr[x][y] > arr[ux][uy]) {
			ret += gogo(ux, uy);
		}
	}
	return ret;
}



int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
		}
	}

	memset(dp, -1, sizeof(dp));
	cout << gogo(1, 1);
	return 0;
}
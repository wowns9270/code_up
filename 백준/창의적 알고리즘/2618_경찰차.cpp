#include<bits/stdc++.h>
#define inf 999999999
using namespace std;

int n, m;
vector<pair<int, int>> arr;
int dp[1001][1001];
int check[1001][1001];

int gogo(int x1, int x2) { // 두 경찰차 위치

	if (x1 >= m + 1 || x2 >= m + 1) {
		return 0;
	}

	int& ret = dp[x1][x2];
	if (ret != -1) return ret;

	ret = inf;

	int k = max(x1, x2) + 1; //다음 목적지

	int a = gogo(k, x2) + (abs(arr[x1].first - arr[k].first) +
		abs(arr[x1].second - arr[k].second));

	int b = gogo(x1, k) + (abs(arr[x2].first - arr[k].first) +
		abs(arr[x2].second - arr[k].second));


	if (a <= b) {
		check[x1][x2] = 1;
	}

	else check[x1][x2] = 2;

	return ret = min(a, b);
}


int main() {
	cin >> n >> m;
	//두 경찰차 위치
	arr.push_back({ 1,1 });
	arr.push_back({ n, n });
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		arr.push_back({ a,b });
	}
	memset(dp, -1, sizeof(dp));
	cout << gogo(0, 1) << "\n";

	int x = 0;
	int y = 1;
	int idx = 2;
	while (1) {
		cout << check[x][y] << "\n";
		if (x == m || y == m) break;

		if (check[x][y] == 1) {
			x = idx;
		}
		else {
			y = idx;
		}
		idx++;
	}
	return 0;
}
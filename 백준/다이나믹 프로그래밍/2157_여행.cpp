#include<bits/stdc++.h>
#define inf -999999999
using namespace std;

int n, m, k;

vector<vector<pair<int, int>>> arr;
int dp[301][301]; // i번도시를 n개로 방문했을 때 최대 기내식 점수

int gogo(int idx, int cnt) {

	if (idx == n) {
		if (cnt <= m) {
			return 0;
		}
		return inf;
	}
	int& ret = dp[idx][cnt];
	if (ret != -1) return ret;

	ret = inf;

	for (int i = 0; i < arr[idx].size(); i++) {
		int to = arr[idx][i].first; // 위치로
		int costt = arr[idx][i].second;

		if (idx > to) continue;

		ret = max(ret, gogo(to, cnt + 1) + costt);
	}
	return ret;
}



int main() {
	cin >> n >> m >> k;
	arr.resize(n + 1);
	while (k--) {
		int a, b, c; cin >> a >> b >> c;
		arr[a].push_back({ b, c });
	}
	memset(dp, -1, sizeof(dp));
	cout << gogo(1, 1);
	return 0;
}
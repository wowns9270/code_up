#include<bits/stdc++.h>
using namespace std;

int n, ans;
vector<pair<int, int>> arr;

bool cmp(pair<int, int> x, pair<int, int> y) {
	if (x.first < y.first) {
		return true;
	}
	return false;
}
int dp[101];

int gogo(int idx) {

	if (idx >= n) {
		return 0;
	}

	int& ret = dp[idx];
	if (ret != -1) return ret;
	ret = 1;

	for (int i = idx + 1; i < n; i++) {
		if (arr[idx].second < arr[i].second) {
			ret = max(ret, gogo(i) + 1);
		}
	}
	return ret;

}


int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		arr.push_back({ a,b });
	}
	sort(arr.begin(), arr.end(), cmp);

	for (int i = 0; i < n; i++) {
		memset(dp, -1, sizeof(dp));
		int k = gogo(i);
		ans = max(ans, k);
	}

	cout << n - ans;
	return 0;
}
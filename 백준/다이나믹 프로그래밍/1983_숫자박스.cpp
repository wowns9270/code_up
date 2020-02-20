#include<bits/stdc++.h>
#define inf -40000
using namespace std;


int n, e1, e2;
int dp[405][405][405];
int arr[401];
int arr2[401];
int gogo(int idx, int c1, int c2) {

	if (c1 == e1 || c2 == e2) {
		return 0;
	}

	int& ret = dp[idx][c1][c2];
	if (ret != inf) return ret;

	ret = inf;

	if (e1 - c1 + idx < n)
		ret = max(ret, gogo(idx + 1, c1, c2 + 1));
	if (e2 - c2 + idx < n)
		ret = max(ret, gogo(idx + 1, c1 + 1, c2));

	return ret = max(ret, gogo(idx + 1, c1 + 1, c2 + 1)
		+ arr[c1] * arr2[c2]);
}
int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n;

	int idx = 0;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		if (a == 0) continue;

		arr[idx++] = a;
		e1++;
	}
	idx = 0;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		if (a == 0) continue;

		arr2[idx++] = a;
		e2++;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				dp[i][j][k] = inf;
			}
		}
	}
	cout << gogo(0, 0, 0);
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
ifstream in("card.inp");
ofstream out("card.out");
int arr[1001],n, dp[2][1001][1001];
int gogo(int turn, int r, int l) {
	if (r > l) return 0;
	int& ret = dp[turn][r][l];
	if (ret != -1) return ret;
	if (turn == 0) {
		int a = gogo(1, r, l - 1) + arr[l];
		int b = gogo(1, r + 1, l) + arr[r];
		return ret = max(a, b);
	}
	else {
		int a = gogo(0, r, l - 1);
		int b = gogo(0, r + 1, l);
		return ret = min(a, b);
	}
}
int main() {
	int test; in >> test;
	while (test--) {
		in >> n;
		for (int i = 0; i < n; i++) in >> arr[i];
		memset(dp, -1, sizeof(dp));
		out<< gogo(0, 0, n - 1)<<"\n";
	}
	return 0;
}
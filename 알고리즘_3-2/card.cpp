#include<bits/stdc++.h>
using namespace std;
ifstream in("card.inp");
ofstream out("card.out");
#define INF -1999999
int  n, arr[1010], dp[1010][1010];
int gogo(int idx, int pre) {
	if (idx == 4 && pre == 2) return INF;
	if (idx == n + 1) return 0;
	if (idx > n + 1) return INF;
	int& ret = dp[idx][pre];
	if (ret != -1) return ret;
	if (idx - pre == 2) {
		int b = gogo(idx + 3, idx) + arr[idx + 3];
		int c = gogo(idx + 4, idx) + arr[idx + 4];
		return ret = max(b, c);
	}
	else {
		int a = gogo(idx + 2, idx) + arr[idx + 2];
		int b = gogo(idx + 3, idx) + arr[idx + 3];
		int c = gogo(idx + 4, idx) + arr[idx + 4];
		ret = max(a, b);
		ret = max(ret, c);
		return ret;
	}
}
int main() {
	int test; in >> test;
	while (test--) {
		in >> n;
		for (int i = 2; i < n + 2; i++) in >> arr[i];
		memset(dp, -1, sizeof(dp));
		out << gogo(0, 0) << "\n";  // 인덱스와 이전과 현재 선택
	}
	return 0;
}
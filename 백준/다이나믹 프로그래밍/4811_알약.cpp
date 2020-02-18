#include<bits/stdc++.h>
using namespace std;

int n;
long long dp[31][31][31][31][31]; //총개수 1의개수 시작과 끝

long long gogo(int k, int f_1, int f_2, int l_1, int l_2) {
	//처음은 1 0           0 1 상태

	if (f_1 + l_1 > n) return 0;
	if (f_2 + l_2 > n) return 0;
	
	if (f_1 < f_2) return 0;
	if (l_1 > l_2) return 0;
	
	if (k == 0) return 1;

	long long& ret = dp[n][f_1][f_2][l_1][l_2];
	if (ret != -1) return ret;
	ret = 0;

	//w w
	ret += gogo(k - 1, f_1 + 1, f_2, l_1 + 1, l_2);
	ret += gogo(k - 1, f_1 + 1, f_2, l_1, l_2 + 1);
	ret += gogo(k - 1, f_1, f_2 + 1, l_1 + 1, l_2);
	ret += gogo(k - 1, f_1, f_2 + 1, l_1, l_2 + 1);
	return ret;
}
int main() {

	ios_base::sync_with_stdio(NULL);
	cin.tie(0), cout.tie(0);
	memset(dp, -1, sizeof(dp));
	while (1) {
		cin >> n;
		if (n == 0) break;
		cout << gogo(n-1, 1, 0, 0, 1) << "\n"; //1이 완 제품 0이 반개
	}
	return 0;
}
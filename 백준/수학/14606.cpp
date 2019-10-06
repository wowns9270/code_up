#include<cstdio>
#pragma warning(disable:4996)
using namespace std;

int dp[11];

//피자 문제인데
//사실 디피도 아닌걸 풀다가 알았다.
//  1  2  3  4  5   6   7   8   9
//  0  1  3  6  10  15  21  28  36
// 규칙은 계차수열이였는데 구현은 디피로 구현했다.
int main() {
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 3;


	int n; scanf("%d", &n);
	for (int i = 4; i <= n; i++) {

		if (i % 2 == 0) {
			dp[i] = (i / 2) * (i / 2);
			dp[i] += dp[i / 2];
			dp[i] += dp[i / 2];
		}
		else {
			dp[i] = (i / 2) * (i / 2 + 1);
			dp[i] += dp[i / 2];
			dp[i] += dp[i / 2 + 1];
		}
	}

	printf("%d", dp[n]);
}
#include<cstdio>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;

int dp[1000000];
// dp 1로 만들기 
int main() {
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;

	int n; scanf("%d", &n);
	for (int i = 4; i <= n; i++) {
		dp[i] = dp[i - 1] + 1;

		if(i%2==0)
		dp[i] = max(dp[i], dp[i / 2] + 1);

		if (i % 3 == 0)
		dp[i] = max(dp[i], dp[i / 3] + 1);
	}
	printf("%d", dp[n]);
	return 0;
}
#include<cstdio>
#pragma warning(disable:4996)
using namespace std;


int dp[2][1001];

int main() {
	int n; scanf("%d", &n);

	dp[0][1] = 1;dp[1][1] = 2;
	dp[0][2] = 2;dp[1][2] = 1;
	dp[0][3] = 1;dp[1][3] = 2;
	dp[0][4] = 1;dp[1][4] = 2;

	for (int i = 5; i <= n; i++) {
		if (dp[1][i - 1] == 1 || dp[1][i - 3] == 1 || dp[1][i - 4] == 1) {
			dp[0][i] = 1;
			dp[1][i] = 2;
		}
		else {
			dp[0][i] = 2;
			dp[1][i] = 1;
		}
	}

	if (dp[0][n] == 1) printf("SK");
	else printf("CY");
	return 0;
}
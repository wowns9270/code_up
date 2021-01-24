#include<bits/stdc++.h>
using namespace std;

long long dp[31][31];


int main() {
	dp[0][0] = 1;


	for (int i = 1; i <= 30; i++) {

		for (int j = 0; j <= i; j++) {

			if (j == 0) dp[i][j] = 1;
			else if (i == j) dp[i][j] = dp[i][j - 1];
			else {
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}
	}

	int a, b; cin >> a >> b;
	int k = abs(a - b);

	cout << dp[k][k];
	return 0;
}
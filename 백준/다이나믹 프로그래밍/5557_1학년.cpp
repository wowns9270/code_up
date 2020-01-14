#include<bits/stdc++.h>
using namespace std;

int n, arr[101];
long long dp[101][101];

long long gogo(int idx,int sum) {

	if (idx == n - 1) {

		if (sum == arr[n - 1]) {
			return dp[idx][sum] = 1;
		}
		else return dp[idx][sum] = 0;
	}

	long long& ret = dp[idx][sum];
	if (ret != -1) return ret;
	
	ret = 0;
	if (sum + arr[idx] <= 20) {
		ret += gogo(idx + 1, sum + arr[idx]);
	}
	if (sum - arr[idx] >= 0) {
		ret += gogo(idx + 1, sum - arr[idx]);
	}

	return ret;
}


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	
	memset(dp, -1, sizeof(dp));
	dp[0][arr[0]] = 0;
	cout<<gogo(1, arr[0]);

}
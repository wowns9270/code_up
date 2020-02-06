#include<bits/stdc++.h>
using namespace std;
#define INF	-199999999
int n,m;
int arr[50001];
int sum[50001];
int dp[3][50001];

//처음에 너무 이상하게 풀었다.
//idx번째를 선택하면 idx부터 뒤에 m개를 선택한다라고 생각해야하는데
//선택하지 않으면 idx +1 하고 cnt 그대로 하면되는것을
//나는 첫화물이 선택하는 가짓수 12 23 34 이렇게 다 해버렸다
//왜 안되는지는 모르겠는데 이방법이 훨씬 간결하다


int gogo(int cnt, int idx) {
	if (cnt >= 3) return 0;
	if (idx > n) return 0;
	int& ret = dp[cnt][idx];
	if (ret != -1) return ret;
	
	
	int a = gogo(cnt, idx + 1);
	int b = gogo(cnt + 1, idx + m) + sum[idx + m - 1] - sum[idx - 1];
	ret = max(a, b);
	return ret;
}
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];

		sum[i] += sum[i-1] + arr[i];
	}
	cin >> m;
	memset(dp, -1, sizeof(dp));
	cout<< gogo(0, 1);
	return 0;
}
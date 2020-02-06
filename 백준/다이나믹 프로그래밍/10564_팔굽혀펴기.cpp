#include<bits/stdc++.h>
using namespace std;

int test, n, m,arr[5001];
bool dp[5001][500]; //i번 팔굽했을 때 j 득점으로 할수 있냐?


//중복문제 계산이 아닌거같다.
//팔굽혀펴기 수 와 그때 득점한 점수를 인자로 두면
// 그것이 가능하다고 체크해주고 팔굽보다 높은 수가되면 리턴한다.
bool gogo(int push, int score) {
	if (push > n) return false;
	bool& ret = dp[push][score];
	if (ret == true) return ret;
	ret = true;
	for (int i = 0; i < m; i++) {
		gogo(push + score + arr[i], score + arr[i]);
	}
	return ret;
}
int main() {
	cin >> test;
	while (test--) {
		cin >> n >> m;
		for (int i = 0; i < m; i++) cin >> arr[i];

		memset(dp, false, sizeof(dp));
		gogo(0, 0);

		int k = -1;
		for (int i = 1; i <= 500; i++) {
			if (dp[n][i] == true) {
				k = i;
			}
		}
		if (k == -1) cout << "-1\n";
		else cout << k<<"\n";
	}
	return 0;
}
#include<cstdio>
#include<memory.h>
#pragma warning(disable:4996)
using namespace std;
#define inf 1000000000

int dp[201][201]; // 행은 k 개수 , 열은 n 정수.


//bottom up
int main() {
	int n, k; scanf("%d %d", &n, &k);

	for (int i = 1; i <= k; i++) {
		for (int j = 0; j <= n; j++) {
			if (i == 1 || j == 0) {
				dp[i][j] = 1;
				continue;
			}
			else {
				dp[i][j] = (dp[i][j - 1] % inf + dp[i - 1][j] % inf) % inf;
			}
		}
	}


	printf("%d", dp[k][n]);
	return 0;
}



int gogo(int num, int cnt) {
	int& ret = dp[num][cnt]; //숫자 뒤에 개수

	if (ret != -1) return ret;

	if (num == 0 || cnt == 1) return 1;

	ret = (gogo(num - 1, cnt)%inf + gogo(num, cnt - 1)%inf)%inf;

	return ret;
}





int main() {
	int n, k; scanf("%d %d", &n, &k);

	memset(dp, -1, sizeof(dp));
	printf("%d", gogo(n, k));
	return 0;
}


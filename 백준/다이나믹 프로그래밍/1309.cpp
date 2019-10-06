#include<cstdio>
#pragma warning(disable:4996)
using namespace std;
#define inf 9901

int dp[100001][3];

//사자 배치 문제
//접근은 사자를 배치하는 경우는 오른쪽 왼쪽 그리고 배치하지 않는경우
//             0   1   2
//1인경우       1   1   1      이렇게 각각 하나씩
//2인경우       2   2   3      오른쪽이면 위에서 왼쪽과 배치x 인경우를 더해준다
//3인경우       5   5   7      배치를 안하는경우는 그전의 모든 배치가 가능
//4            12  12  21     예제의 답이 떴을 때 확신했고


//우리가 구하는것은 n칸일때 모든 경우니까 즉  
//dp[n][0]과 dp[n][1] 과 dp[n][2] 를 모두 더하면 사자를 배치하는 
//모든 경우가 나온다 끝.



int main() {
	dp[1][0] = 1;
	dp[1][1] = 1;
	dp[1][2] = 1;

	int n; scanf("%d", &n);
	for (int i = 2; i <= n; i++) {

		for (int j = 0; j < 3; j++) {
			
			if (j == 0) {
				dp[i][j] = (dp[i - 1][1] + dp[i - 1][2])%inf;
			}
			else if (j == 1) {
				dp[i][j] = (dp[i - 1][0] + dp[i - 1][2])%inf;
			}
			else {
				dp[i][j] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2])%inf;
			}
		}
	}

	printf("%d", (dp[n][0] + dp[n][1] + dp[n][2])%inf);
	return 0;
}
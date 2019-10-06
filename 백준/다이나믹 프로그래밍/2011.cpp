#include<cstdio>
#pragma warning(disable:4996)
using namespace std;
#define inf 1000000


int arr[5001]; // 5000자리의 암호
int dp[5001];  //dp

//2011 암호코드


int main() {
	
	int n = 1;
	int a;

	//입력 문자열로 받을수 있지만
	// 숫자 판별이 편해 int 로 받음
	while (scanf("%1d",&a)!=EOF) {
		arr[n] = a;
		n++;
	}


	//첫 숫자가 0이면 암호 불가 .. 0을 출력
	if (arr[1] == 0) {
		printf("0");
		return 0;
	}


	//첫 숫자가 0이 아니면 dp[1] =1 이고 
	//두번째 숫자가 첫번째 수와 합이 조건에 가능하면
	//2가 되어야 해서 dp[0] = 1 이라고 초기화 해줘야함
	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2; i < n; i++) {
		
		//0이 아니면 그전의 조합을 그대로 가지므로
		//dp[i] = dp[i-1]+dp[i];
		if (arr[i] != 0) {
			dp[i] = (dp[i - 1]+dp[i]) % inf;
		}


		//그 전의 값과 합을 구한다.
		int k = arr[i - 1] * 10 + arr[i];

		//합칠수 있다면 dp[i-2] 합을 더한다 
		//여기서 k==10 이면 위의 if 에서 dp[i] =0 일것이고
		//210 이런식이면 즉 dp[1] =1 이고 dp[3] = 1 이 되는 것이다.
		if (k >= 10 && k <= 26) {
			dp[i] = (dp[i] + dp[i - 2]) % inf;
		}
	}

	printf("%d", dp[n-1]);
	return 0;
}


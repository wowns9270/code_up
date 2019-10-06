#include<cstdio>
#pragma warning(disable:4996)
using namespace std;

int dp[1000001];


// �̰͵� dp��⿣ �׷�����.
//�з��� dp�� Ǯ���µ�
// ��Ģ�� ����
// 1  2  3  4  5   6   7   8  9
// 0  1  7  4  8  14  11  15  21

//���� dp[i] = dp[i-3] �� 7�� ���ѰͰ� ����.
//�׷��� dp[n]�� ���ϸ� ��/.
int main() {
	int n; scanf("%d", &n);

	dp[1] = 0;dp[2] = 1;
	dp[3] = 7;dp[4] = 4;

	for (int i = 5; i <= n; i++) {
			dp[i] = dp[i - 3] + 7;
	}

	printf("%d", dp[n]);
	return 0;

}
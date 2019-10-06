#include<cstdio>
#pragma warning(disable:4996)
using namespace std;
#define inf 1000000


int arr[5001]; // 5000�ڸ��� ��ȣ
int dp[5001];  //dp

//2011 ��ȣ�ڵ�


int main() {
	
	int n = 1;
	int a;

	//�Է� ���ڿ��� ������ ������
	// ���� �Ǻ��� ���� int �� ����
	while (scanf("%1d",&a)!=EOF) {
		arr[n] = a;
		n++;
	}


	//ù ���ڰ� 0�̸� ��ȣ �Ұ� .. 0�� ���
	if (arr[1] == 0) {
		printf("0");
		return 0;
	}


	//ù ���ڰ� 0�� �ƴϸ� dp[1] =1 �̰� 
	//�ι�° ���ڰ� ù��° ���� ���� ���ǿ� �����ϸ�
	//2�� �Ǿ�� �ؼ� dp[0] = 1 �̶�� �ʱ�ȭ �������
	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2; i < n; i++) {
		
		//0�� �ƴϸ� ������ ������ �״�� �����Ƿ�
		//dp[i] = dp[i-1]+dp[i];
		if (arr[i] != 0) {
			dp[i] = (dp[i - 1]+dp[i]) % inf;
		}


		//�� ���� ���� ���� ���Ѵ�.
		int k = arr[i - 1] * 10 + arr[i];

		//��ĥ�� �ִٸ� dp[i-2] ���� ���Ѵ� 
		//���⼭ k==10 �̸� ���� if ���� dp[i] =0 �ϰ��̰�
		//210 �̷����̸� �� dp[1] =1 �̰� dp[3] = 1 �� �Ǵ� ���̴�.
		if (k >= 10 && k <= 26) {
			dp[i] = (dp[i] + dp[i - 2]) % inf;
		}
	}

	printf("%d", dp[n-1]);
	return 0;
}


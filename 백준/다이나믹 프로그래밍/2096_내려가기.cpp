#include<bits/stdc++.h>
using namespace std;

int arr[100002][3];
int dp[2][3];
int dp2[2][3];
int n;

//���Ҿ� ����� ���� �� ���� �ʴµ�
//��ͷ� ��� ¥������ �𸣰ڴ�.
//�������� �������� ����Ҷ��� ����ϰ� ������ �ʿ䰡����
//�׷��� dp[100001][3] ���� ����� �޸� �ʰ��� ���..
//�̻���
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
	}

	for (int i = 1; i <= n; i++) {
		
		int cur = i % 2;
		int pre = (i-1) % 2;

		dp[cur][0] = max(dp[pre][0], dp[pre][1]) + arr[i][0];
		dp[cur][1] = max({ dp[pre][0], dp[pre][1],dp[pre][2] }) + arr[i][1];
		dp[cur][2] = max(dp[pre][1], dp[pre][2]) + arr[i][2];

		dp2[cur][0] = min(dp2[pre][0], dp2[pre][1]) + arr[i][0];
		dp2[cur][1] = min({ dp2[pre][0], dp2[pre][1],dp2[pre][2] }) + arr[i][1];
		dp2[cur][2] = min(dp2[pre][1], dp2[pre][2]) + arr[i][2];
	}

	cout << max({ dp[n % 2][0],dp[n % 2][1],dp[n % 2][2] }) << " ";
	cout << min({ dp2[n % 2][0],dp2[n % 2][1],dp2[n % 2][2] });
	return 0;
}
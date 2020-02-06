#include<bits/stdc++.h>
using namespace std;
#define INF	-199999999
int n,m;
int arr[50001];
int sum[50001];
int dp[3][50001];

//ó���� �ʹ� �̻��ϰ� Ǯ����.
//idx��°�� �����ϸ� idx���� �ڿ� m���� �����Ѵٶ�� �����ؾ��ϴµ�
//�������� ������ idx +1 �ϰ� cnt �״�� �ϸ�Ǵ°���
//���� ùȭ���� �����ϴ� ������ 12 23 34 �̷��� �� �ع��ȴ�
//�� �ȵǴ����� �𸣰ڴµ� �̹���� �ξ� �����ϴ�


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
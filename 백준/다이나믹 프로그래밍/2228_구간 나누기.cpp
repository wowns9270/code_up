//���� ��ġ ���� �� ? 3276800
#include<bits/stdc++.h>
#define inf -99999999
using namespace std;

int n, m;
int arr[101];
int dp[101][51][2];

int gogo(int idx, int cnt, int check) {
	if (idx == n) {
		if (cnt == m) {
			return 0;
		}
		return inf;
	}
	int& ret = dp[idx][cnt][check];
	if (ret != -1) return ret;
	ret = inf;
	if (check == 0) {//������ ������ �˸���.
		//���ܿ� �������� �ʴ´�
		ret = max(ret, gogo(idx + 1, cnt, 0));
		//������ �����Ѵ�
		ret = max(ret, gogo(idx + 1, cnt + 1, 1) + arr[idx]);
	}
	else {
		//���Ƽ� �� ������ �����Ѵ�. 
		ret = max(ret, gogo(idx + 1, cnt, 1) + arr[idx]);
		//���� �ױ����� �����Ѵ�.
		ret = max(ret, gogo(idx + 1, cnt, 0));
	}
	return ret;
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	memset(dp, -1, sizeof(dp));
	cout << gogo(0, 0, 0);
}
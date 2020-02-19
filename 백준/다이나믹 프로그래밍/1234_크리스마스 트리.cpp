#include<bits/stdc++.h>
using namespace std;
	
int n, r, b, g;

long long dp[11][101][101][101];

long long c[11][11];

long long gogo(int idx, int red, int blue, int green) {

	if (red < 0 || blue < 0 || green < 0) {
		return 0;
	}
	if (idx == n + 1 ) return 1;
	long long& ret = dp[idx][red][blue][green];
	if (ret != -1) return ret;

	ret = 0;
	ret += gogo(idx + 1, red - idx, blue, green);
	ret += gogo(idx + 1, red, blue - idx, green);
	ret += gogo(idx + 1, red, blue, green - idx);
	if (idx % 2 == 0) {//¦�� ���̸�  ������ �ϳ� �Ǵ� �ΰ��θ� ����
		//3������ ���� ������ �� �޾� ������~ �̸��̾�

		ret += gogo(idx + 1, red - idx / 2, blue - idx / 2, green) *c[idx][idx/2];
		ret += gogo(idx + 1, red - idx / 2, blue , green - idx / 2) * c[idx][idx / 2];
		ret += gogo(idx + 1, red , blue - idx / 2, green - idx / 2) * c[idx][idx / 2];

	}
	 // Ȧ����� �ù� 3���� �� ���� �������� ���� ������ 
		// �ѻ���� �ϴ� �� �ƴϸ�
	if (idx % 3 == 0) {//3���� ���� ����
		ret += gogo(idx + 1, red - idx / 3, blue - idx / 3, green - idx / 3) * c[idx][idx / 3] * c[idx - idx / 3][idx / 3];
	}
	return ret;
}
int main() {
	cin >> n >> r >> b >> g;

	c[0][0] = 1;
	for (int i = 1; i <= 10; i++) {
		c[i][0] = c[i][i] = 1;
		for (int j = 1; j < i; j++) {
			c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
		}
	}

	memset(dp, -1, sizeof(dp));
	cout<< gogo(1, r, b, g)<<"\n";
	return 0;
}
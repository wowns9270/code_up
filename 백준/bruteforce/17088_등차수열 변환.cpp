#include<bits/stdc++.h>
using namespace std;
#define INF 19999999
int n,ret=INF;
int arr[100001];
int k[] = { -1,0,1 };

// -1 0 1 �� ��� ��쿡 �غ���� ������ n�� ���� 10^5�̹Ƿ� ����
// �׷��� ������ ����� ���� 5���� ���̴ϱ�.
//������ ��쿡 �Ǵ� ������ ����غô�.
//������ �������� ù���� �̸� �����ְ� �������� �Ұ�������
//�Ǵ��Ѵ��� ������ ���� ��� �󸶳� +1 -1 �� �ߴ��� �̾����.
//�ð����⵵�� 5 * 3 * 10^5�̶� ����ϱ��ϴ�
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int ch = arr[1] - arr[0];
	for (int i = ch - 2; i <= ch + 2; i++) {//5���� ��츦 �غ���.
		int st = 0;
		int ans = 0;
		for (int j = 0; j < 3; j++) {
			st = arr[0] + k[j];
			if (j == 1) ans = 0;
			else ans = 1;
		bool check = true;
		for (int k = 1; k < n; k++) {
			if ( abs((st + i) - arr[k])  > 1) {
				check = false;
				break;
			}
			else {
				ans += abs(st+i - arr[k]);
				st = st + i;
			}
		}

		if (check == false) continue;
		ret = min(ret, ans);
		}
	}
	if (ret == INF) cout << "-1";
	else cout << ret;
	return 0;
}
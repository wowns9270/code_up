#include<bits/stdc++.h>
using namespace std;

char arr[21][21];
//�׸���� ��Ʈ����ũ�� �̿��� Ǯ��
//��� �� ���¸� ���� ���� �ִ� 2^n*2^n*n^2 �ʹ� ��찡 ���Ƽ� �����
//�ุ ������Ű�� ���� ������ ���� �������� �����ϸ� �ǹǷ�
//2^n * n^2 =   �ִ� 419,430,400��  4�� ������ �����ϴ�
int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	int ret = 0;
	int ans = 4000;
	for (int i = 0; i < (1 << n); i++) { //��Ʈ����
		ret = 0;
		for (int j = 0; j < n; j++) { //�� ��
			int sum = 0;
			for (int k = 0; k < n; k++) { //��
				char go = arr[k][j];
				if (i & (1 << k)) {
					go == 'H' ? go = 'T' : go = 'H';
				}

				if (go == 'H') sum++; //SUM ������ H
			}
			sum = min(sum, n - sum);
			ret += sum;
		}
		ans = min(ans, ret);
	}
	cout << ans;
	return 0;
}
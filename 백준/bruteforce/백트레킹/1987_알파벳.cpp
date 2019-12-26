#include<iostream>
#include<algorithm>
using namespace std;

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

char arr[21][21];
bool check[26];
int ret = 1;
int n, m;

int bruteforce(int x, int y, int cnt) {

	//4���� �����߿�
	for (int i = 0; i < 4; i++) {
		int ux = x + dx[i];
		int uy = y + dy[i];

		//�ϴ� �Ǿȿ� �ְ�
		if (ux >= 1 && uy >= 1 && ux <= n && uy <= m) {
			//�� ���� ���ĺ��� ���ο� ���̸�
			if (check[arr[ux][uy] - 65] == false) {
				//�湮ǥ�� 
				check[arr[ux][uy] - 65] = true;
				//����Ž��
				bruteforce(ux, uy, cnt + 1);
				//������ ��湮�� �ٸ����� ����
				check[arr[ux][uy] - 65] = false;
			}
		}
	}

	//�� �̻� �� �� �� ���� ��� ���� ū �� ��ȯ
	return ret = max(cnt, ret);
}

int main() {
	//���ĺ� ����Ž��
	cin >> n >> m;
	//�Է�
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
		}
	}
	//ó��ĭ�� �湮 ǥ�� �ϰ� 
	check[arr[1][1] - 65] = true;
	//Ž��
	cout << bruteforce(1, 1, 1);
}
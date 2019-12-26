#include<iostream>
using namespace std;

int arr[9][9];
bool low_s[10][10];
bool col_s[10][10];
bool box_s[10][10];

int check(int x, int y) {
	return (x / 3) * 3 + (y / 3);
}

void back(int cnt) {
	//������� �°��̸� ��ĭ �� ���� �Ȱ��̹Ƿ� 
	//���������� �̾��ش�
	if (cnt == 81) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << arr[i][j] << " ";
			}
			cout << "\n";
		}
		exit(0);
	}

	//��ĭ�̶��
	//�ĺ� 1~9���� �����Ѱ��� ����ִ� �۾�
	if (arr[cnt / 9][cnt % 9] == 0) {
		for (int i = 1; i <= 9; i++) {
			if (low_s[cnt / 9][i] == false && col_s[cnt % 9][i] == false
				&& box_s[check(cnt / 9, cnt % 9)][i] == false) {
				low_s[cnt / 9][i] = true;
				col_s[cnt % 9][i] = true;
				box_s[check(cnt / 9, cnt % 9)][i] = true;
				arr[cnt / 9][cnt % 9] = i;
				back(cnt + 1);
				arr[cnt / 9][cnt % 9] = 0;
				low_s[cnt / 9][i] = false;
				col_s[cnt % 9][i] = false;
				box_s[check(cnt / 9, cnt % 9)][i] = false;

			}
		}
	}
	//��ĭ�� �ƴϸ� ���� �۾�
	else back(cnt + 1);
}
int main() {
	//�������� ��Ʈ��ŷ 
	//�Է��� �����鼭 ��� �� �׸��� �ڽ��� ���� ���¸� �����Ų��.
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> arr[i][j];
			if (arr[i][j] != 0) {
				low_s[i][arr[i][j]] = true;
				col_s[j][arr[i][j]] = true;
				box_s[check(i, j)][arr[i][j]] = true;
			}
		}
	}
	//����
	back(0);
}
#include<bits/stdc++.h>
using namespace std;
#define INF 1999999
int arr[10][10],ret =INF;
int paper[] = { 0,5,5,5,5,5 };
bool check(int x, int y, int size) {
	if (x + size > 10 || y + size > 10) return false;
	for (int i = x; i < x + size; i++) {
		for (int j = y; j < y + size; j++) {
			if (arr[i][j] == 0) {
				return false;
			}
		}
	}
	return true;
}
void gogo(int cnt) {
	int x = cnt / 10;
	int y = cnt % 10;    // x��ǥ y��ǥ
	if (cnt == 100) {
		int k = 25;
		for (int i = 1; i <= 5; i++) k -= paper[i];
		ret = min(ret, k);
		return;
	}
	if (arr[x][y] == 0) gogo(cnt + 1);
	else {
		for (int i = 1; i <= 5; i++) {
			if (check(x, y, i) == true) //���簢�� ������ (i) ��ŭ Ȯ��
			{
				paper[i]--; // ���� ����
				if (paper[i] < 0) { //���̰� �����ϸ� �������
					paper[i] ++;
					continue;
				}
				for (int j = x; j < x + i; j++) {
					for (int k = y; k < y + i; k++) {
						arr[j][k] = 0;
					}
				}
				gogo(cnt + 1);
				paper[i] ++;
				for (int j = x; j < x + i; j++) {
					for (int k = y; k < y + i; k++) {
						arr[j][k] = 1;
					}
				}
			}
			else break;
		}
		return;
	}
}
//�ð������ �� �ȵǱ��Ѵ� ��Ž�̶�� �ַ���� �˰�� ���� Ǯ���µ�
//ū�ź��� ã�ڴٴ� ���������� ��ű� ������


int main() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> arr[i][j];
		}
	}
	gogo(0);
	if (ret == INF) cout << "-1";
	else
	cout << ret;	
	return 0;
}
#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;
char arr[5][5];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int ret;
unordered_set<string> llist;
void gogo(int x, int y, int cnt, string k) {
	if (cnt == 6) {
		if (llist.count(k) == 0) {
			llist.insert(k);
			ret++;
		}
		return;
	}
	for (int i = 0; i < 4; i++) {
		int ux = x + dx[i];
		int uy = y + dy[i];

		if (ux < 0 || uy < 0 || ux >= 5 || uy >= 5) continue;

		gogo(ux, uy, cnt + 1, k + arr[ux][uy]);
	}
}
//�̹����� �׳� ��~�غ��� �ȴ� �ð��� ���� ������
//�� ĭ�� 4^6 �̹Ƿ� 4096���� �ű⿡ ĭ�� 25���̹Ƿ� 102400 ���� ���´�
// ���� ����ϴ�~
int main() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			string a = "";
			a += arr[i][j];
			gogo(i, j, 1, a);
		}
	}
	cout << llist.size();
	return 0;
}
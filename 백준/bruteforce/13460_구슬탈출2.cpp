#include<bits/stdc++.h>
using namespace std;
#define INF 99999999

int dx[] = { 0,0,1,-1 };//��������
int dy[] = { 1,-1,0,0 }, n, m;
vector<string> arr;
int b_x, b_y, r_x, r_y;
int d_x, d_y, ret = 11;



// �־ȵǴ��� ��� ����ߴµ� �����⿴��.
// ���� �ȵȰ���
// 4 4
//####
//#OB#
//#R##
//####
//�̿��� �󸶳� �㹫�Ѱ� ��� ��츦 �� �غ��� �ϴµ� B�� ���ʿ���
//������ ������ �ع����� ������ �õ� ���ϴ� ��ó���� ���� �ҽ� ����.
//�̾���..
void gogo(int dir, int cnt, int a_x, int a_y, int c_x, int c_y) {

	if (cnt >= 11) {
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (dir == 0) {
			if (i == 0 || i == 1) continue;
		}
		else if (dir == 1) {
			if (i == 1 || i == 0) continue;
		}
		else if (dir == 2) {
			if (i == 2 || i == 3) continue;
		}
		else if (dir == 3) {
			if (i == 3 || i == 2) continue;
		}
		int ur_x = a_x;  // ���� ��ġ
		int ur_y = a_y;
		int ub_x = c_x;
		int ub_y = c_y;

		bool check = false;

		while (1) {
			ur_x += dx[i];
			ur_y += dy[i];

			if (ur_x == d_x && ur_y == d_y) {
				check = true;
				break;
			}

			if (arr[ur_x][ur_y] == '#') {
				break;
			}
		}
		ur_x -= dx[i];
		ur_y -= dy[i];

		bool check2 = false;
		while (1) {
			ub_x += dx[i];
			ub_y += dy[i];

			if (ub_x == d_x && ub_y == d_y) {
				check2 = true;
				break;
			}

			if (arr[ub_x][ub_y] == '#') {
				break;
			}
		}
		ub_x -= dx[i];
		ub_y -= dy[i];

		if (check == true && check2 == true) { //�Ѵ� ������ ����
			continue;
		}
		else if (check == true && check2 == false) { //���常 ������ ����
			ret = min(ret, cnt);
			return;
		}
		else if (check == false && check2 == true) { //��縸������ ����
			continue;
		}
		if (ur_x == ub_x && ur_y == ub_y) { //��ġ�� ������
			if (a_x == c_x) { // ���� ������
				if (i == 0) { // ���϶�
					if (a_y < c_y) {
						ur_x -= dx[i];
						ur_y -= dy[i];
					}
					else {
						ub_x -= dx[i];
						ub_y -= dy[i];
					}
				}
				else if (i == 1) {
					if (a_y < c_y) {
						ub_x -= dx[i];
						ub_y -= dy[i];
					}
					else {
						ur_x -= dx[i];
						ur_y -= dy[i];
					}
				}
			}
			else { //���� ��������
				if (i == 2) { // ���϶�
					if (a_x < c_x) {
						ur_x -= dx[i];
						ur_y -= dy[i];
					}
					else {
						ub_x -= dx[i];
						ub_y -= dy[i];
					}
				}
				else if (i == 3) {
					if (a_x < c_x) {
						ub_x -= dx[i];
						ub_y -= dy[i];
					}
					else {
						ur_x -= dx[i];
						ur_y -= dy[i];
					}
				}
			}
		} // ��ġ������
		gogo(i, cnt + 1, ur_x, ur_y, ub_x, ub_y);
	}
}
int main() {
	cin >> n >> m;
	arr.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 'B') {
				b_x = i;
				b_y = j;
			}
			else if (arr[i][j] == 'R') {
				r_x = i;
				r_y = j;
			}
			else if (arr[i][j] == 'O') {
				d_x = i;
				d_y = j;
			}
		}
	}
	gogo(-1, 1, r_x, r_y, b_x, b_y);

	if (ret >= 11) cout << "-1\n";
	else cout << ret<<"\n";

	return 0;
}

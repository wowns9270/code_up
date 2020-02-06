#include<bits/stdc++.h>
using namespace std;
#define INF 99999999

int dx[] = { 0,0,1,-1 };//동서남북
int dy[] = { 1,-1,0,0 }, n, m;
vector<string> arr;
int b_x, b_y, r_x, r_y;
int d_x, d_y, ret = 11;



// 왜안되는지 계속 고민했는데 쓰레기였다.
// 내가 안된경우는
// 4 4
//####
//#OB#
//#R##
//####
//이였다 얼마나 허무한가 모든 경우를 다 해봐야 하는데 B가 서쪽에서
//빠지고 리턴을 해버려서 북쪽을 시도 안하는 어처구니 없는 소스 였다.
//미안해..
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
		int ur_x = a_x;  // 원래 위치
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

		if (check == true && check2 == true) { //둘다 빠지면 실패
			continue;
		}
		else if (check == true && check2 == false) { //레드만 빠지면 성공
			ret = min(ret, cnt);
			return;
		}
		else if (check == false && check2 == true) { //블루만빠지면 실패
			continue;
		}
		if (ur_x == ub_x && ur_y == ub_y) { //위치가 같을때
			if (a_x == c_x) { // 행이 같으면
				if (i == 0) { // 동일때
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
			else { //열이 같을때는
				if (i == 2) { // 남일때
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
		} // 위치같을때
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

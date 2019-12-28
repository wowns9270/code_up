#include<bits/stdc++.h>
using namespace std;
int a, b, n, m;
enum kk { N = 0, W = 1, S = 2, E = 3 };
int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };
struct robot { int x; int y; int dir; };
struct memory { int q; char w; int e; };
int board[105][105];
robot arr[105];
//너무너무너무 바보같이 했던 문제
// 가로 세로 랑 1부터 시작하는 것과 동쪽이면 사실 남쪽으로 이동하는것을
//착각한 문제 ㅜㅜㅜ
int main() {
	cin >> a >> b >> n >> m;
	for (int i = 1; i <= n; i++) {
		int x, y; char c;
		cin >> x >> y >> c;
		arr[i].x = x;
		arr[i].y = y;
		if (c == 'N') arr[i].dir = E;
		else if (c == 'W') arr[i].dir = N;
		else if (c == 'S') arr[i].dir = W;
		else if (c == 'E') arr[i].dir = S;

		board[x][y] = i;
	}
	vector<memory> q;
	for (int i = 0; i < m; i++) {
		int select_robot, mul; char gubun;
		cin >> select_robot >> gubun >> mul;
		q.push_back({ select_robot,gubun,mul });
	}
	for (int i = 0; i < q.size(); i++) {
		int select_robot = q[i].q; char gubun = q[i].w; int mul = q[i].e;
		while (mul--) {
			if (gubun == 'L') {
				arr[select_robot].dir = (arr[select_robot].dir + 1) % 4;
			}
			else if (gubun == 'R') {
				arr[select_robot].dir = (arr[select_robot].dir + 3) % 4;
			}
			else {
				int x = arr[select_robot].x;
				int y = arr[select_robot].y;

				int ux = x + dx[arr[select_robot].dir];
				int uy = y + dy[arr[select_robot].dir];

				if (ux < 1 || uy < 1 || ux > a || uy > b) {
					cout << "Robot " << select_robot << " crashes into the wall\n";
					return 0;
				}
				else if (board[ux][uy] != 0) {
					cout << "Robot " << select_robot << " crashes into robot " << board[ux][uy] << "\n";
					return 0;
				}

				arr[select_robot].x = ux;
				arr[select_robot].y = uy;
				board[x][y] = 0;
				board[ux][uy] = select_robot;
			}
		}
	}
	cout << "OK\n";
	return 0;
}
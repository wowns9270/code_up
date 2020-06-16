#include<bits/stdc++.h>
#pragma warning(disable:4996)
using namespace std;

//가장 중요한부분 방향마다 거울이 있을때
//그 1번거울인지 2번거울인지 판단후에
//그방향에서 어떠케 되는지 
//2번거울에서 방향이 2 라면 d[2][2] = 0 
//  2(동) -> 0 (남)으로 이동을 뜻함 
//##################################################
int dx[] = { 1,-1,0,0 }; //남북동서
int dy[] = { 0,0,1,-1 };

int d[3][4] = { //방향 배열
	{}, {3,2,1,0} , {2,3,0,1}
};
//##################################################
int test, t_n = 1, ret, n;
bool check[1001][1001];
int arr[1001][1001];

int main() {
	cin >> test;
	while (test--) {
		ret = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%1d", &arr[i][j]);
			}
		}
		//memory.h 안되나?
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				check[i][j] = false;
			}
		}
		int dir = 2;
		int x = 0;
		int y = 0;
		while (1) {
			if (x < 0 || y < 0 || x >= n || y >= n) break;

			if (arr[x][y] == 1) {

				dir = d[arr[x][y]][dir];

				if (check[x][y] == false) {
					check[x][y] = true;
					ret++;
				}

			}
			else if (arr[x][y] == 2) { // 거울이 있따.

				dir = d[arr[x][y]][dir]; //방향을 바꿔주고

				if (check[x][y] == false) {
					check[x][y] = true;
					ret++;
				}
			}
			else {
			}
			x += dx[dir];
			y += dy[dir];
		}
		cout << "Case #" << t_n++ << "\n";
		cout << ret << "\n";
	}
}
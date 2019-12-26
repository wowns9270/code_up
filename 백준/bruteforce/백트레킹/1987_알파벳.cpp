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

	//4가지 방향중에
	for (int i = 0; i < 4; i++) {
		int ux = x + dx[i];
		int uy = y + dy[i];

		//일단 판안에 있고
		if (ux >= 1 && uy >= 1 && ux <= n && uy <= m) {
			//그 곳의 알파벳이 새로운 것이면
			if (check[arr[ux][uy] - 65] == false) {
				//방문표시 
				check[arr[ux][uy] - 65] = true;
				//다음탐색
				bruteforce(ux, uy, cnt + 1);
				//끝나면 노방문에 다른방향 ㄱㄱ
				check[arr[ux][uy] - 65] = false;
			}
		}
	}

	//더 이상 갈 곳 이 없을 경우 가장 큰 값 반환
	return ret = max(cnt, ret);
}

int main() {
	//알파벳 완전탐색
	cin >> n >> m;
	//입력
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
		}
	}
	//처음칸은 방문 표시 하고 
	check[arr[1][1] - 65] = true;
	//탐색
	cout << bruteforce(1, 1, 1);
}
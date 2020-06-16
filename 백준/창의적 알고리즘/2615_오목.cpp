#include<bits/stdc++.h>
using namespace std;

int arr[19][19];

int dx[] = { -1,0,1,1 };
int dy[] = { 1,1,1,0 };

vector<pair<int, int>> white;
vector<pair<int, int>> black;

bool check(int x, int y) {
	

	for (int i = 0; i < 4; i++) {

		int kx = x + dx[i];
		int ky = y + dy[i];

		bool ok2 = false;
		int cnt = 1;
		while (1) {
			if (kx < 0 || ky < 0 || kx >= 19 || ky >= 19) break;
			if (arr[kx][ky] != arr[x][y]) break;

			cnt++;
			kx += dx[i];
			ky += dy[i];
		}
		if (cnt == 5) {
			//이건 좀 예외처리 주의 
			//연속된 수중에 그 방향 으로 이전이 있는경우는
			//안된다.
			if (arr[x - dx[i]][y - dy[i]] == arr[x][y])continue;
			return true;
		}
	}
	return false;
}


int main() {
	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			cin >> arr[i][j];

			if (arr[i][j] == 1) {
				white.push_back({ i,j });
			}
			else if (arr[i][j] == 2) {
				black.push_back({ i,j });
			}

		}
	}

	for (int i = 0; i < white.size(); i++) {

		int x = white[i].first;
		int y = white[i].second;

		bool ok = check(x, y);
		if (ok == true) {
			cout << 1 <<"\n";
			cout << x + 1 << " " << y + 1;
			return 0;
		}
	}

	for (int i = 0; i < black.size(); i++) {

		int x = black[i].first;
		int y = black[i].second;

		bool ok = check(x, y);
		if (ok == true) {
			cout << 2 << "\n";
			cout << x + 1 << " " << y + 1;
			return 0;
		}
	}
	cout << 0;
	return 0;


}
#include<bits/stdc++.h>
using namespace std;


int dx[] = { -1,-2,-1,1,2,1 };
int dy[] = { -1,0,1,-1,0,1 };

int dp[50][50][50];
int a;

int gogo(int x, int y, int cnt) {
	if (cnt == 0) {
		if (x == 25 && y == 25) return 1;
		else return 0;
	}


	int& ret = dp[x][y][cnt];
	if (ret != -1) return ret;

	ret = 0;

	for (int i = 0; i < 6; i++) {
		int ux = x + dx[i];
		int uy = y + dy[i];

		ret += gogo(ux, uy, cnt - 1);
	}
	return ret;
}
int main() {
	int test; cin >> test;
	memset(dp, -1, sizeof(dp));
	while (test--) {
		cin >> a;
		cout << gogo(25, 25, a) << "\n";
	}
	return 0;
}
// 더이상  갈 방향이 없다
#include<bits/stdc++.h>;
#define inf 999999999
using namespace std;

int n, m, ret = inf;
bool visit[31][31];

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

vector<string> arr;

void gogo(int x, int y, int cnt) {


	for (int i = 0; i < 4; i++) {

		int ux = x + dx[i];
		int uy = y + dy[i];

		if (ux < 0 || uy < 0 || ux >= n || uy >= m) continue;
		//벗어나거나
		if (arr[ux][uy] == '*' || visit[ux][uy] == true) continue;
		//벽이거나 방문했으면

		visit[ux][uy] = true;

		int kx = ux;
		int ky = uy;
		while (1) {
			kx = kx + dx[i];
			ky = ky + dy[i];

			if (kx < 0 || ky < 0 || kx >= n || ky >= m) break;
			if (arr[kx][ky] == '*' || visit[kx][ky] == true) break;

			visit[kx][ky] = true;
		}
		kx = kx - dx[i];
		ky = ky - dy[i];


		gogo(kx, ky, cnt + 1);

		visit[kx][ky] = false;
		while (1) {
			if (kx == ux && ky == uy) break;

			kx = kx - dx[i];
			ky = ky - dy[i];
			visit[kx][ky] = false;

		}
	}

	bool check = false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == '*') continue;

			if (visit[i][j] == false) {
				check = true;
			}
		}
	}

	if (check == false) {
		ret = min(ret, cnt);
	}
	return;
}



int main() {
	int a = 1;
	while (cin >> n) {
		ret = inf;
		cin >> m;
		arr.resize(n);
		memset(visit, false, sizeof(visit));
		for (int i = 0; i < n; i++) { // map 받는다
			cin >> arr[i];
		}

		for (int i = 0; i < n; i++) { // map 받는다
			for (int j = 0; j < m; j++) {
				if (arr[i][j] == '*') continue;

				visit[i][j] = true;
				gogo(i, j, 0);
				visit[i][j] = false;
			}
		}
		cout << "Case " << a << ": ";
		if (ret >= inf) cout << -1 << "\n";
		else cout << ret << "\n";
		a++;
	}
	return 0;
}
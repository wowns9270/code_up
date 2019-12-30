#include<bits/stdc++.h>
using namespace std;

char a[51][51];
char b[51][51];
int ret;
void convert(int x, int y) {
	for (int i = x; i <= x + 2; i++) {
		for (int j = y; j <= y + 2; j++) {
			a[i][j] == '1' ? a[i][j] = '0' : a[i][j] = '1';
		}
	}
}
int main() {
	int n, m; cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> b[i][j];
		}
	}
	for (int i = 0; i < n - 2; i++) {
		for (int j = 0; j < m - 2; j++) {
			if (a[i][j] != b[i][j]) {
				ret++;
				convert(i, j);
			}
		}
	}

	bool check = true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] != b[i][j]) {
				check = false;
			}
		}
	}
	if (check == false) cout << "-1";
	else cout << ret;
	return 0;
}
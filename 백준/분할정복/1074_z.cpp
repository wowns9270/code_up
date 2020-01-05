#include<bits/stdc++.h>
using namespace std;

int cnt = 0;
int n, r, c;
void gogo(int size, int x, int y) {
	if (size == 1) {
		if (x == r && y == c) {
			cout << cnt;
			exit(0);
		}
		cnt++;
		return;
	}
	if (x > r || x + size <= r || y > c || y + size <= c) {
		cnt += size * size;
		return;
	}


	int n_size = size / 2;
	for (int i = 0; i <= 1; i++) {
		for (int j = 0; j <= 1; j++) {
			gogo(n_size, x + n_size * i, y + n_size * j);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> r >> c;


	int k = 1 << n;
	gogo(k, 0, 0);
}

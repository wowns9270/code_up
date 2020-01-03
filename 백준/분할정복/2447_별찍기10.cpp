#include<bits/stdc++.h>
using namespace std;

int n;
char arr[3000][3000];

void gogo(int size, int x, int y) {
	if (size == 1) {
		arr[x][y] = '*';
		return;
	}
	int n_size = size / 3;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == 1 && j == 1) continue;

			gogo(n_size, x + (n_size * i), y + (n_size * j));
		}
	}
	return;
}
int main() {
	cin >> n;
	for (int i = 0; i < 3000; i++) {
		for (int j = 0; j < 3000; j++) {
			arr[i][j] = ' ';
		}
	}
	gogo(n, 0, 0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr[i][j];
		}
		cout << "\n";
	}
	return 0;
}
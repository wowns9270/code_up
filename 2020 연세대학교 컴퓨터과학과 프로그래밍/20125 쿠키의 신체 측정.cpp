#include<bits/stdc++.h>
using namespace std;

int n;
vector<string> arr;

int kx, ky, cnt;

int main() {

	cin >> n;

	for (int i = 0; i < n; i++) {
		string a; cin >> a;
		arr.push_back(a);
	}
	int x = -1, y = -1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if ((i - 1 >= 0 && j - 1 >= 0 && i + 1 < n && j + 1 < n) &&
				arr[i][j] == '*' &&
				arr[i - 1][j] == '*' &&
				arr[i][j - 1] == '*' &&
				arr[i + 1][j] == '*' &&
				arr[i][j + 1] == '*'
				) {
				x = i;
				y = j;
			}
		}
	}
	cout << x + 1 << " " << y + 1 << "\n";

	kx = x, ky = y;
	cnt = 0;
	while (ky >= 0 && arr[kx][ky] == '*') {
		ky--;
		cnt++;
	}
	cout << cnt - 1 << " ";

	kx = x, ky = y;
	cnt = 0;
	while (ky < n && arr[kx][ky] == '*') {
		ky++;
		cnt++;
	}
	cout << cnt - 1 << " ";

	kx = x, ky = y;
	cnt = 0;
	while (arr[kx][ky] == '*') {
		kx++;
		cnt++;
	}
	cout << cnt - 1 << " ";

	int rx = kx;
	int ry = ky;

	kx = kx, ky = ky - 1;
	cnt = 1;

	while (kx < n && arr[kx][ky] == '*') {
		kx++;
		cnt++;
	}
	cout << cnt - 1 << " ";

	ry++;
	cnt = 1;

	while (rx < n && arr[rx][ry] == '*') {
		rx++;
		cnt++;
	}
	cout << cnt - 1 << " ";
	return 0;

}
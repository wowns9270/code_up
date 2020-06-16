#include<bits/stdc++.h>
using namespace std;

int arr[101][101];

int main() {
	for (int i = 0; i < 4; i++) {

		int a, b, c, d;
		cin >> a >> b >> c >> d;
		for (int k = a; k < c; k++) {
			for (int j = b; j < d; j++) {
				arr[k][j] = 1;
			}
		}
	}

	int ret = 0;
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			if (arr[i][j] == 1) {
				ret++;
			}
		}
	}
	cout << ret;

}
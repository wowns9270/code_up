#include<bits/stdc++.h>
using namespace std;

int main() {
	int a; cin >> a;

	int ret = 0;
	for (int i = a / 2; i >= 1; i--) {
		for (int j = i; ; j--) {

			int k = a - i - j;
			if (k > j) break;

			if (i < j + k) {
				ret++;
			}
		}
	}
	cout << ret;
	return 0;
}
#include<bits/stdc++.h>
using namespace std;

int main() {

	int max_num = 0;
	int idx = -1;
	for (int i = 1; i <= 9; i++) {
		int a; cin >> a;
		if (max_num < a) {
			max_num = a;
			idx = i;
		}
	}
	cout << max_num << "\n" << idx;
	return 0;
}
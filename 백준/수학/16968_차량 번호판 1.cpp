#include<bits/stdc++.h>
using namespace std;
int ret;

//수학문제
int main() {
	string n; cin >> n;

	if (n[0] == 'd') ret = 10;
	else ret = 26;

	for (int i = 1; i < n.size(); i++) {
		if (n[i - 1] == n[i]) {
			if (n[i] == 'd') ret *= 9;
			else ret *= 25;
		}
		else {
			if (n[i] == 'd') ret *= 10;
			else ret *= 26;
		}
	}
	cout << ret;
	return 0;
}
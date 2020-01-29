//#include<bits/stdc++.h>
//using namespace std;
//
//string n;
//
//int gogo(int cnt, int pre, int sum) {
//
//	if (cnt == n.size()) {
//		return sum;
//	}
//	if (pre == 0) {
//		if (n[cnt] == 'd') {
//			return gogo(cnt + 1, 1, sum * 10);
//		}
//		else if (n[cnt] == 'c') {
//			return gogo(cnt + 1, 2, sum * 26);
//		}
//	}
//	else if (pre == 1) {
//		if (n[cnt] == 'd') {
//			return gogo(cnt + 1, 1, sum * 9);
//		}
//		else if (n[cnt] == 'c') {
//			return gogo(cnt + 1, 2, sum * 26);
//		}
//	}
//	else {
//		if (n[cnt] == 'd') {
//			return gogo(cnt + 1, 1, sum * 10);
//		}
//		else if (n[cnt] == 'c') {
//			return gogo(cnt + 1, 2, sum * 25);
//		}
//	}
//}
//int main() {
//	cin >> n;
//	cout << gogo(0, 0, 1);
//	return 0;
//}
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



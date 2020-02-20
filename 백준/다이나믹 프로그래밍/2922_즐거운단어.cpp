#include<bits/stdc++.h>
using namespace std;
//i번째 까지 자음 모음이 몇개 연속 되어 왔는지
long long dp[101][3][4][2];
char llist[] = { 'A','E','I','O','U' };
string arr;
long long gogo(int idx, int type, int cnt, int l) {
	if (cnt >= 3) return 0;
	if (idx == arr.size()) {
		if (l == 1) {
			return 1;
		}
		return 0;
	}
	long long& ret = dp[idx][type][cnt][l];
	if (ret != -1) return ret;
	ret = 0;
	if (arr[idx] == '_') {

		if (type == 1) {//모음
			if (cnt == 2) {
				ret += gogo(idx + 1, 2, 1, l) * 20;
				ret += gogo(idx + 1, 2, 1, 1);
			}
			else {
				ret += gogo(idx + 1, 1, cnt + 1, l) * 5;
				ret += gogo(idx + 1, 2, 1, l) * 20;
				ret += gogo(idx + 1, 2, 1, 1);
			}
		}
		else if (type == 2) {
			if (cnt == 2) {
				ret += gogo(idx + 1, 1, 1, l) * 5;
			}
			else {
				ret += gogo(idx + 1, 1, 1, l) * 5;
				ret += gogo(idx + 1, 2, cnt + 1, l) * 20;
				ret += gogo(idx + 1, 2, cnt + 1, 1);
			}
		}
		else {//26 가지에서 5개 빼면 21 가지 l 한가지
			ret += gogo(idx + 1, 1, 1, 0) * 5;
			ret += gogo(idx + 1, 2, 1, 0) * 20;
			ret += gogo(idx + 1, 2, 1, 1);
		}
	}
	else {
		bool check = false;
		for (int i = 0; i < 5; i++) {
			if (arr[idx] == llist[i]) {
				check = true;
			}
		}
		if (check == true) { // 모음이다.
			if (type == 1) { // 전에도 모음이였다.
				ret += gogo(idx + 1, 1, cnt + 1, l);
			}
			else if (type == 2) { //전에는 자음이였는데요~
				ret += gogo(idx + 1, 1, 1, l);
			}
			else {
				ret += gogo(idx + 1, 1, 1, l);
			}
		}
		else { // 자음이다
			if (type == 1) {//전이 모음이다
				if (arr[idx] == 'L') {
					ret += gogo(idx + 1, 2, 1, 1);
				}
				else
					ret += gogo(idx + 1, 2, 1, l);
			}
			else if (type == 2) {//자음애서 왔다
				if (arr[idx] == 'L') {
					ret += gogo(idx + 1, 2, cnt + 1, 1);
				}
				else
					ret += gogo(idx + 1, 2, cnt + 1, l);
			}
			else {
				if (arr[idx] == 'L') {
					ret += gogo(idx + 1, 2, 1, 1);
				}
				else
					ret += gogo(idx + 1, 2, 1, l);
			}
		}
	}
	return ret;
}
int main() {
	cin >> arr;

	memset(dp, -1, sizeof(dp));
	cout << gogo(0, 0, 0, 0);
	return 0;
}
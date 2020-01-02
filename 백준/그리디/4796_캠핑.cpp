#include<bits/stdc++.h>
using namespace std;
int l, p, v, a;

int main() {

	//그리디 문제
	//갈 수 있는 만큼 가고
	// 남은 날을 계산
	while (1) {
		cin >> l >> p >> v;
		if (l == 0 && p == 0 && v == 0) break;
		int set_day = v / p;
		int d_day = v % p;
		set_day = l * set_day;

		if (d_day >= l) set_day = set_day + l;
		else set_day = set_day + d_day;
		cout << "Case " << ++a << ": " << set_day << "\n";
	}
	return 0;
}
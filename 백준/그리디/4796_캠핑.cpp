#include<bits/stdc++.h>
using namespace std;
int l, p, v, a;

int main() {

	//�׸��� ����
	//�� �� �ִ� ��ŭ ����
	// ���� ���� ���
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
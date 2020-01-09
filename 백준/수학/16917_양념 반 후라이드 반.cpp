#include<bits/stdc++.h>
using namespace std;
int ret;
//¼öÇĞ
int main() {
	int a, b, c, x, y; cin >> a >> b >> c >> x >> y;
	if (a + b > 2 * c) {
		int k = min(x, y);
		ret += 2 * c * k;
		x = x - k; y = y - k;

		if (a > 2 * c)
			ret += 2 * x * c;
		else ret += x * a;

		if (b > 2 * c)
			ret += 2 * y * c;
		else ret += y * b;
	}
	else {
		ret += x * a;
		ret += y * b;
	}
	cout << ret;
	return 0;
}
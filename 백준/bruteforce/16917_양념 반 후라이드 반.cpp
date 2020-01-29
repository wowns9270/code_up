//#include<bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int a, b, c, x, y; cin >> a >> b >> c >> x >> y;
//
//
//	//각 각 산경우
//	int ret = a * x + b * y;
//
//	for (int i = 1; i <= 100000; i++) { //10만마리까지
//
//		int k = c * i * 2; //반반으로 양념 후라이드 i마리를 샀을때 가격
//
//		int k_ret = k + (max(0, x - i) * a + max(0, y - i) * b);
//
//		ret = min(ret, k_ret);
//	}
//	cout << ret;
//	return 0;
//}
#include<bits/stdc++.h>
using namespace std;
int ret;
//수학
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
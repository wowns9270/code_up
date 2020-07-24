#include<bits/stdc++.h>
using namespace std;

int main() {

	int test; cin >> test;
	int t = 1;
	while (test--) {

		int n; cin >> n;

		int a = 0, b = 0, c = 0, d = 0;


		d = n / 500;
		n %= 500;

		c = n / 100;
		n %= 100;

		b = n / 50;
		n %= 50;

		a = n / 10;

		cout << "Case #" << t++ << "\n";

		cout << a << " " << b << " " << c << " " << d << "\n";

	}
	return 0;


}
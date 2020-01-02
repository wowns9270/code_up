#include<bits/stdc++.h>
using namespace std;

int a, b, c, k;

//동전과 같은 문제
int main() {
	int n; cin >> n;

	a = n / 300;
	k = n % 300;
	b = k / 60;
	k = k % 60;
	c = k / 10;
	k = k % 10;

	if (k != 0) cout << "-1";
	else cout << a << " " << b << " " << c;
	return 0;
}
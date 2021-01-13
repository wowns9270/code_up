#include<bits/stdc++.h>
using namespace std;

int a, b, c, d;

int main() {
	cin >> a >> b >> c >> d;

	int k = b / d;
	int k2 = c / d;

	cout << min(a, k * k2);
	return 0;


}
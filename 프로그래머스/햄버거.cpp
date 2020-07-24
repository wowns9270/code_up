#include<bits/stdc++.h>
using namespace std;

int main() {

	int test; cin >> test;
	int t = 1;
	while (test--) {

		int a, b, c; cin >> a >> b >> c;

		a /= 2;
		c /= 3;

		cout << "Case #" << t++<<"\n";


		cout << min({ a,b,c }) <<"\n";


	}



}
#include<bits/stdc++.h>
using namespace std;

int main() {

	int test; cin >> test;
	int t = 1;
	while (test--) {

		string arr; cin >> arr;

		int a = 0, b = 0;

		for (int i = 0; i < arr.size(); i++) {

			if (arr[i] == 'A') a++;
			else b++;

		}
		cout << "Case #" << t++ << "\n";
		
		if ( (a < 21) && (b < 21) ) cout << "Playing\n";
		else if (a == 21) cout << "Alice\n";
		else cout << "Bob\n";




	}
	return 0;


}
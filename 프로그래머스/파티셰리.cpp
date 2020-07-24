#include<bits/stdc++.h>	
using namespace std;


int ans;

int main() {


	int test, a = 1;

	cin >> test;

	while (test--) {
		cout << "Case #" << a++ << "\n";
		bool check = false;
		int n; cin >> n;

		for (int i = 0; i <= 20; i++) {
			for (int j = 0; j <= 20; j++) {
				for (int k = 0; k <= 20; k++) {

					if ((i * 7 + j * 9 + k * 11) == n) {
						check = true;
						break;
					}
				}
			}
		}

		if (check == false) cout << "NO\n";
		else {
			cout << "YES\n";
		}
	}
	return 0;

}
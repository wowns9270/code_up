#include<iostream>
#include<string>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);



	int a; cin >> a;

	string arr;
	int k = 0;
	int b = 0;
	while (a--) {
		cin >> arr;

		if (arr == "all") {
			k = (1 << 21) - 1;
			continue;
		}
		else if (arr == "empty") {
			k = 0;
			continue;
		}
		cin >> b;

		if (arr == "add") {
			k |= (1 << b);
		}
		else if (arr == "check") {

			if (k & (1 << b) ) {
				cout << "1\n";
			}
			else cout << "0\n";
		}
		else if (arr == "remove") {

			k &= ~(1 <<b);
		}
		else if (arr == "toggle") {
			k ^= (1 << b);
		}
	}
	return 0;
}
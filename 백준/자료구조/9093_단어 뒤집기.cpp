#include<bits/stdc++.h>
using namespace std;
int main() {
	int n; cin >> n;
	cin.ignore();
	while (n--) {
		string a; getline(cin, a);
		int k = 0;
		for (int i = 0; i < a.size(); i++) {
			if (a[i] == ' ') {
				reverse(a.begin() + k, a.begin() + i);
				k = i + 1;
			}
		}
		reverse(a.begin() + k, a.end());
		cout << a << "\n";
	}
	return 0;
}
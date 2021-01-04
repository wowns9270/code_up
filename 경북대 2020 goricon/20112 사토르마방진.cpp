#include<bits/stdc++.h>
using namespace std;

int n;

vector<string> arr;


int main() {
	cin >> n;


	for (int i = 0; i < n; i++) {
		string a; cin >> a;

		arr.push_back(a);
	}

	string k = "";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			k += arr[i][j];
		}
	}

	string k2 = "";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			k2 += arr[j][i];
		}
	}

	if (k == k2) cout << "YES";
	else cout << "NO";

	return 0;

}
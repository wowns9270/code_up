#include<bits/stdc++.h>
using namespace std;

int n;

vector<string> arr;

bool check[101][101];



int main() {
	cin >> n;

	arr.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 'Y' && arr[j][i] == 'N') {
				check[i][j] = true;
			}
		}
	}

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (check[i][k] == true && check[k][j] == true) {
					check[i][j] = true;
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		if (check[i][i] == true) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	return 0;
}
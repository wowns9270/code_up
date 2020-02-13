#include<bits/stdc++.h>
using namespace std;
int n, m;
bool arr[401][401];
int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		arr[a][b] = true;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {

				if (arr[i][k] == true && arr[k][j] == true) {
					arr[i][j] = true;
				}


			}
		}
	}
	int test;
	cin >> test;
	while (test--) {
		int a, b; cin >> a >> b;
		if (arr[a][b] == true) {
			cout << "-1\n";
		}
		else if (arr[a][b] == false && arr[b][a] == true) {
			cout << "1\n";
		}
		else cout << "0\n";
	}
	return 0;
}
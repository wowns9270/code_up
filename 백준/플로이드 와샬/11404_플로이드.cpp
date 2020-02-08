#include<bits/stdc++.h>
using namespace std;
#define INF 99999999
int n, arr[101][101], m;

int main() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			arr[i][j] = INF;
			if (i == j) arr[i][j] = 0;
		}
	}

	for (int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;


		if (arr[a][b] == 0) {
			arr[a][b] = c;
		}
		else if (arr[a][b] != 0 && arr[a][b] > c) {
			arr[a][b] = c;
		}
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {

				if (arr[i][j] > arr[i][k] + arr[k][j]) {
					arr[i][j] = arr[i][k] + arr[k][j];
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (arr[i][j] >= INF) cout << "0 ";
			else cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;

}
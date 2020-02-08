#include<bits/stdc++.h>
using namespace std;
#define INF 99999999
int n,arr[101][101],m;
int gogo[101][101];

void path(int x, int y) {

	queue<int> q;
	q.push(x);

	while (x != y) {
		x = gogo[x][y];
		q.push(x);
	}

	cout << q.size() << " ";
	while (!q.empty()) {
		cout << q.front() << " ";
		q.pop();
	}

	cout << "\n";

}

//역추적 어렵다 이건 나를거쳐서 왔다 gogo[i][j];
//


int main() {
	cin >> n>>m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			arr[i][j] = INF;
			if (i == j) arr[i][j] = 0;

			gogo[i][j] = -1;
		}
	}

	for (int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;


		if (arr[a][b] == 0) {
			arr[a][b] = c;
			gogo[a][b] = b;
		}
		else if (arr[a][b] != 0 && arr[a][b] > c) {
			arr[a][b] = c;
			gogo[a][b] = b;
		}
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {

				if (arr[i][j] > arr[i][k] + arr[k][j]) {
					arr[i][j] = arr[i][k] + arr[k][j];
					gogo[i][j] = gogo[i][k];
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (arr[i][j] >= INF) cout << "0 ";
			else cout << arr[i][j]<<" ";
		}
		cout << "\n";
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) {
				cout << "0\n";
			}
			else if (arr[i][j] >= INF) {
				cout << "0\n";
			}
			else {
				path(i, j);
			}
		}
	}

	return 0;

}
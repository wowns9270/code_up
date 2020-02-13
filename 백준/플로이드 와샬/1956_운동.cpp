#include<bits/stdc++.h>
using namespace std;
#define inf 99999999
int v, e, arr[401][401];
int main() {
	cin >> v >> e;
	for (int i = 1; i <= v; i++) {
		for (int j = 1; j <= v; j++) {
			arr[i][j] = inf;
		}
	}
	for (int i = 0; i < e; i++) {
		int a, b, c; cin >> a >> b >> c;
		arr[a][b] = c;
	}
	for (int k = 1; k <= v; k++) {
		for (int i = 1; i <= v; i++) {
			for (int j = 1; j <= v; j++) {
				if (arr[i][j] > arr[i][k] + arr[k][j]) {
					arr[i][j] = arr[i][k] + arr[k][j];
				}
			}
		}
	}
	int ret = inf;
	for (int i = 1; i <= v; i++) {
		for (int j = 1; j <= v; j++) {
			if (i == j) continue;

			if (arr[i][j] != inf && arr[j][i] != inf) {
				ret = min(ret, arr[i][j] + arr[j][i]);
			}
		}
	}
	if (ret == inf)cout << "-1";
	else cout << ret;
	return 0;
}
#include<bits/stdc++.h>
#define inf 99999999
using namespace std;

int n;
int arr[51][51];
int llist[51];

int main() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			arr[i][j] = inf;
		}
	}


	while (1) {
		int a, b; cin >> a >> b;
		if (a == -1 && b == -1) break;

		arr[a][b] = 1;
		arr[b][a] = 1;
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
	int idx = 0;
	int ret = inf;
	for (int i = 1; i <= n; i++) {

		int ans = -1;
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			ans = max(ans, arr[i][j]);
		}
		llist[i] = ans;
		ret = min(ret, ans);
	}
	vector<int> k;
	for (int i = 1; i <= n; i++) {
		if (llist[i] == ret) {
			k.push_back(i);
		}
	}
	cout << ret << " " << k.size() << "\n";
	for (int i = 0; i < k.size(); i++) {
		cout << k[i] << " ";
	}
	return 0;
}
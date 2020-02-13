#include<bits/stdc++.h>
using namespace std;

int n, m, k;

vector < vector<bool>> arr;
bool ret[201][201];

vector<vector<bool>> gogo(vector<vector<bool>> a, vector<vector<bool>> b ) {

	vector<vector<bool>> ans(n + 1, vector<bool>(n + 1));

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if (a[i][k]==true && b[k][j]==true) {
					ans[i][j] = true;
				}
			}
		}
	}
	return ans;
}
vector<vector<bool>> pow(int k) {

	vector < vector<bool>> ans(n + 1, vector<bool>(n + 1));
	for (int i = 1; i <= n; i++) ans[i][i] = true;
	while (k > 0) {
		if (k % 2 == 1) {
			ans = gogo(ans,arr);
		}
		arr = gogo(arr, arr);
		k /= 2;
	}
	return ans;
}


int main() {

	ios_base::sync_with_stdio(NULL);
	cin.tie(0), cout.tie(0);

	cin >> n >> k >> m;

	arr.resize(n + 1,vector<bool>(n+1));
	for (int i = 1; i <= n; i++) {
		int a, b; cin >> a >> b;

		arr[i][a] = true;
		arr[i][b] = true;
	}

	vector<vector<bool>> ret = pow(k);

	while (m--) {
		int a, b; cin >> a >> b;

		if (ret[a][b] == true) {
			cout << "death\n";
		}
		else cout << "life\n";
	}
	return 0;
}
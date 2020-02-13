#include<bits/stdc++.h>
using namespace std;
#define inf 9999
int n;
pair<int, int > arr[21][21];
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		string a; cin >> a;
		for (int j = 0; j < a.size(); j++) {
			if (a[j] == '.') {
				arr[i][j + 1].first = inf;
			}
			else arr[i][j + 1].first = a[j] - '0';
		}
	}
	for (int i = 1; i <= n; i++) {
		string a; cin >> a;
		for (int j = 0; j < a.size(); j++) {
			if (a[j] == '.') {
				arr[i][j + 1].second = inf;
			}
			else arr[i][j + 1].second = a[j] - '0';
		}
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {

				if (arr[i][j].first * arr[i][j].second

		> (arr[i][k].first + arr[k][j].first)*
					(arr[i][k].second + arr[k][j].second)
					) {
					arr[i][j].first = arr[i][k].first + arr[k][j].first;
					arr[i][j].second = arr[i][k].second + arr[k][j].second;
				}
			}
		}
	}
	if (arr[1][2].first * arr[1][2].second == inf * inf) {
		cout << -1;
		return 0;
	}
	cout << arr[1][2].first * arr[1][2].second;
	return 0;
}
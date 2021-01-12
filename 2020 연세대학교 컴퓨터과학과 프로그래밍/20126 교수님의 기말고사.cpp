#include<bits/stdc++.h>
using namespace std;

int n, m, s;


vector<pair<int, int>> arr;

int main() {
	cin >> n >> m >> s;

	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;

		arr.push_back({ a,a + b });
	}

	arr.push_back({ 0,0 });
	arr.push_back({ s,s });

	sort(arr.begin(), arr.end());

	bool check = false;
	int ret = -1;
	for (int i = 0; i < arr.size()-1; i++) {

		if (arr[i + 1].first - arr[i].second >= m) {
			check = true;
			ret = arr[i].second;
			break;
		}
	}
	if (check == false) cout << -1;
	else cout << ret;
}
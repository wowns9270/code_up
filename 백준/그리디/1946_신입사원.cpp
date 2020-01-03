#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<pair<int, int>> arr;
bool cmp(pair<int, int>x, pair<int, int>y) {
	if (x.first < y.first) {
		return true;
	}
	return false;
}
int main() {
	int test; cin >> test;
	while (test--) {
		int n; cin >> n;
		arr.clear();
		for (int i = 0; i < n; i++) {
			int a, b; cin >> a >> b;
			arr.push_back(make_pair(a, b));
		}
		sort(arr.begin(), arr.end(), cmp);
		int line = arr[0].second;
		int cnt = 0;
		for (int i = 1; i < n; i++) {
			if (line > arr[i].second) {
				line = arr[i].second;
			}
			else {
				cnt++;
			}
		}
		cout << n - cnt << "\n";
	}
	return 0;
}
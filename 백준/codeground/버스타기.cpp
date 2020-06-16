#include<bits/stdc++.h>
using namespace std;

int test, t_n = 1, ret;

int main() {
	cin >> test;

	while (test--) {
		ret = 1;
		int n,k; cin >> n >>k;

		vector<int>arr;
		for (int i = 0; i < n; i++) {
			int a; cin >> a;
			arr.push_back(a);
		}
		sort(arr.begin(), arr.end());

		for (int i = 1; i < n; i++) {
			if (arr[i] - arr[i - ret] <= k) {
				ret++;
			}
		}

		cout << "Case #" << t_n++ << "\n";
		cout << ret << "\n";
	}
}
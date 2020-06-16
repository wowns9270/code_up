#include<bits/stdc++.h>
using namespace std;
int test,t_n=1,ret;
int main() {
	cin >> test;
	while (test--) {
		ret = 0;
		int n; cin >> n;
		vector<int> arr;
		for (int i = 0; i < n; i++) {
			int k; cin >> k;
			arr.push_back(k);
		}
		int len; cin >> len;
		int idx = -1;
		int x = 0;
		bool check = false;
		while (1) {
			if (idx == arr.size() - 1) break;
			for (int i = idx + 1; i<n; i++) {
				if (x + len >= arr[i]) {
					idx = i;
				}
				else {
					break;
				}
			}
			if (x == arr[idx]) {
				check = true;
				break;
			}
			x = arr[idx];
			ret++;
		}
		cout << "Case #" << t_n++ << "\n";
		if (check == true) cout << "-1\n";
		else
		cout << ret << "\n";
	}
}
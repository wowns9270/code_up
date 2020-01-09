#include<bits/stdc++.h>
using namespace std;
int arr[16], ret;
int main() {
	int n, l, r, x; cin >> n >> l >> r >> x;
	for (int i = 0; i < n; i++) cin >> arr[i];
	for (int i = 0; i < (1 << n); i++) {
		int sum = 0; int max_n = 0; int cnt = 0;
		int small_n = 213211231;
		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) {
				sum += arr[j];
				max_n = max(max_n, arr[j]);
				small_n = min(small_n, arr[j]);
				cnt++;
			}
		}
		if (cnt >= 2 && sum >= l && sum <= r && max_n - small_n >= x)ret++;
	}
	cout << ret;
	return 0;
}
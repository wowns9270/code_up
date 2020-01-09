#include<bits/stdc++.h>
using namespace std;
int n, m;
long long arr[1000000], max_h;
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		max_h = max(max_h, arr[i]);
	}
	long long lo = 1;
	long long hi = max_h;
	while (lo <= hi) {
		long long mid = (lo + hi) / 2;
		long long sum = 0;
		for (int i = 0; i < n; i++) {
			if (arr[i] > mid) sum += (arr[i] - mid);
		}
		if (sum >= m) lo = mid + 1;
		else hi = mid - 1;
	}
	cout << hi;
	return 0;
}
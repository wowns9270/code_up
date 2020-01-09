#include<bits/stdc++.h>
using namespace std;
int n, m ;
long long arr[10001] , max_n;
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		max_n = max(max_n, arr[i]);
	}
	long long lo = 1;
	long long hi = max_n;
	while (lo <= hi) {
		long long sum = 0;
		long long mid = (lo + hi) / 2;
		for (int i = 0; i < n; i++) {
			sum += arr[i] / mid;
		}
		if (sum >= m) {
			lo = mid + 1;
		}
		else {
			hi = mid - 1;
		}
	}
	cout << hi;
	return 0;
}
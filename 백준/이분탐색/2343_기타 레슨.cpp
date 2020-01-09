#include<bits/stdc++.h>
using namespace std;
int n, m;
long long arr[100010], ret;
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		ret = max(ret, arr[i]);
	}
	long long lo = ret;
	long long hi = 1000000000;
	while (lo <= hi) {
		long long mid = (lo + hi) / 2; //블루레이 길이
		long long sum = 0;
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (sum + arr[i] < mid) {
				sum += arr[i];
			}
			else if (sum + arr[i] == mid) {
				cnt++;
				sum = 0;
			}
			else {
				cnt++;
				sum = arr[i];
			}
		}
		if (sum != 0) cnt++;

		if (cnt > m) lo = mid + 1;
		else hi = mid - 1;
	}
	cout << lo;
	return 0;
}
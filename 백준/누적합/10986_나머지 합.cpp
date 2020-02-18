#include<bits/stdc++.h>
using namespace std;

long long arr[1000001];
long long sum[1000001],n,k;

int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(0), cout.tie(0);

	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];

		sum[i] = sum[i - 1] + arr[i];
	}
	long long ret = 0;
	map<long long, long long> llist;
	llist[0] = 1;
	for (int i = 1; i <= n; i++) {
		
		ret += llist[sum[i] % k];
		llist[sum[i] % k] ++;
	}
	cout << ret;
	return 0;
}
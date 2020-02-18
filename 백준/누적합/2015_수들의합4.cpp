#include<bits/stdc++.h>
using namespace std;

int arr[200001];
int sum[200001],n,k;

int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(0), cout.tie(0);

	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];

		sum[i] = sum[i - 1] + arr[i];
	}
	long long ret = 0;
	map<int, int> llist;
	llist[0] = 1;
	for (int i = 1; i <= n; i++) {
		
		if (llist[sum[i] - k] == 0) {
			llist[sum[i]]++;
		}
		else {
			ret += llist[sum[i] - k];
			llist[sum[i]]++;
		}
	}
	cout << ret;
	return 0;
}
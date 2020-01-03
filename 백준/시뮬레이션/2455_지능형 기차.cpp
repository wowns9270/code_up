#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int>> arr;
int ret;

int main() {
	for (int i = 0; i < 4; i++) {
		int a, b; cin >> a >> b;
		arr.push_back(make_pair(a, b));
	}

	int k = 0;
	k += arr[0].second;
	ret = max(ret, k);
	for (int i = 1; i < 4; i++) {
		k -= arr[i].first;
		k += arr[i].second;
		ret = max(ret, k);
	}
	cout << ret;
	return 0;
}
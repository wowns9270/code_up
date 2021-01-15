#include<bits/stdc++.h>
using namespace std;

int n, d, k, c;

vector<int > arr;

map<int, int> llist;

int main() {

	cin >> n >> d >> k >> c;

	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		arr.push_back(a);
	}

	for (int i = 0; i < k; i++) {
		llist[arr[i]]++;
	}

	for (int i = 0; i < k-1; i++) {
		arr.push_back(arr[i]);
	}

	int lo = 0; 
	int hi = k - 1;

	int ret = 0;

	while (1) {

		int k = llist.size();

		if (llist.find(c) != llist.end()) {
			ret = max(ret, k);
		}
		else {
			ret = max(ret, k+1);
		}

		hi++;
		if (hi >= arr.size()) break;

		llist[arr[hi]]++;

		llist[arr[lo]]--;
		if (llist[arr[lo]] == 0) llist.erase(arr[lo]);
		lo++;
	}
	cout << ret;
	return 0;
}
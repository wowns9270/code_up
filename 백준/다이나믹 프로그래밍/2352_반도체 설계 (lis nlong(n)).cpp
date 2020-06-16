#include<bits/stdc++.h>
using namespace std;

int arr[40001];
vector<int> lis;


int main() {

	int n; cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}


	int l = 1;
	lis.push_back(arr[0]);
	for (int i = 1; i < n; i++) {

		if (lis[l - 1] < arr[i]) {
			lis.push_back(arr[i]);
			l++;
			continue;
		}

		int idx = lower_bound(lis.begin(), lis.end(), arr[i])-lis.begin();
		lis[idx] = arr[i];
	}

	cout << l;
	return 0;

}
#include<bits/stdc++.h>
using namespace std;


int arr[3000000];
int ret;

int main() {
	int n; cin >> n;

	int k = 0;

	for (int i = 0; i < n; i++) {
		 cin >> arr[i];

		k ^= arr[i];
	}

	//cout << k;
	ret = max(ret, k);

	for (int i = 0; i < n; i++) {

		ret = max(ret, k ^ arr[i]);
	}

	cout << ret << ret;
	return 0;
}
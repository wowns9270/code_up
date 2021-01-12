#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> arr;

int incre, decre;

int main() {
	cin >> n;

	

	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		arr.push_back(a);
	}
	for (int i = 0; i < arr.size() - 1; i++) {
		if (arr[i] < arr[i + 1]) incre++;

		if (arr[i] > arr[i + 1]) decre++;
	}
	if (incre == 0 || decre == 0) {
		cout << 0;
		return 0;
	}

	for (int i = 0; i < n; i++) {

		bool state = -1;
		if (arr[0] < arr[1]) incre--;
		else if (arr[0] > arr[1]) decre--;

		int k = arr[0];
		arr.erase(arr.begin(), arr.begin() + 1);

		if (arr[arr.size() - 1] < k) incre++;
		else if (arr[arr.size() - 1] > k) decre++;

		arr.push_back(k);

		if (incre == 0 || decre == 0) {
			cout << i + 1;
			return 0;
		}
	}
	cout << -1;
	return 0;



}
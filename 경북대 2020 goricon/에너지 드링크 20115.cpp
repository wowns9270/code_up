#include<bits/stdc++.h>
using namespace std;

int n, ret;

vector<double> arr;

int main() {
	cin >> n;

	double sum = 0;
	for (int i = 0; i < n; i++) {
		double a; cin >> a;

		arr.push_back(a);
		sum += a;
	}

	sort(arr.begin(), arr.end());

	for (int i = 0; i < arr.size()-1; i++) {

		sum -= arr[i] / 2;
	}

	cout << sum;
	return 0;





}
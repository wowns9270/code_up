#include<bits/stdc++.h>
using namespace std;

int n;

vector<pair<int, string> > arr;

bool cmp(pair<int, string> x, pair<int, string> y) {

	if (x.first > y.first) {
		return true;
	}
	else if (x.first == y.first) {
		if (x.second < y.second) return true;
	}

	return false;
}


int main() {

	cin >> n;

	for (int i = 0; i < n; i++) {
		string a;
		int b;
		cin >> a >> b;

		arr.push_back({ b,a });
	}
	sort(arr.begin(), arr.end(), cmp);

	cout << arr[0].second;
	return 0;

}
#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> x, pair<int, int> y) {
	if (x.second < y.second) {
		return true;
	}
	else if (x.second == y.second) {
		if (x.first < y.first) {
			return true;
		}
	}
	return false;
}
int main() {
	//그리디 대표적인 문제
	//회의 끝시간에 따라 최대 회의 수가 결정된다는 사실
	//그리디의 증명은 사실 어렵다.
	vector<pair<int, int>> arr;
	int n; cin >> n;

	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		arr.push_back(make_pair(a, b));
	}
	sort(arr.begin(), arr.end(), cmp);

	int ret = 1;
	int x = arr[0].second;
	for (int i = 1; i < n; i++) {
		if (arr[i].first >= x) {
			ret++;
			x = arr[i].second;
		}
	}
	cout << ret;
	return 0;
}
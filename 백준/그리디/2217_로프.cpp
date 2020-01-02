#include<bits/stdc++.h>
using namespace std;

vector<int> arr;
int ret;
//최소 길이부터 확인하여 가장 최대값을 찾는 문제
int main() {
	int n; cin >> n;

	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		arr.push_back(a);
	}
	sort(arr.begin(), arr.end());

	for (int i = 0; i < n; i++) {
		int sum = arr[i] * (n - i);
		ret = max(ret, sum);
	}
	cout << ret;
	return 0;

}
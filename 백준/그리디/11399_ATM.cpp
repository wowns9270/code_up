#include<bits/stdc++.h>
using namespace std;

int main() {
	//기다리는사람 의 시간을 생각하려면
	//앞에서 부터 빨리 끝날수 있는 사람이 서야 
	//총합이 작아진다 그리디
	vector<int> arr;
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		arr.push_back(a);
	}
	sort(arr.begin(), arr.end());

	int sum = 0;
	int ret = 0;
	for (int i = 0; i < n; i++) {
		ret += arr[i];
		sum += ret;
	}
	cout << sum;
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
int n, k, ret;

vector<int> arr;
vector<int> dist;

bool cmp(int x, int y) {
	if (x > y) return true;
	return false;
}


int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		arr.push_back(a);
	}
	sort(arr.begin(), arr.end());

	for (int i = 0; i < arr.size() - 1; i++) {
		int ch = arr[i + 1] - arr[i];
		dist.push_back(ch);
	}
	sort(dist.begin(), dist.end(), cmp);


	for (int i = k - 1; i < dist.size(); i++) ret += dist[i];
	cout << ret;
	return 0;
}
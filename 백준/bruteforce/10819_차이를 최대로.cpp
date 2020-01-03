#include<bits/stdc++.h>	
using namespace std;

int n, ret;
int arr[9];
vector<int> go;
int gogo() {
	int temp[9];
	int sum = 0;
	for (int i = 0; i < n; i++) {
		temp[go[i]] = arr[i];
	}
	for (int i = 0; i < n - 1; i++) {
		sum += abs(temp[i] - temp[i + 1]);
	}
	return sum;
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++) {
		go.push_back(i);
	}
	do {
		int kk = gogo();
		ret = max(ret, kk);
	} while (next_permutation(go.begin(), go.end()));
	cout << ret;
	return 0;
}
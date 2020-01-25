#include<bits/stdc++.h>
using namespace std;
#define INF 19999999
vector<int> arr;
vector<int> d;
int ret = INF;

bool magic() {
	int sum = d[0] + d[1] + d[2];
	int sum_test = 0;
	for (int i = 0; i < 3; i++) {
		sum_test = d[i * 3] + d[i*3 +1] + d[i*3 + 2];
		if (sum != sum_test) return false;
		sum_test = 0;
	}
	for (int i = 0; i < 3; i++) {
		sum_test = d[i] + d[i + 3] + d[i + 6];

		if (sum != sum_test) return false;
	}
	if (sum != (d[0] + d[4] + d[8]))return false;
	if (sum != (d[2] + d[4] + d[6])) return false;
	return true;
}
int diff() {
	int kkk = 0;
	for (int i = 0; i < 9; i++) {
		kkk += abs(arr[i] - d[i]);
	}
	return kkk;
}

int main() {
	for(int i=0; i<3*3; i++){
		int a; cin >> a;
		arr.push_back(a);
	}
	for (int i = 0; i < 3 * 3; i++) {
		d.push_back(i + 1);
	}
	do {
		if (magic() == true) {
			int k = diff();
			ret = min(ret, k);
		}
	} while (next_permutation(d.begin(), d.end()));
	cout << ret;
	return 0;
}
#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<int > arr;
vector<int> llist;

bool check[100000];
vector<int> ret;

void gogo(int idx, int cnt) {


	if (cnt == m) {

		int sum = 0;

		for (int i = 0; i < llist.size(); i++) {
			sum += llist[i];
		}

		if (check[sum] == false) {
			ret.push_back(sum);
		}
		return;
	}

	if (idx >= n) return;

	llist.push_back(arr[idx]);
	gogo(idx + 1, cnt + 1);
	llist.pop_back();
	gogo(idx + 1, cnt);
}
int main() {

	cin >> n >> m;

	for (int i = 2; i <= sqrt(10000); i++) {

		for (int j = i * i; j <= 10000; j += i) {
			check[j] = true;
		}

	}


	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		arr.push_back(a);
	}

	gogo(0, 0);

	sort(ret.begin(), ret.end());

	ret.erase(unique(ret.begin(), ret.end()), ret.end());

	if (ret.size() == 0) {
		cout << -1;
		return 0;
	}

	for (int i = 0; i < ret.size(); i++) {
		cout << ret[i] << " ";
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;

int n, m;
bool check[10001];

int main() {
	cin >> n >> m;
	//2 ดย false
	check[1] = true;
	for (int i = 2; i <= 100; i++) {


		for (int j = i*i; j <= 10000; j += i) {
			check[j] = true;
		}
	}
	int sum = 0;
	int min_s = 10001;
	for (int i = n; i <= m; i++) {
		if (check[i] == false) {
			sum += i;
			min_s = min(min_s, i);
		}
	}

	if (sum == 0) {
		cout << -1;
	}
	else {
		cout << sum << "\n" << min_s;
	}

	return 0;
}
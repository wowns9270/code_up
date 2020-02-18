#include<bits/stdc++.h>
using namespace std;

int n, m, k;

long long arr[1000001];
long long seg[3000003];

long long gogo(int i) {
	long long ret = 0;
	while (i > 0) {
		ret += seg[i];

		i -= (i & -i);
	}

	return ret;
}

void update(int i, long long cnt) {
	while (i < n + 1) {
		seg[i] += cnt;
		
		i += (i & -i);
	}
}

int main() {
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		update(i, arr[i]);
	}
	m += k;
	while (m--) {
		int a; cin >> a;

		if (a == 1) {
			long long b,c;
			cin >> b >> c;
			long long diff = c - arr[b];
			arr[b] = c;
			update(b, diff);
		}
		else {
			int b, c; cin >> b >> c;
			
			cout << gogo(c) - gogo(b - 1) <<"\n";
		}
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;

int parant[10001];
int n, m;

struct span {
	int x, y, cost;
};

bool operator<(span x, span y) {
	if (x.cost < y.cost) {
		return true;
	}
	return false;
}


vector<span> arr;

int find(int n) {

	if (parant[n] == n) return n;

	int yy = find(parant[n]);

	parant[n] = yy;

	return yy;
}


void unionn(int x, int y) {

	int kx = find(x);
	int ky = find(y);

	parant[ky] = kx;
	return;
}


int main() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		parant[i] = i;
	}

	for (int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;
		arr.push_back({ a,b,c });
	}
	sort(arr.begin(), arr.end());

	int ret = 0;
	for (int i = 0; i < arr.size(); i++) {

		int from = arr[i].x;
		int to = arr[i].y;
		int costt = arr[i].cost;

		if (find(from) == find(to)) continue;

		unionn(from, to);
		ret += costt;
	}
	cout << ret;


}
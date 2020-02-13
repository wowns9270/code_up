#include<bits/stdc++.h>
using namespace std;



int parant[100001],n,m;

struct edge { //°£¼±
	int x;
	int y;
	int cost;
};

bool operator <(edge x, edge y) {
	if (x.cost < y.cost) return true;
	return false;
}

vector<edge> arr;

int find(int n) {

	if (parant[n] == n) return n;

	int y = find(parant[n]);

	parant[n] = y;

	return y;
}



void unionn(int x, int y) {

	int nx = find(x);
	int ny = find(y);

	if (nx == ny) return;

	parant[ny] = nx;

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
		arr.push_back({ b,a,c });
	}
	sort(arr.begin(), arr.end());

	int sum = 0;
	int n_k = 0;

	for (int i = 0; i < arr.size(); i++) {

		int from = arr[i].x;
		int to = arr[i].y;
		int costt = arr[i].cost;

		if (find(from) == find(to)) continue;

		unionn(from, to);

		sum += costt;
		n_k++;
		if (n_k == n - 2) break;
	}
	cout << sum;
	return 0;

}
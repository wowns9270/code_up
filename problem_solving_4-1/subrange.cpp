#include<bits/stdc++.h>
using namespace std;


ifstream in("subrange.inp");
ofstream out("subrange.out");

int n;

int arr[500001];
int seg[2000000];


void update(int x, int y, int k, int r, int l , int idx) {


	if (x <= r && y >= l) { // 구간에 완전히 포함된다.

		seg[idx] += k;
		return;
	}

	if (l < x || y < r) return;


	int mid = (r + l) / 2;

	update(x, y, k, r, mid, idx * 2);
	update(x, y, k, mid+1, l, idx * 2 + 1);

}

void gogo( int x, int y , int idx) {


	if (seg[idx] != 0) {
		for (int i = x; i <= y; i++) {
			arr[i] += seg[idx];
		}
	}

	if (x == y) return;


	int mid = (x + y) / 2;

	gogo(x, mid, idx * 2);
	gogo(mid + 1, y, idx * 2 + 1);
}

int main() {

	in >> n;

	while (1) {

		int a, b, c; in >> a >> b >> c;


		if (a == -1 && b == -1 && c == -1) break;
		update(a, b, c, 0, n-1 , 1);
	}


	gogo( 0 , n-1, 1);


	int max_r = -99999999;
	int max_idx = -1;


	int min_r = 99999999;
	int min_idx = -1;

	for (int i = 0; i < n; i++) {

		if (arr[i] > max_r) {
			max_r = arr[i];

			max_idx = i;
		}

		if (arr[i] < min_r) {
			min_r = arr[i];

			min_idx = i;
		}
	}

	out << min_r << " " << min_idx << " " << max_r << " " << max_idx;
	return 0;


}
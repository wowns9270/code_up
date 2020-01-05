#include<bits/stdc++.h>
using namespace std;

ifstream in("inv.inp");
ofstream out("inv.out");

int n, m;
int a[100010];
int c[100010];
long long ret;
void merge(int lo, int hi) {
	int mid = (lo + hi) / 2;
	int i = lo;
	int j = mid + 1;
	int k = 0;
	while (i <= mid && j <= hi) {
		if (a[i] <= a[j]) {
			c[k++] = a[i++];
		}
		else {
			c[k++] = a[j++];
			ret += (long long)(mid - i + 1);
		}
	}
	while (i <= mid) c[k++] = a[i++];
	while (j <= hi) c[k++] = a[j++];

	for (int i = lo; i <= hi; i++) {
		a[i] = c[i - lo];
	}
	return;
}
void sort(int lo, int hi) {
	if (lo == hi) return;
	int mid = (lo + hi) / 2;
	sort(lo, mid);
	sort(mid + 1, hi);
	merge(lo, hi);
}
int main() {
	int test; in >> test;
	while (test--) {
		in >> n; ret = 0;
	 for (int i = 0; i < n; i++) { in >> a[i]; }
	 sort(0, n- 1);
	 out << ret<<"\n";
	}
	 return 0;
}
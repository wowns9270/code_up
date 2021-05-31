#include<bits/stdc++.h>
#define INF 4000099
using namespace std;

ifstream in("rmq.inp");
ofstream out("rmq.out");
int n , base , b ,c; 
char a;

int arr[1000004];
int seg[4000100];

void init() {
	for (int i = base - 1; i > 0; i--) {

		if (arr[seg[i * 2]] < arr[seg[i * 2 + 1]]) {
			seg[i] = seg[i * 2];
		}
		else if (arr[seg[i * 2]] > arr[seg[i * 2 + 1]]) {
			seg[i] = seg[i * 2 + 1];
		}
		else {
			if (seg[i * 2] < seg[i * 2 + 1]) seg[i] = seg[i * 2];
			else seg[i] = seg[i * 2 + 1];
		}
	}
}

int query(int l, int r) {

	l += base;
	r += base;

	int ret = 1000002;



	while (l <= r) {

		if (l % 2 == 1) {

			if (arr[ret] > arr[seg[l]]) {
				ret = seg[l];
			}
			else if (arr[ret] == arr[seg[l]]) {
				if (ret > seg[l])
					ret = seg[l];
			}
			l++;
		}

		if (r % 2 == 0) {
			if (arr[ret] > arr[seg[r]]) {
				ret = seg[r];
			}
			else if (arr[ret] == arr[seg[r]]) {
				if (ret > seg[r])
					ret = seg[r];
			}
			r--;
		}
		l /= 2;
		r /= 2;
	}

	return ret;

}

int main() {

	in >> n;

	arr[1000002] = INF;
	for (int i = 0; i < 4000100; i++) {
		seg[i] = 1000002;
	}
	//가장 인덱스가 되는 지점
	for (base = 1; base < n; base *= 2);

	//맨 밑단 노드는 원래 배열의 값이 들어간다.
	for (int i = 0; i < n; i++) {
		int a; in >> a;
		arr[i] = a;
		seg[base + i] = i;
	}


	//부모가 되는 노드들이 갖는 값
	init();

	int ans = 0;
	while (1) {
		in >> a >> b >> c;

		if (a == 'q') {

			int k  = query(b, c);

			ans += k;
			ans %= 100000;
			
			//out << k << "\n";
		}
		else if (a == 'c') {

			arr[b] = c;
			int idx = base + b;
			for (idx /= 2; idx; idx /= 2) {
				if (arr[seg[idx * 2]] < arr[seg[idx * 2 + 1]]) {
					seg[idx] = seg[idx * 2];
				}
				else if (arr[seg[idx * 2]] > arr[seg[idx * 2 + 1]]) {
					seg[idx] = seg[idx * 2 + 1];
				}
				else {
					if (seg[idx * 2] < seg[idx* 2 + 1]) seg[idx] = seg[idx * 2];
					else seg[idx] = seg[idx * 2 + 1];
				}
			}


		}
		else {
			if (b == -1 && c == -1) break;
		}
	}
	out << ans << "\n";
	return 0;
}
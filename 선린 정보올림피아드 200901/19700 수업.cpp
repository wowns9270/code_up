#include<bits/stdc++.h>
using namespace std;


int n;

vector<pair<int, int> > arr;

bool cmp(pair<int, int> x, pair<int, int> y) {

	if (x.first > y.first) return true;

	return false;

}
deque<int> q;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		arr.push_back({ a,b });
	}
	sort(arr.begin(), arr.end(), cmp);


	for (int i = 0; i < n; i++) {

		int k = arr[i].first;
		int k2 = arr[i].second;


		if (k2 == 1) q.push_front(1);
		else {

			int lo = 0, hi = q.size() - 1, idx = -1;

			while (lo <= hi) {

				int mid = (lo + hi) / 2;

				if (q[mid] < k2) {
					idx = mid, lo = mid + 1;
				}
				else {
					hi = mid - 1;
				}
			}

			if (idx != -1) q[idx]++;
			else {
				q.push_front(1);
			}
		}
	}

	cout << q.size();



	return 0;

}
#include<bits/stdc++.h>
using namespace std;
int  h, w, n,ret;
vector<pair<int, int>> arr;

//두스티커의 넓이의 합이 최대가 되는 넓이를 구하는 문제
//두스티커를 붙이는 방법은 총 8개이다. 처음에 헷갈려서
//잘못했는데 그냥 모든 경우를 다 해봤다.
//이런게 더어렵다
int main() {
	cin >> h >> w >> n;

	for (int i = 0; i < n; i++) {
		int r, c; cin >> r >> c;
		arr.push_back({ r,c });
	}

	for (int i = 0; i < arr.size() - 1; i++) {
		for (int j = i + 1; j < arr.size(); j++) {

			int x1 = arr[i].first;
			int y1 = arr[i].second;
			int x2 = arr[j].first;
			int y2 = arr[j].second;

			bool check = false;

			if (max(x1, x2) <= h && y1 + y2 <= w) {
				check = true;
			}
			if (max(y1, y2) <= w && x1 + x2 <= h) {
				check = true;
			}
			if (max(x1, y2) <= h && y1 + x2 <= w) {
				check = true;
			}
			if (max(y1, x2) <= w && x1 + y2 <= h) {
				check = true;
			}
			if (max(y1, x2) <= h && x1 + y2 <= w) {
				check = true;
			}
			if (max(x1, y2) <= w && y1 + x2 <= h) {
				check = true;
			}
			if (max(y1, y2) <= h && x1 + x2 <= w) {
				check = true;
			}
			if (max(x1, x2) <= w && y1 + y2 <= h) {
				check = true;
			}

			if (check == true) {
				int sum = x1 * y1 + x2 * y2;

				ret = max(ret, sum);
			}
		}
	}
	cout << ret;
	return 0;
}
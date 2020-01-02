#include<bits/stdc++.h>
using namespace std;

int n, st, en, cnt;
vector<pair<int, int>> arr;

bool cmp(pair<int, int> x, pair<int, int> y) {
	if (x.first < y.first) {
		return true;
	}
	return false;
}


int main() {

	//꽃이 피는날로 정렬한다.
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b, c, d; cin >> a >> b >> c >> d;
		arr.push_back(make_pair(a * 100 + b, c * 100 + d));
	}
	sort(arr.begin(), arr.end(), cmp);

	int date = 301;
	int i = 0;
	int state = 0;
	int en = 0;
	//301로 설정한다 처음을
	while (date <= 1130 && i < n) {
		state = 0;
		for (int j = i; j < n; j++) {

			//처음에는 301보다 큰값은 조건에 충족하지못해서 빠져나간다,
			if (date < arr[j].first) break;

			// 더 좋은 조건에 충족 지는날이 더 긴 것을 선택한다.
			if (en < arr[j].second) {
				en = arr[j].second;
				state = 1;
				i = j;
			}

		}

		if (state == 0) {
			cout << "0";
			return 0;
		}
		else {
			date = en;
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}
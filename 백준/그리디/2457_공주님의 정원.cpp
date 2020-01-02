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

	//���� �Ǵ³��� �����Ѵ�.
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
	//301�� �����Ѵ� ó����
	while (date <= 1130 && i < n) {
		state = 0;
		for (int j = i; j < n; j++) {

			//ó������ 301���� ū���� ���ǿ� �����������ؼ� ����������,
			if (date < arr[j].first) break;

			// �� ���� ���ǿ� ���� ���³��� �� �� ���� �����Ѵ�.
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
#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> x, pair<int, int> y) {
	if (x.second < y.second) {
		return true;
	}
	else if (x.second == y.second) {
		if (x.first < y.first) {
			return true;
		}
	}
	return false;
}
int main() {
	//�׸��� ��ǥ���� ����
	//ȸ�� ���ð��� ���� �ִ� ȸ�� ���� �����ȴٴ� ���
	//�׸����� ������ ��� ��ƴ�.
	vector<pair<int, int>> arr;
	int n; cin >> n;

	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		arr.push_back(make_pair(a, b));
	}
	sort(arr.begin(), arr.end(), cmp);

	int ret = 1;
	int x = arr[0].second;
	for (int i = 1; i < n; i++) {
		if (arr[i].first >= x) {
			ret++;
			x = arr[i].second;
		}
	}
	cout << ret;
	return 0;
}
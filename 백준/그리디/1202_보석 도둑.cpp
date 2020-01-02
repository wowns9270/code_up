#include<bits/stdc++.h>
using namespace std;
int n, m;
long long ret;
vector<pair<int, int>> arr;
multiset<int> pack;
bool cmp(pair<int, int>x, pair<int, int>y) {
	if (x.second > y.second) {
		return true;
	}
	else if (x.second == y.second) {
		if (x.first < y.first) return true;
	}
	return false;
}
int main() {
	cin >> n >> m;
	//������ ���Զ� ������ ���
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		arr.push_back(make_pair(a, b));
	}
	//������ ���� ������ ����
	sort(arr.begin(), arr.end(), cmp);

	for (int i = 0; i < m; i++) {
		int k; cin >> k;
		pack.insert(k);
	}
	multiset<int>::iterator it;
	//�ִ���  ������ �ִ� ���� �߿� ������ ���濡 ��ƾ�
	//�����ϴ� 
	for (int i = 0; i < n; i++) {
		it = pack.lower_bound(arr[i].first);
		if (it == pack.end()) continue;
		else {
			ret += arr[i].second;
			pack.erase(it);
		}

		if (pack.size() == 0) break;

	}
	cout << ret;
	return 0;
}
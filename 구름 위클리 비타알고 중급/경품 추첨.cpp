#include<bits/stdc++.h>
using namespace std;

int n, m;

vector<int> arr;
vector<int>llist;
vector<int> cnt;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;


	//���� ��� �޴´�.
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		arr.push_back(a);
	}

	// ������ �Ѵ� nlog n
	sort(arr.begin(), arr.end());

	//��ǥ�� �����Ѵ�.

	//ó�� ���� ����
	llist.push_back(arr[0]);
	cnt.push_back(1);

	// n
	for (int i = 1; i < arr.size(); i++) {
		if (arr[i - 1] == arr[i]) {
			cnt[cnt.size() - 1]++;
		}
		else {
			llist.push_back(arr[i]);
			cnt.push_back(1);
		}
	}

	//lower_bound�� ���ؼ� ã������ ������ ��ȯ�Ѵ� m log2n
	for (int i = 0; i < m; i++) {

		int a; cin >> a;

		//��ǥ
		auto it = lower_bound(llist.begin(), llist.end(), a) - llist.begin();

		if (llist[it] == a) {
			cout << cnt[it] << " ";
		}
		else {
			cout << "0 ";
		}
	}
}
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


	//수를 모두 받는다.
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		arr.push_back(a);
	}

	// 정렬을 한다 nlog n
	sort(arr.begin(), arr.end());

	//좌표를 압축한다.

	//처음 수와 개수
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

	//lower_bound를 통해서 찾은다음 개수를 반환한다 m log2n
	for (int i = 0; i < m; i++) {

		int a; cin >> a;

		//좌표
		auto it = lower_bound(llist.begin(), llist.end(), a) - llist.begin();

		if (llist[it] == a) {
			cout << cnt[it] << " ";
		}
		else {
			cout << "0 ";
		}
	}
}
#include<bits/stdc++.h>	
using namespace std;
int n;
int ret;
vector<pair<int, int>> arr;
set<int> day;
int visit[10000];


// 13904과제랑 똑같은 문제 될 수 있는 날을 선택한다
bool cmp(pair<int, int>x, pair<int, int>y) {
	if (x.first > y.first) {
		return true;
	}

	return false;
}
int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		arr.push_back(make_pair(a, b));
	}
	sort(arr.begin(), arr.end(), cmp);

	for (int i = 0; i < n; i++) {
		if (visit[arr[i].second] == false) {
			visit[arr[i].second] = true;
			ret += arr[i].first;
		}
		else {
			int j = arr[i].second - 1;
			while (1) {
				if (j == 0) break;

				if (visit[j] == false) {
					visit[j] = true;
					ret += arr[i].first;
					break;
				}
				j--;
			}
		}
	}
	cout << ret;
	return 0;
}
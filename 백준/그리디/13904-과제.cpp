#include<bits/stdc++.h>
using namespace std;

int n, ret;
vector<pair<int, int>> arr;
int visit[1000];

bool cmp(pair<int, int> x, pair<int, int> y) {
	if (x.second > y.second) {
		return true;
	}
	else if (x.second == y.second) {
		if (x.first > y.first) return true;
	}
	return false;
}
int main() {
	//일단 점수를 가장 많이 받는 것부터 정렬을한다.
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		arr.push_back(make_pair(a, b));
	}
	sort(arr.begin(), arr.end(), cmp);

	//visit 은 그날에 과제를 했는지 안했는지이다.
	//마감이 4일인 과제가 이미 4일에 다른과제를 했으면
	//3일을 보고 다음보고 하는 것이다. 이게 왜그러냐면
	//점수가 큰거 부터 보기 때문에 최대한 미뤄서 다른과제를 할 수 있게 하고
	//앞날 앞날을 체크하면서 할 수 있으면 과제를 한다.
	//그리디
	for (int i = 0; i < n; i++) {
		if (visit[arr[i].first] == false) {
			visit[arr[i].first] = true;
			ret += arr[i].second;
		}
		else {
			int j = arr[i].first - 1;
			while (1) {
				if (j == 0) break;

				if (visit[j] == false) {
					visit[j] = true;
					ret += arr[i].second;
					break;
				}
				j--;
			}
		}
	}
	cout << ret;
	return 0;
}
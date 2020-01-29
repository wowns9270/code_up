#include<bits/stdc++.h>
using namespace std;
int arr[16];
int n, l, r, x,ret;
vector<int>llist;

// n 이 20 이하인 전형적인 부르트 포스 문제..
//각 문제를 선택할지 안할지를 고르므로 2^n n이 최대 15이므로 
// 충분히 해결가능 그리고 각 조건들
// 2개이상 고르는것 최대최소 그리고
// 가장작은값과 큰값의 차이를 구하기 위해 정렬까지해서 진행하였다.
void gogo(int idx, int cnt, int sum) {
	if (idx == n) {
		if (cnt >= 2) {
			if (sum >= l && sum <= r) {
				if (llist[llist.size() - 1] - llist[0] >= x) {
					ret++;
				}
			}
		}
		return;
	}
	llist.push_back(arr[idx]);
	gogo(idx + 1, cnt + 1, sum + arr[idx]);
	llist.pop_back();
	gogo(idx + 1, cnt, sum);
}
int main() {
	cin >> n >> l >> r >> x;

	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);

	gogo(0, 0, 0); //idx.cnt.sum;
	cout << ret;
	return 0;
}
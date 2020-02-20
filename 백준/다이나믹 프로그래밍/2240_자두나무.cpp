#include<bits/stdc++.h>
#define inf -999999
using namespace std;

int arr[1002];
int dp[1002][32][3], t, w;


int gogo(int idx, int cnt, int space) {

	if (idx == t) {
		if (cnt <= w) {
			return 0;
		}
		return inf;
	}
	if (cnt > w) return inf;

	int& ret = dp[idx][cnt][space];
	if (ret != -1) return ret;
	ret = 0;

	//떨어지는 위치와 현재위치가 같으면
	if (arr[idx] == space) {
		ret = max(ret, gogo(idx + 1, cnt, space) + 1);
		ret = max(ret, gogo(idx + 1, cnt + 1, 3 - space) + 1);
	}
	else {
		ret = max(ret, gogo(idx + 1, cnt, space));
		ret = max(ret, gogo(idx + 1, cnt + 1, 3 - space) + 1);
	}
	return ret;

}
int main() {
	cin >> t >> w;
	for (int i = 0; i < t; i++) {
		cin >> arr[i];
	}
	memset(dp, -1, sizeof(dp));
	cout << gogo(0, 0, 1);
	return 0;
}
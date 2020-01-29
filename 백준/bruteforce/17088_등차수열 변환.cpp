#include<bits/stdc++.h>
using namespace std;
#define INF 19999999
int n,ret=INF;
int arr[100001];
int k[] = { -1,0,1 };

// -1 0 1 인 모든 경우에 해볼라고 했으나 n이 무려 10^5이므로 실패
// 그래서 공차의 경우의 수는 5가지 뿐이니까.
//공차의 경우에 되는 수열을 계산해봤다.
//각각의 공차에서 첫항을 미리 정해주고 가능한지 불가능한지
//판단한다음 끝까지 가는 경우 얼마나 +1 -1 을 했는지 뽑아줬다.
//시간복잡도는 5 * 3 * 10^5이라 충분하긴하다
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int ch = arr[1] - arr[0];
	for (int i = ch - 2; i <= ch + 2; i++) {//5개의 경우를 해본다.
		int st = 0;
		int ans = 0;
		for (int j = 0; j < 3; j++) {
			st = arr[0] + k[j];
			if (j == 1) ans = 0;
			else ans = 1;
		bool check = true;
		for (int k = 1; k < n; k++) {
			if ( abs((st + i) - arr[k])  > 1) {
				check = false;
				break;
			}
			else {
				ans += abs(st+i - arr[k]);
				st = st + i;
			}
		}

		if (check == false) continue;
		ret = min(ret, ans);
		}
	}
	if (ret == INF) cout << "-1";
	else cout << ret;
	return 0;
}
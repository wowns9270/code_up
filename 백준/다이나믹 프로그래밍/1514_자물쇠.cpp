#include<bits/stdc++.h>
#define inf 999999999
using namespace std;


int n;
string a, b;
int turn[10] = { 0,1,1,1,2,2,2,1,1,1 };
int dp[103][11][11];
//시발 몰라
int gogo(int idx, int x1, int x2) {

	if (idx == n) return 0;

	int& ret = dp[idx][x1][x2];
	if (ret != -1) return ret;

	ret = inf;

	int cur = ((a[idx] - 48) + x1) % 10; // 현재 위치
	int to = b[idx] - 48;

	for (int three = 0; three < 10; three++) {
		for (int two = 0; two < 10; two++) {
			int from = (cur + two + three) % 10;
			int one = to - from;
			if (one < 0) one += 10;
			int cost = turn[one] + turn[two] + turn[three];
			cost += gogo(idx + 1, (x2 + three + two) % 10, three);

			ret = min(ret, cost);
		}
	}
	return ret;

}

int main() {
	cin >> n;
	cin >> a >> b;
	memset(dp, -1, sizeof(dp));
	cout << gogo(0, 0, 0);
}
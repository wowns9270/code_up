//fdsa{R, I, N, G, S}
#include<bits/stdc++.h>
using namespace std;

int n, a, b;
int dp[101][101][3];
string x, y, z;

int gogo(int idx, int cnt, int type) {
	// idx 는 몇번째 칸 cnt 는 어디까지 올 순서 타입
	if (idx == a) {
		if (cnt == n) {
			return 1;
		}
		return 0;
	}

	int& ret = dp[idx][cnt][type];
	if (ret != -1) return ret;
	ret = 0;

	if (type == 1) {
		if (y[idx] == x[cnt]) {
			ret += gogo(idx + 1, cnt + 1, 2);
			ret += gogo(idx + 1, cnt, 1);
		}
		else {
			ret += gogo(idx + 1, cnt, 1);
		}
	}
	else {
		if (z[idx] == x[cnt]) {
			ret += gogo(idx + 1, cnt + 1, 1);
			ret += gogo(idx + 1, cnt, 2);
		}
		else {
			ret += gogo(idx + 1, cnt, 2);
		}
	}
	return ret;
}



int main() {

	cin >> x >> y >> z;
	n = x.size();
	a = y.size();
	b = z.size();

	memset(dp, -1, sizeof(dp));

	int t1 = gogo(0, 0, 1);
	int t2 = gogo(0, 0, 2);
	cout << t1 + t2;
	return 0;
}

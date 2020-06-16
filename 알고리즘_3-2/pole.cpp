#include<bits/stdc++.h>
using namespace std;

ifstream in("pole.inp");
ofstream out("pole.out");


int n;
long long dp[21][21][21];


long long gogo(int n, int x, int y) {

	if (n == 1) {
		if (x == 1 && y == 1) return 1;
		return 0;
	}

	long long& ret = dp[n][x][y];
	if (ret != -1) return ret;

	ret = 0;

	ret += gogo(n - 1, x - 1, y);
	ret += gogo(n - 1, x, y - 1);
	ret += gogo(n - 1, x, y) * (n - 2);

	return ret;

}


int main() {
	in >> n;
	memset(dp, -1, sizeof(dp));
	while (n--) {
		int a, b, c; in >> a >> b >> c;

		out<< gogo(a, b, c) <<"\n";
	}
	return 0;
}
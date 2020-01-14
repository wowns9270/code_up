#include<bits/stdc++.h>
using namespace std;
ifstream in("palindrome.inp");
ofstream out("palindrome.out");

string a;
int dp[10000][10000];
int gogo(int r, int l) {
	if (r == l) return 0;
	if (r + 1 == l) {
		if (a[r] == a[l]) return 0;
		else return 1;
	}
	int& ret = dp[r][l];
	if (ret != -1) return ret;
	ret = 0;
	if (a[r] == a[l]) return ret += gogo(r + 1, l - 1);
	int aaa = gogo(r + 1, l) + 1;
	int bbb = gogo(r, l - 1) + 1;
	ret = min(aaa, bbb);
	return ret;
}
int main() {
	int test; in >> test;
	while (test--) {
		in >> a;
		memset(dp, -1, sizeof(dp));
		int k =gogo(0, a.size() - 1);
		if (k == 0) out << "0\n";
		else if (k == 1) out << "1\n";
		else if (k == 2)out << "2\n";
		else out << "-1\n";
	}
	return 0;
}
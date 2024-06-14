#include<iostream>
using namespace std;


long long dp[31][62];

long long gogo(int n, int p)
{
	if (n < 0 || p < 0) return 0;

	if (n == 0 && p == 0) return 1;

	long long& ret = dp[n][p];
	if (ret != 0) return ret;

	ret = gogo(n, p - 1) + gogo(n - 1, p + 1);

	return ret;
}




int main()
{
	while (1)
	{
		int n; cin >> n;
		if (n == 0) break;

		cout << gogo(n, 0) << endl;

	}


}
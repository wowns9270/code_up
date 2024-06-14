#include<iostream>
#include<memory.h>
#include<vector>
using namespace std;

int n;
int dp[1000002];
int check[1000002];
vector<int> vec;


int gogo(int n)
{
	if (n == 1) return 0;

	int& ret = dp[n];
	if (ret != -1) return ret;

	ret = 1e9;

	int ret1 = 1e9, ret2 = 1e9, ret3 = 1e9;

	if (n % 3 == 0)
	{
		ret1 = gogo(n / 3) + 1;
	}

	if (n % 2 == 0)
	{
		ret2 = gogo(n / 2) + 1;
	}

	ret3 =  gogo(n - 1) + 1 ;

	ret = min(ret1, ret2);
	ret = min(ret, ret3);


	if (ret1 < ret2)
	{
		if (ret1 < ret3)
		{
			check[n] = n / 3;
		}
		else
		{
			check[n] = n - 1;
		}
	}
	else
	{
		if (ret2 < ret3)
		{
			check[n] = n / 2;
		}
		else
		{
			check[n] = n - 1;
		}
	}

	return ret;

}

int main()
{
	cin >> n;

	memset(dp, -1, sizeof(dp));
	cout << gogo(n) << "\n";

	int n2 = n;
	while (1)
	{
		if (n2 == 1)
		{
			cout << n2 << " ";
			break;
		}

		cout << n2 << " ";
		n2 = check[n2];
	}
}
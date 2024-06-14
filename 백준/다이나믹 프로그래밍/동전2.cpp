#include<iostream>
#include<memory.h>
using namespace std;


int n, k;
int arr[100003];
int dp[100003];

int gogo(int k)
{
	if (k == 0) return 0;
	if (k < 0) return 1e9;

	int& ret = dp[k];
	if (ret != -1) return ret;

	ret = 1e9;

	for (int i = 0; i < n; i++)
	{
		ret = min(ret, gogo(k - arr[i]) + 1);
	}
	return ret;


}

int main()
{
	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	//cout << gogo(k);

	for (int i = 0; i <= k; i++)
	{
		dp[i] = 1e9;
	}

	for (int i = 0; i < n; i++)
	{
		dp[arr[i]] = 1;
	}

	for (int i = 1; i <= k; i++)
	{

		for (int j = 0; j < n; j++)
		{
			if (i >= arr[j])
			{
				dp[i] = min(dp[i], dp[i - arr[j]] + dp[arr[j]]);
			}
		}
	}

	if (dp[k] >= 1e9)
	{
		cout << "-1";
	}
	else
	{
		cout << dp[k];
	}


}
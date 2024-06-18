#include<iostream>
using namespace std;

int dp[101], n;

int l[101];
int j[101];

int main()
{
	cin >> n;


	for (int i = 0; i < n; i++)
	{
		cin >> l[i];
	}

	for (int i = 0; i < n; i++)
	{
		cin >> j[i];
	}

	
	for (int i = 0; i < n; i++)
	{
		for (int k = 100; k > l[i]; k--)
		{
			dp[k] = max(dp[k], dp[k - l[i]] + j[i]);
		}

	}

	cout << dp[100];

}
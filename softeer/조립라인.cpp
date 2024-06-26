#include<iostream>
using namespace std;

int n;
int a[1003];
int b[1003];

int dp[1003][2];

int a_b[1003], b_a[1003]; 

int main()
{
	cin >> n; 

	for (int i = 0; i < n - 1; i++)
	{
		cin >> a[i] >> b[i] >> a_b[i] >> b_a[i]; 
	}


	cin >> a[n - 1] >> b[n - 1];

	dp[0][0] = a[0];
	dp[0][1] = b[0];


	for (int i = 1; i < n; i++)
	{

		dp[i][0] = a[i] + min(dp[i - 1][0], dp[i - 1][1] + b_a[i-1]);
		dp[i][1] = b[i] + min(dp[i - 1][1], dp[i - 1][0] + a_b[i-1]);
	}


	cout << min(dp[n - 1][0], dp[n - 1][1]);
}
#include<iostream>
#include<memory.h>
using namespace std;

int t, w;
int arr[1003];
int dp[1003][3][31];

int gogo(int j, int cur, int w)
{

	if (j == t)
	{
		return 0;
	}

	int& ret = dp[j][cur][w];
	if (ret != -1) return ret;

	//이동할 경우
	if (w > 0)
	{
		if (cur % 2 + 1 == arr[j])
		{
			ret = max(ret, gogo(j + 1, cur % 2 + 1, w - 1) + 1);
		}
		else
		{
			ret = max(ret, gogo(j + 1, cur % 2 + 1, w - 1));
		}
	}

	//안할 경우
	if (cur == arr[j])
	{
		ret = max(ret, gogo(j + 1, cur, w) + 1);
	}
	else
	{
		ret = max(ret, gogo(j + 1, cur, w));
	}
	
	return ret;
}

int main()
{
	cin >> t >> w;

	for (int i = 0; i < t; i++)
	{
		cin >> arr[i];
	}

	memset(dp, -1, sizeof(dp));

	cout << gogo(0, 1, w);


}
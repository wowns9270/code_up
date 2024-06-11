#include<iostream>
#include<memory.h>
using namespace std;

int n;
int arr[17][17];
int visited[17][70000];

bool allVisited(int visited)
{
	bool bret = true;
	for (int i = 0; i < n; i++)
	{
		if (((1 << i) & visited) == false)
		{
			bret = false;
			break;
		}
	}
	return bret;
}

int gogo(int st, int prev, int visit)
{
	if (allVisited(visit) == true)
	{
		if (arr[prev][st] != 0)
		{
			return arr[prev][st];
		}
		else
		{
			return 99999999;
		}
	}

	int& ret = visited[prev][visit];
	if (ret != 0) return ret;

	ret = 99999999;

	for (int i = 0; i < n; i++)
	{
		if ((visit & (1 << i)) <= 0)
		{
			if (arr[prev][i] != 0)
			{
				ret = min(ret, gogo(st, i, visit | (1 << i)) + arr[prev][i]);
			}
		}
	}



	return ret;
}

int main() {


	// input
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}

	//visit [st][prev][visited]
	int ret = 99999999;
	for (int i = 0; i < n; i++)
	{
		memset(visited, 0, sizeof(visited));
		ret = min(ret, gogo(i, i, 1 << i));
	}
	cout << ret;
	return 0;
}
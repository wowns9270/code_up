#include<iostream>
#include<vector>
using namespace std;

int n;
vector<int> arr;

int visited[21][21];
int checked[21];

int min_ret = 1e9;

void checking()
{
	vector<int> not_arr; 

	for (int i = 1; i <= n; i++)
	{
		if (checked[i] == 0)
		{
			not_arr.push_back(i);
		}
	}

	// °è»ê. 
	int sum1 = 0;
	for (int i = 0; i < arr.size() - 1; i++)
	{
		for (int j = i + 1; j < arr.size(); j++)
		{
			int x = arr[i] - 1;
			int y = arr[j] - 1;

			sum1 += visited[x][y];
			sum1 += visited[y][x];
		}
	}

	int sum2 = 0;
	for (int i = 0; i < not_arr.size() - 1; i++)
	{
		for (int j = i + 1; j < not_arr.size(); j++)
		{
			int x = not_arr[i] - 1;
			int y = not_arr[j] - 1;

			sum2 += visited[x][y];
			sum2 += visited[y][x];
		}
	}

	int ret = abs(sum1 - sum2);
	min_ret = min(min_ret, ret);
}

void gogo(int idx, int cnt)
{
	if (cnt == n / 2)
	{
		checking();
		return;
	}

	if (idx > n) return;

	arr.push_back(idx);
	checked[idx] = 1;
	gogo(idx + 1, cnt + 1);
	arr.pop_back();
	checked[idx] = 0;
	gogo(idx + 1, cnt);
}


int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> visited[i][j];
		}
	}

	gogo(1, 0);
	cout << min_ret;
}
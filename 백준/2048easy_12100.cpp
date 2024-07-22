#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
vector<vector<int>> arr;
vector<int> dir;


int dx[] = { 1,0,-1,0 }; // 남 동 북 서 
int dy[] = { 0,1,0,-1 };
int max_ret = 0;


vector<int> calc(vector<int> list)
{
	vector<int> ret;
	for (int i = 0; i < list.size(); i++)
	{
		if (list[i] != 0)
		{

			if (i + 1 <= list.size() - 1 && list[i] == list[i + 1])
			{
				ret.push_back(list[i] * 2);
				i++;
			}
			else
			{
				ret.push_back(list[i]);
			}
		}
	}
	return ret;
}

void processing()
{
	vector<vector<int>> copy_arr = arr;

	for (int idx = 0; idx < dir.size(); idx++)
	{
		if (dir[idx] == 0 || dir[idx] == 2)
		{
			// 열마다 계산필요 			
			for (int i = 0; i < n; i++)
			{
				vector<int> list;
				for (int j = 0; j < n; j++)
				{
					if (copy_arr[j][i] != 0) list.push_back(copy_arr[j][i]);
				}

				if (dir[idx] == 0)
				{
					reverse(list.begin(), list.end());
					vector<int> ret = calc(list);

					int idx = 0;
					for (int j = n - 1; j >= 0; j--)
					{
						if (ret.size() > idx)
						{
							copy_arr[j][i] = ret[idx];
							idx++;
						}
						else
						{
							copy_arr[j][i] = 0;
						}
					}
				}
				else
				{
					vector<int> ret = calc(list);
					int idx = 0;
					for (int j = 0; j < n; j++)
					{
						if (ret.size() > idx)
						{
							copy_arr[j][i] = ret[idx];
							idx++;
						}
						else
						{
							copy_arr[j][i] = 0;
						}
					}
				}
			}
		}
		else
		{
			for (int i = 0; i < n; i++)
			{
				vector<int> list;
				for (int j = 0; j < n; j++)
				{
					if (copy_arr[i][j] != 0) list.push_back(copy_arr[i][j]);
				}

				if (dir[idx] == 1)
				{
					reverse(list.begin(), list.end());
					vector<int> ret = calc(list);
					while (ret.size() < n)
					{
						ret.push_back(0);
					}
					copy_arr[i] = ret;
				}
				else
				{
					vector<int> ret = calc(list);
					while (ret.size() < n)
					{
						ret.push_back(0);
					}
					copy_arr[i] = ret;
				}
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			max_ret = max(max_ret, copy_arr[i][j]);
		}
	}
	return;
}

void gogo(int cnt)
{

	if (cnt == 5)
	{
		processing();
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		dir.push_back(i);
		gogo(cnt + 1);
		dir.pop_back();
	}

}

int main()
{
	cin >> n;

	arr.resize(n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int a; cin >> a;
			arr[i].push_back(a);
		}
	}

	gogo(0);

	cout << max_ret;
}
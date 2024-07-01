#include<iostream>
#include<vector>
using namespace std;

int n, m, h;

int arr[31][11];
int g_ret = 1e9;
vector<pair<int, int>> list;

bool checking()
{
	bool bret = true;
	for (int i = 0; i < n; i++)
	{
		
		int x = 0;
		int y = i;

		while (x < h)
		{
			if (arr[x][y] == 1)
			{
				y = y + 1; 
				x = x + 1;
			}
			else if (y -1 >=0 && arr[x][y-1] == 1)
			{
				y = y - 1; 
				x = x + 1; 
			}
			else
			{
				x = x + 1;
			}
		}

		if (i != y)
		{
			bret = false;
			break;
		}
	}
	return bret;
}

void gogo(int idx, int cnt)
{

	if (cnt > 3) return;

	if (checking())
	{
		g_ret = min(g_ret, cnt);
	}

	for (int i = idx; i < list.size(); i++)
	{
		int x = list[i].first;
		int y = list[i].second;

		if (y == 0)
		{
			if (arr[x][y] == 0 && arr[x][y + 1] == 0)
			{
				arr[x][y] = 1; 
				gogo(i +1 ,cnt + 1);
				arr[x][y] = 0;
			}
		}
		else if (y == n - 2)
		{
			if (arr[x][y] == 0 && arr[x][y - 1] == 0)
			{
				arr[x][y] = 1;
				gogo(i+1, cnt + 1);
				arr[x][y] = 0;
			}
		}
		else
		{
			if (arr[x][y] == 0 && arr[x][y - 1] == 0 && arr[x][y + 1] == 0)
			{
				arr[x][y] = 1; 
				gogo(i+1, cnt + 1);
				arr[x][y] = 0; 
			}
		}
	}


}

int main()
{
	cin >> n >> m >> h;

	for (int i = 0; i < m; i++)
	{
		int a, b; cin >> a >> b;

		arr[a-1][b-1] = 1;
	}

	//사다리를 놓을 수 있는 곳
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < n -1; j++)
		{
			if (j == 0)
			{
				if (arr[i][j] == 0 && arr[i][j + 1] == 0)
				{
					list.push_back({ i,j });
				}
			}
			else if (j == n - 2)
			{
				if (arr[i][j] == 0 && arr[i][j - 1] == 0)
				{
					list.push_back({ i,j });
				}
			}
			else
			{
				if (arr[i][j] == 0 && arr[i][j - 1] == 0 && arr[i][j + 1] == 0)
				{
					list.push_back({ i,j });
				}
			}
		}
	}

	if (checking())
	{
		cout << "0";
	}
	else
	{
		gogo(0,0);

		if (g_ret == 1e9)
		{
			cout << "-1";
		}
		else
		{
			cout << g_ret;
		}
	}

}
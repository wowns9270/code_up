#include<iostream>
#include<vector>
using namespace std;


int n, m;

int arr[101][101];
vector<pair<int, int>> point;


int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			arr[i][j] = -1;
		}
	}

	for (int i = 0; i < n; i++)
	{
		string k; cin >> k;
		for (int j = 0; j < k.size(); j++)
		{
			if (k[j] == 'c')
			{
				arr[i][j] = 0;
				point.push_back({ i,j });
			}
		}
	}

	while (1)
	{
		
		bool move_c = false;

		for (int i = 0; i < point.size(); i++)
		{
			int x = point[i].first;
			int y = point[i].second;

			if (y + 1 >= m)
			{
				continue;
			}

			if (arr[x][y + 1] != -1)
			{
				continue;
			}

			arr[x][y + 1] = arr[x][y] + 1;
			point[i].second = y + 1;
			move_c = true;
		}

		if (move_c == false) break;
	}
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}
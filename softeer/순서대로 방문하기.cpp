#include<iostream>
#include<vector>
using namespace std;

int n, m;
vector<vector<int>>arr;
vector<pair<int, int>> point;


int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

int check[5][5];
int ret = 0;

bool process()
{
	bool ret = true;
	int pre = 0;
	for (const auto& item : point)
	{
		if (pre < check[item.first][item.second])
		{
			pre = check[item.first][item.second];
		}
		else
		{
			// 순서가 틀렸따. 
			ret = false;
			break;
		}
	}
	return ret;
}

void gogo(int x, int y , int v)
{
	if (point[m - 1].first == x && point[m - 1].second == y)
	{
		// 마지막 지점
		check[x][y] = v;
		if (process())
		{
			ret++;
		}
		check[x][y] = 0;
		return;
	}

	check[x][y] = v;

	for (int i = 0; i < 4; i++)
	{
		int ux = x + dx[i];
		int uy = y + dy[i];

		if (ux < 0 || ux >= n || uy < 0 || uy >= n) continue; // 범위 밖.
		if (arr[ux][uy] == 1) continue; // 벽

		if (check[ux][uy] == 0)
		{
			gogo(ux, uy, v + 1);
		}
	}

	check[x][y] = 0;
}

int main()
{
	cin >> n >> m;

	arr.resize(n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int a; cin >> a;
			arr[i].push_back(a);
		}
	}

	for (int i = 0; i < m; i++)
	{
		int x, y; cin >> x >> y;
		point.push_back({ x- 1, y - 1 });
	}


	gogo(point[0].first, point[0].second, 1);
	
	std::cout << ret;
}
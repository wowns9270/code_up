#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n, m;
vector<string> vec;
int dp[51][51];
int check[51][51];

int dx[] = { 1,0,0,-1 };
int dy[] = { 0,1,-1,0 };

bool loopCheck = false;

int gogo(int x, int y)
{
	if (x < 0 || y < 0 || x >= n || y >= m) return 0;
	if (vec[x][y] == 'H') return 0;
	if (check[x][y] == 1)
	{
		loopCheck = true;
		return -1;
	}

	int& ret = dp[x][y];
	if (ret != 0) return ret;

	check[x][y] = 1;
	for (int i = 0; i < 4; i++)
	{
		int ux = x + dx[i] * (vec[x][y] - '0');
		int uy = y + dy[i] * (vec[x][y] - '0');

		ret = max(ret, gogo(ux, uy) + 1);

	}
	check[x][y] = 0;

	return ret;

}


int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		string str; cin >> str;
		vec.push_back(str);
	}

	int ret = gogo(0, 0);

	if (loopCheck == true)
	{
		cout << "-1";
	}
	else
	{
		cout << ret;
	}


}
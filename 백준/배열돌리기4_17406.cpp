#include<iostream>
#include<vector>
using namespace std;

int n, m, k;
struct pp
{
	int r, c, s;
};
vector<vector<int>>born_arr;
vector<pp> k_list;


int check[7];
vector<int> q;
int ret = 1e9;
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };

vector<vector<int>> gogo(int r, int c, int s, vector<vector<int>>& arr)
{
	vector<vector<int>> copy_arr = arr;

	for (int i = 1; i <= s; i++)
	{

		int x = r - i;
		int y = c - i;

		int dir = 0; 
		while (1)
		{
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			copy_arr[nx][ny] = arr[x][y];
			x = nx;
			y = ny;

			if (x == r - i && y == c + i)
			{
				dir++;
			}
			else if (x == r + i && y == c + i)
			{
				dir++;
			}
			else if (x == r + i && y == c - i)
			{
				dir++;
			}

			if (x == r - i && y == c - i) break;
		}
	}

	return copy_arr;
}

void processing(int cnt)
{
	if (cnt == k)
	{
		vector<vector<int>> arr = born_arr;

		for (int i = 0; i < q.size(); i++)
		{
			arr = gogo(k_list[q[i]].r -1 , k_list[q[i]].c -1, k_list[q[i]].s, arr);
		}

		for (int i = 0; i < n; i++)
		{
			int sum = 0;
			for (int j = 0; j < m; j++)
			{
				sum += arr[i][j];
			}

			ret = min(ret, sum);
		}
		return;
	}

	for (int i = 0; i < k; i++)
	{
		if (check[i] == 0)
		{
			check[i] = 1;
			q.push_back(i);
			processing(cnt + 1);
			q.pop_back();
			check[i] = 0;
		}
	}


}

int main()
{
	cin >> n >> m >> k;

	born_arr.resize(n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int a;  cin >> a;
			born_arr[i].push_back(a);
		}
	}

	for(int i=0; i<k; i++)
	{	
		int r, c, s; cin >> r >> c >> s;
		k_list.push_back({ r,c,s });
	}

	processing(0);
	cout << ret;
}
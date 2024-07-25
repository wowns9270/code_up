// 4:05
#include<iostream>
#include<vector>
#include<memory.h>
using namespace std;

int r, c, m;

struct shark { int r, c, s, d, z, isOk; };

int dx[] = { 0,-1,1,0,0 };
int dy[] = { 0, 0,0,1,-1 };

vector<shark> arr;
int check[101][101];

void gogo(int k)
{
	//if (arr[k].d == 1 && arr[k].r == 1) arr[k].d = 2;
	//if (arr[k].d == 2 && arr[k].r == r) arr[k].d = 1;
	//if (arr[k].d == 3 && arr[k].c == c) arr[k].d = 4;
	//if (arr[k].d == 4 && arr[k].c == 1) arr[k].d = 3;

	if (arr[k].d == 1 || arr[k].d == 2)
	{
		int cur = arr[k].r;
		int dist = r;
		int speed = arr[k].s;

		speed = speed % ((r - 1) * 2);

		for (int i = 0; i < speed; i++)
		{
			if (arr[k].d == 1 && arr[k].r == 1) arr[k].d = 2;
			if (arr[k].d == 2 && arr[k].r == r) arr[k].d = 1;

			arr[k].r = arr[k].r + dx[arr[k].d];
		}


	}
	else
	{
		int cur = arr[k].c;
		int dist = c;
		int speed = arr[k].s;

		speed = speed % ((c - 1) * 2);

		for (int i = 0; i < speed; i++)
		{
			if (arr[k].d == 3 && arr[k].c == c) arr[k].d = 4;
			if (arr[k].d == 4 && arr[k].c == 1) arr[k].d = 3;

			arr[k].c = arr[k].c + dy[arr[k].d];
		}
	}


	if (check[arr[k].r][arr[k].c] != -1)
	{
		int comp = arr[check[arr[k].r][arr[k].c]].z;
		if (comp > arr[k].z)
		{
			arr[k].isOk = 0;
		}
		else
		{
			arr[check[arr[k].r][arr[k].c]].isOk = 0;
			check[arr[k].r][arr[k].c] = k;
		}
	}
	else check[arr[k].r][arr[k].c] = k;
}

int main()
{
	cin >> r >> c >> m;
	memset(check, -1, sizeof(check));
	for (int i = 0; i < m; i++)
	{
		int a, b, c, d, e;
		cin >> a >> b >> c >> d >> e;
		arr.push_back({ a,b,c,d,e,1 });

		check[a][b] = i;
	}
	int sum = 0;
	for (int i = 1; i <= c; i++)
	{
		// i는 사람. 

		int best_shark = -1;
		for (int j = 1; j <= r; j++)
		{
			if (check[j][i] != -1)
			{
				best_shark = check[j][i];
				break;
			}
		}
		
		if (best_shark != -1)
		{
			sum += arr[best_shark].z;
			arr[best_shark].isOk = 0;
		}

		memset(check, -1, sizeof(check));

		for (int k = 0; k < arr.size(); k++)
		{
			if (arr[k].isOk == 1)
			{
				// check를 하는 것이 목표

				// 1. 도착 위치와 방향이 뭔지 
				gogo(k);
			}
		}

		//for (int k = 0; k < arr.size(); k++)
		//{
		//	if (arr[k].isOk == 1)
		//	{
		//		cout << k << " " <<arr[k].r << " " << arr[k].c << " " << arr[k].d << "\n";
		//	}
		//}
		//cout << "\n";
	}
	cout << sum;
}
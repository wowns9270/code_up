#include<iostream>
#include<string>
#include<vector>
using namespace std;

int r, c, ret = 1;
int check[26];
int visited[21][21];
vector<string> arr;

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };


void DFS(int x, int y , int cnt)
{
	if (check[arr[x][y] - 'A'] == 1)
	{
		ret = max(ret, cnt - 1);
		return;
	}


	check[arr[x][y] - 'A'] = 1; 
	//visited[x][y] = 1;

	for (int i = 0; i < 4; i++)
	{
		int ux = x + dx[i];
		int uy = y + dy[i];

		if (ux < 0 || uy < 0 || ux >= r || uy >= c) continue;

		//if (visited[ux][uy] == 0)
		//{
			//visited[ux][uy] = 1; 
			DFS(ux, uy, cnt + 1);
			//visited[ux][uy] = 0;
		//}
	}

	check[arr[x][y] - 'A'] = 0;


}

int main() {
	cin >> r >> c;


	for (int i = 0; i < r; i++)
	{
		string k; cin >> k;
		arr.push_back(k);
	}

	DFS(0, 0, 1);
	cout << ret;
}
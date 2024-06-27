#include<iostream>
#include<vector>
using namespace std;

int n;
int check[52];
vector<vector<int>> vec;

void remove(int r)
{
	check[r] = 1; 

	for (int i = 0; i < vec[r].size(); i++)
	{
		int nr = vec[r][i];
		remove(nr);
	}
}

int gogo(int r)
{
	
	int cnt = 0;
	int ret = 0;
	for (int i = 0; i < vec[r].size(); i++)
	{

		int nr = vec[r][i];
		if (check[nr] == 1) continue;


		ret += gogo(nr);
		cnt++;
	}

	if (cnt == 0) return 1;

	return ret;
}

int main()
{
	cin >> n;

	int root = -1; 
	vec.resize(n + 1);

	for (int i = 0; i < n; i++)
	{
		int a; cin >> a;
		if (a == -1)
		{
			root = i;
			continue;
		}

		vec[a].push_back(i);
	}

	int r; cin >> r; 

	remove(r);

	if (r == root) cout << "0";
	else cout << gogo(root);
}
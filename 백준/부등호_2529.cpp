#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int n;
vector<char> arr;
vector<string> ret;
int check[10];

void gogo(int idx, string& k)
{
	if (idx == n)
	{
		ret.push_back(k);
		return;
	}

	char bu = arr[idx];
	if (bu == '<')
	{
		int r = k[idx] - '0';

		for (int i = r + 1; i <= 9; i++)
		{
			k += ('0' + i);
			if (check[i] == 0)
			{
				check[i] = 1; 
				gogo(idx + 1, k);
				check[i] = 0;
			}
			k.pop_back();
		}
	}
	else
	{
		int r = k[idx] - '0';
		for (int i = r - 1; i >= 0; i--)
		{
			k += ('0' + i);
			if (check[i] == 0)
			{
				check[i] = 1; 
				gogo(idx + 1, k);
				check[i] = 0;
			}
			k.pop_back();
		}
	}

}

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		char c; cin >> c;
		arr.push_back(c);
	}

	string k;

	for (int i = 0; i <= 9; i++)
	{
		k += ('0' + i);
		check[i] = 1; 
		gogo(0, k );
		check[i] = 0;
		k.pop_back();
	}

	sort(ret.begin(), ret.end());

	cout << ret[ret.size() - 1] << "\n";
	cout << ret[0] << "\n";
}
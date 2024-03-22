#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

struct pp
{
	int val;
	int cnt;
	int idx;
};

int main() {


	int n, c; cin >> n >> c;

	map<int, pair<int, int>> mp;

	for (int i = 0; i < n; i++)
	{
		int a; cin >> a;

		if (mp.find(a) != mp.end()) // ¿÷¥Ÿ.
		{
			mp[a].first += 1;
		}
		else
		{
			mp[a] = { 1, i };
		}
	}

	vector<pp> arr;
	for (auto it = mp.begin(); it!= mp.end(); it++)
	{
		pp a;
		a.val = (*it).first;
		a.cnt = (*it).second.first;
		a.idx = (*it).second.second;

		arr.push_back(a);
	}

	sort(arr.begin(), arr.end(), [](const pp& l, const pp& r) ->bool {

		if (l.cnt > r.cnt) return true;
		else if (l.cnt == r.cnt)
		{
			if (l.idx < r.idx)
			{
				return true;
			}
		}

		return false;
	});

	for (int i = 0; i < arr.size(); i++)
	{
		for (int j = 0; j < arr[i].cnt; j++)
		{
			std::cout << arr[i].val << " ";
		}
	}
	return 0;
}
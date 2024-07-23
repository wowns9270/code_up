#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<pair<int, int>> arr;

int main()
{

	int n, l; cin >> n >> l;

	for (int i = 0; i < n; i++)
	{
		int st, ed; cin >> st >> ed;
		arr.push_back({ st,ed });
	}

	sort(arr.begin(), arr.end());

	int water = -1;
	int cnt = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		int st = arr[i].first;
		int ed = arr[i].second;
		
		if (water > ed)
		{
			continue;
		}

		if (st <= water)
		{
			int diff = (ed - (water + 1)) / l;
			int diff_mod = (ed - (water + 1)) % l;

			if (diff_mod > 0) diff++;

			water = (water + 1) + l * diff - 1;
			cnt += diff;
		}
		else
		{
			int diff = (ed - st) / l;
			int diff_mod = (ed - st) % l;

			if (diff_mod > 0) diff++;

			water = st + l * diff - 1;
			cnt += diff;
		}

	}

	cout << cnt;
	return 0;

}
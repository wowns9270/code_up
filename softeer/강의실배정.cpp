#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<pair<int, int>> vec;

int main()
{

	int n; cin >> n;

	vec.reserve(n);

	for (int i = 0; i < n; i++)
	{
		int st, ed; cin >> st >> ed;

		vec.emplace_back(st, ed);
	}

	std::sort(vec.begin(), vec.end(), [](pair<int, int>x, pair<int, int>y) ->bool {		
		return x.second < y.second;
	});

	int ret = 0;
	int end = 0;
	for (const auto& item : vec)
	{
		if (item.first >= end)
		{
			ret += 1;
			end = item.second;
		}
	}

	std::cout << ret;

}
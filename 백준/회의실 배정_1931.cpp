#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
vector<pair<int, int>> arr;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {

		int a, b; cin >> a >> b;

		arr.push_back({ a,b });
	}

	sort(arr.begin(), arr.end(), [](pair<int, int> fi, pair<int, int> se) ->bool {

		if (fi.second < se.second) return true;
		else if (fi.second == se.second)
		{
			if (fi.first < se.first) {
				return true;
			}
		}
		return false;
	});


	int end_time = -1;
	int ret = 0;
	for (int i = 0; i < n; i++)
	{
		if (end_time <= arr[i].first)
		{
			end_time = arr[i].second;
			ret += 1;
		}
	}
	cout << ret;
}
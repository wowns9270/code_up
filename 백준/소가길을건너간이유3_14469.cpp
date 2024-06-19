#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
vector<pair<int, int>> arr;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a, b; cin >> a >> b;
		arr.push_back({ a,b });
	}

	sort(arr.begin(), arr.end());


	int time = 0;
	for (int i = 0; i < n; i++)
	{
		if (time <= arr[i].first)
		{
			time = arr[i].first + arr[i].second;
		}
		else
		{
			time = time + arr[i].second;
		}
	}

	cout << time;
}
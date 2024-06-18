#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int n;
vector<pair<int, int>> arr;

int check[200002];

struct cmp
{
	bool operator ()(int s, int p)
	{
		return s > p;
	}
};

int main() {

	cin >> n;

	for (int i = 0; i < n; i++)
	{

		int a, b; cin >> a >> b;

		arr.push_back({ a,b });
	}

	sort(arr.begin(), arr.end());

	std::priority_queue<int,vector<int>, cmp> pq;
	int ret = 0; 
	for (int i = 0; i < arr.size(); i++)
	{
		pq.push(arr[i].second);
		ret += arr[i].second;
		if (pq.size() > arr[i].first)
		{
			ret -= pq.top();
			pq.pop();
		}
	}

	cout << ret;

}
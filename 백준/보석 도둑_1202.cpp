#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int n, k;
vector<pair<int, int>> arr;
vector<int> pack;

int check[300002];

int gogo(int value)
{

	int st = 0; 
	int ed = arr.size() - 1;

	while (st < ed)
	{

		int mid = (st + ed) / 2;
		int k = pack[mid];

		if (k == value)
		{
			st = mid;
			break;
		}
		if (k > value)
		{
			ed = mid - 1;
		}
		else
		{
			st = mid + 1; 
		}
	}

	return st;


}


int main()
{
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		int m, v; cin >> m >> v;

		arr.push_back({ m,v });
	}

	sort(arr.begin(), arr.end());

	for (int i = 0; i < k; i++) {
		int c; cin >> c;
		pack.push_back(c);
	}

	sort(pack.begin(), pack.end());

	


	//가방하나하나를 보면서 담을 수 있는 최고 보석을 담는다. 
	int v = 0;
	long long ret = 0;
	priority_queue<int> pq;
	for (int i = 0; i < k; i++)
	{

		int pack_w = pack[i];

		while (v < n)
		{
			if( arr[v].first <= pack_w)
			{
				pq.push(arr[v].second);
				v++;
			}
			else
			{
				break;
			}
		}

		if (!pq.empty())
		{
			ret += pq.top();
			pq.pop();
		}

	}

	cout << ret;

}
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


vector<int> arr;


int lower_bound(int m)
{
	int st = 0; 
	int ed = arr.size() - 1;
	while (st <= ed)
	{
		int mid = (st + ed) / 2;
		int k = arr[mid];

		if (k < m)
		{
			st = mid + 1;
		}
		else
		{
			ed = mid - 1;
		}
	}

	return st;
}


int uper_bound(int m)
{
	int st = 0;
	int ed = arr.size() - 1;
	while (st <= ed)
	{
		int mid = (st + ed) / 2;
		int k = arr[mid];

		if (k <= m)
		{
			st = mid + 1;
		}
		else
		{
			ed = mid - 1;
		}
	}

	return st;
}



int main()
{
	arr.push_back(7);
	arr.push_back(4);
	arr.push_back(3);
	arr.push_back(6);
	arr.push_back(10);
	arr.push_back(16);

	sort(arr.begin(), arr.end());

	cout << lower_bound(10) <<"\n";
	cout << uper_bound(10) << "\n";
}
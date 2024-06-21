#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

vector<string> arr;

int n;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {

		string k; cin >> k;


		string tmp = "";
		for (int i = 0; i < k.size(); i++)
		{

			if (k[i] >= '0' && k[i] <= '9')
			{
				tmp += k[i];
			}
			else
			{
				if (tmp.size() > 0)
				{
					arr.push_back(tmp);
					tmp = "";
				}
			}
		}

		if (tmp.size() > 0)
		{
			arr.push_back(tmp);
			tmp = "";
		}

	}


	// 1. 0을 제거 
	for (int i = 0; i < arr.size(); i++)
	{

		int k = -1;
		for (int j = 0; j < arr[i].size(); j++)
		{
			if (arr[i][j] >= '1' && arr[i][j] <= '9')
			{
				k = j;
				break;
			}
		}
		
		if (k != -1)
		{
			arr[i].erase(0, k);
		}
		else
		{
			arr[i] = "0";
		}
	}

	// 2. 정렬
	sort(arr.begin(), arr.end(), [](string a, string b) -> bool {

		if (a.size() < b.size()) return true;

		else if (a.size() == b.size())
		{
			for (int i = 0; i < a.size(); i++)
			{
				if (a[i] < b[i])
				{
					return true;
				}
				else if (a[i] > b[i])
				{
					return false;
				}
			}
		}

		return false;
	});

	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << "\n";
	}

	return 0;

}
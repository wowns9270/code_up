#include<iostream>
#include<vector>
using namespace std;

int n, k;
vector<int> cur;
int sum[101];
int arr[101];

int main()
{
	cin >> n >> k;

	for (int i = 0; i < k; i++)
	{
		int a; cin >> a;
		arr[i] = a;
	}

	int ret = 0;

	for (int i = 0; i < k; i++)
	{
		// 현재 꽂혀있는지.
		int val = arr[i];
		bool check = false;
		for (int j = 0; j < cur.size(); j++)
		{
			if (val == cur[j]) check = true;
		}

		if (check == true)
		{
			continue;
		}


		if (cur.size() < n)
		{
			cur.push_back(arr[i]);
		}
		else
		{
			// 뺄놈을 정해야함. 여러개면 상관없나?
			int idx = -1; 
			int pos = -1;
			
			for (int r = 0; r < n; r++)
			{
				bool bret = false;

				for (int j = i + 1; j < k; j++)
				{
					if (cur[r] == arr[j])
					{
						if (j > idx)
						{
							idx = j;
							pos = r;
						}

						bret = true;
						break;
					}
				}

				// 뒤에 더 없다?
				if (bret == false)
				{
					pos = r;c
					break;
				}
			}

			cur[pos] = arr[i];
			ret++;
		}
	}

	cout << ret;

}
#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

int main()
{
	int n, m, k; cin >> n >> m >> k;

	std::vector<int > arr;

	for (int i = 0; i < n; i++)
	{
		int a; cin >> a;
		arr.push_back(a);
	}

	sort(arr.begin(), arr.end());

	int max_num = 999999999;
	do
	{
		int idx = 0;
		int bucket = m;
		int score = 0;
		int t = k;
		while (t--)
		{
			while (bucket - arr[idx] >= 0)
			{
				bucket -= arr[idx];
				score += arr[idx];
				idx++;

				if (idx >= n) {
					idx %= n;
				}
			}
			bucket = m;
		}

		if (max_num > score)
		{
			max_num = score;
		}
	} while (next_permutation(arr.begin(), arr.end()));


	std::cout << max_num;
}
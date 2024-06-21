#include<iostream>
#include<algorithm>
using namespace std;

int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long t; cin >> t;

	while (t--)
	{
		long long n; cin >> n;

		long long cnt_2 = 0;
		long long cnt_5 = 0;


		long long k = 2;
		while (1)
		{
			if (k > n ) break;
			long long r = n / k;

			cnt_2 += r;

			k *= 2;
		}

		long long k2 = 5;
		while (1)
		{
			if (k2 > n) break;
			long long r = n / k2;

			cnt_5 += r;
			k2 *= 5;
		}

		long long cnt = min(cnt_2, cnt_5);
		cout << cnt << "\n";
	}



}
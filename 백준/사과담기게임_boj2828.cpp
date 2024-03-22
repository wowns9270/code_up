#include<iostream>

using namespace std;

int main()
{
	int n, m;

	cin >> n >> m;

	int j; cin >> j;


	int ret = 0;

	pair<int, int> cur = { 0, m - 1 }; // √÷√  0 ~ 1 

	for (int i = 0; i < j; i++)
	{
		int a; cin >> a;
		a -= 1;

		if (a >= cur.first && a <= cur.second)
		{
			continue;
		}
		else if (a > cur.second)
		{
			int diff = a - cur.second; 
			cur.first += diff;
			cur.second += diff;
			ret += diff;
		}
		else
		{
			int diff = cur.first - a;
			cur.first -= diff;
			cur.second -= diff;
			ret += diff;
		}
	}
	std::cout << ret;
	return 0;
}
#include<iostream>
#include<string>
using namespace std;

int main()
{
	int n; cin >> n;


	int r = 0; 
	int cnt = 0;
	while (1)
	{

		string str = to_string(r);

		bool check = false; 
		for (int i = 0; i < static_cast<int>(str.size()) - 2; i++ )
		{

			if (str[i] == '6' && str[i + 1] == '6' && str[i + 2] == '6')
			{
				check = true;
				break;
			}
		}

		if (check == true) cnt++;

		if (n == cnt) break;

		r++;
	}

	cout << r;
}
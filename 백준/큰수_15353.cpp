#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{

	string a, b; cin >> a >> b;

	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	int op = 0;
	string ret = "";

	for (int i = 0; i < max(a.size(), b.size()); i++)
	{
		if (i > a.size() - 1)
		{		
			int r = (b[i] - '0') + op;
			if (r == 10) {
				op = 1;
				ret += '0';
			}
			else
			{
				ret += (r + '0');
				op = 0;
			}			
		}
		else if (i > b.size() - 1)
		{
			int r = (a[i] - '0') + op;
			if (r == 10) {
				op = 1;
				ret += '0';
			}
			else
			{
				ret += (r + '0');
				op = 0;
			}
		}
		else
		{
			int r = (a[i] - '0') + (b[i] - '0') + op;
			if (r >= 10)
			{
				op = 1; 
				r -= 10;
				ret += (r + '0');
			}
			else
			{
				op = 0;
				ret += (r + '0');
			}
		}
	}

	if (op == 1) ret += '1';

	reverse(ret.begin(), ret.end());
	cout << ret;

}
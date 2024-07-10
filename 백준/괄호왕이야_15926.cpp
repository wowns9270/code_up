#include<iostream>
#include<string>
#include<stack>
using namespace std;

int check[200002];

int main()
{
	int n; cin >> n;

	string str; cin >> str;

	stack<pair<char, int>> st;
	for (int i = 0; i < str.size(); i++)
	{
		if (st.empty())
		{
			st.push({ str[i], i });
		}
		else
		{
			if (str[i] == ')')
			{
				if (st.top().first == '(')
				{
					check[st.top().second] = 1;
					check[i] = 1;
					st.pop();
				}
			}
			else
			{
				st.push({ str[i], i });
			}
		}
	}

	int ret = 0; 
	int tmp_ret = 0;
	for (int i = 0; i < str.size(); i++)
	{
		if (check[i] == 1) tmp_ret++;
		else
		{
			ret = max(ret, tmp_ret);
			tmp_ret = 0;
		}
	}

	ret = max(ret, tmp_ret);

	cout << ret;
}
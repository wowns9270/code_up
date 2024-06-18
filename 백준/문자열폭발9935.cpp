#include<iostream>
using namespace std;




int main()
{
	string a, b; cin >> a >> b;

	string ret = "";
	for (int i = 0; i < a.size(); i++)
	{
		ret.push_back(a[i]);

		if (ret.size() >= b.size())
		{

			int st_idx = ret.size() - b.size();

			bool check = true;
			for (int i = 0; i < b.size(); i++)
			{
				if (ret[st_idx + i] != b[i])
				{
					check = false;
				}
			}

			if (check == true)
			{
				ret.erase(st_idx, b.size());
			}
		}
	}

	if (ret.empty()) cout << "FRULA";
	else cout << ret;
}
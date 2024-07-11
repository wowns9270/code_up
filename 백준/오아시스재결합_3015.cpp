#include<iostream>
#include<stack>
using namespace std;

int main()
{
	int n; cin >> n;
	

	long long ret = 0; 

	stack<pair<int, int>> st;

	for (int i = 0; i < n; i++)
	{
		int a; cin >> a;
		if (st.empty()) st.push({ a, 1 });
		else
		{
			while (1)
			{
				if (st.empty())
				{
					st.push({ a,1 });
					break;
				}

				int num = st.top().first;
				int cnt = st.top().second;

					
				if (a > num)
				{
					ret += cnt;
					st.pop();
				}
				else if (a == num)
				{
					st.pop();

					if (st.empty())
					{
						ret += cnt;
						st.push({ num, cnt + 1 });
					}
					else
					{
						ret += cnt;
						ret += 1;
						st.push({num, cnt + 1});
					}
					break;
				}
				else
				{
					ret += 1;
					st.push({ a, 1 });
					break;
				}
			}
		}
	}

	std::cout << ret;
}
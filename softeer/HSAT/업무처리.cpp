#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int h, k, r;


int main() {
	cin >> h >> k >> r;

	int allNode = (2 << h);

	vector<vector<queue<int>>> arr(2 << h ,vector<queue<int>>(2));


	for (int i = (1 << h); i < (1 << h + 1); i++)
	{
		for (int j = 0; j < k; j++) {
			int v; cin >> v; 
			// 말단은 0에 저장 (R ) 
			arr[i][0].push(v);
		}
	}

	for (int i = 1; i <= r; i++)
	{
		
		for (int j = 1; j < (2 << h); j++)
		{
			// 말단인 경우, 
			if (j >= (1 << h) && j < (1 << (h + 1)))
			{
				if (!arr[j][0].empty())
				{
					int v = arr[j][0].front();
					arr[j][0].pop();
					arr[j / 2][j % 2].push(v);
				}
			}
			else
			{
				if (i % 2 == 1) // 홀수 날에는 왼쪽 직원이 올린
				{
					if (!arr[j][0].empty())
					{
						int v = arr[j][0].front();
						arr[j][0].pop();
						arr[j / 2][j % 2].push(v);
					}
				}
				else
				{
					if (!arr[j][1].empty())
					{
						int v = arr[j][1].front();
						arr[j][1].pop();
						arr[j / 2][j%2].push(v);
					}
				}
			}
		}
	}

	int ret = 0;

	while (!arr[0][1].empty())
	{
		ret += arr[0][1].front();
		arr[0][1].pop();
	}

	cout << ret;

}
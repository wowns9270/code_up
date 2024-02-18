#include<iostream>
#include<vector>
using namespace std;

int n, m;
vector<vector<int>> arr;


int dx[] = { 0,-1,0,1 };
int dy[] = { 1,0,-1,0 };
struct people
{
	int x;
	int y;
};

vector<people> list;
// ������� ����� ����, 
// ����
// ģ������ ���� ( ��ġ ) 
// ���ʰ� ����Ǿ�����

int sum = 0;
int max_sum = 0;

void gogo(int cur , int sec, int sum)
{
	if (sec == 4)
	{
		max_sum = max(max_sum, sum);
		return;
	}

	for (int i = 0; i < 4; i++)
	{

		if( list[cur].x + dx[i] <= 0 || 
			list[cur].x + dx[i] > n ||
			list[cur].y + dy[i] <= 0 ||
			list[cur].y + dy[i] > n)
			{
				continue;
			}

		
		// ���� �԰�,
		int value = arr[list[cur].x - 1][list[cur].y - 1];
		sum += value;
		arr[list[cur].x - 1][list[cur].y - 1] = 0;

		// �̵�
		list[cur].x = list[cur].x + dx[i];
		list[cur].y = list[cur].y + dy[i];

		// ���� ģ��
		if (cur + 1 == m)
		{
			gogo(0, sec + 1, sum);
		}
		else
		{
			gogo(cur + 1, sec, sum);
		}

		// �ٽ� ���ƿ;���. 
		list[cur].x -= dx[i];
		list[cur].y -= dy[i];
		sum -= value;
		arr[list[cur].x - 1][list[cur].y - 1] = value;
	}
}


int main()
{
	cin >> n >> m;

	arr.resize(n);
	for (int i = 0; i < arr.size(); i++)
	{
		arr[i].resize(n);
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int val; cin >> val;
			arr[i][j] = val;
		}
	}


	for (int i = 0; i < m; i++)
	{
		int x, y; cin >> x >> y;
		people tmp = { x, y };
		list.push_back(tmp);
	}

	// ��������� �̵��� ��Ű�� ���� �ð����� 
	// ������ ������� ��� ( ��Ž ) 

	// m������ ���°� �����Ǿ�� �Ѵ�. 

	gogo(0, 0, 0);

	std::cout << max_sum;
}
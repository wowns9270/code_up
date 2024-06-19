#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, q;
vector<int > arr;


void gogo(int m)
{
	// ������ 5���� ( n )
	// ������ 20���� ( q )

	// n * q �� �ð��ʰ� 
	// lonN * q 

	// �ִ��� ã�´�. 

	int st = 0;
	int ed = arr.size() - 1;
	int ret = -1;

	while (st <= ed)
	{
		int mid = (st + ed) / 2;
		int k = arr[mid];

		if (k < m)
		{
			st = mid + 1;
		}
		else
		{
			ed = mid - 1;
		}
	}


	if (st < arr.size())
	{
		if (arr[st] == m) ret = st;
	}

	if (ret == -1) cout << "0" << "\n";
	else
	{
		cout << ret * (arr.size() - (ret + 1)) << "\n";
	}
}


int main() {

	cin >> n >> q;

	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		arr.push_back(a);
	}
	sort(arr.begin(), arr.end());

	for (int i = 0; i < q; i++)
	{
		int r; cin >> r;
		gogo(r);
	}

}
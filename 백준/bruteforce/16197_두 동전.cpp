#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int n, m;

char arr[20][20];
bool check[20][20];
vector<pair<int, int>> coin;
int ret = 11;

//����
void bruteforce(int cnt, int x1, int y1, int x2, int y2) {

	//10���� �Ѱ� �ϸ� ����
	if (cnt == 11) return;

	//2�������� �����ǿ��� ���������
	if ((x1 >= 0 && x1 < n && y1 >= 0 && y1 < m) && (x2 < 0 || x2 >= n || y2 < 0 || y2 >= m)) {
		ret = min(ret, cnt);
		return;
	}

	//1�������� ���������
	if ((x2 >= 0 && x2 < n && y2 >= 0 && y2 < m) &&
		(x1 < 0 || x1 >= n || y1 < 0 || y1 >= m)) {
		ret = min(ret, cnt);
		return;
	}
	//�Ѵ� �������� �ȵǿ�
	if (x1 < 0 || x1 >= n || y1 < 0 || y1 >= m ||
		x2 < 0 || x2 >= n || y2 < 0 || y2 >= m) {
		return;
	}
	//4�������� ������ �̵���Ų��.
	for (int i = 0; i < 4; i++) {
		int n_x1 = x1 + dx[i];
		int n_y1 = y1 + dy[i];
		int n_x2 = x2 + dx[i];
		int n_y2 = y2 + dy[i];

		//�̵��Ϸ��� ĭ�� ��(#) �̶�� ������ġ��
		if (n_x1 >= 0 && n_x1 < n && n_y1 >= 0 && n_y1 < m && arr[n_x1][n_y1] == '#') {
			n_x1 = x1;
			n_y1 = y1;
		}
		//�ι�° ������ ��������
		if (n_x2 >= 0 && n_x2 < n && n_y2 >= 0 && n_y2 < m && arr[n_x2][n_y2] == '#') {
			n_x2 = x2;
			n_y2 = y2;
		}
		//���� �ܰ�� �Ѿ��.
		bruteforce(cnt + 1, n_x1, n_y1, n_x2, n_y2);
	}
}

int main() {
	cin >> n >> m;
	//���� �ΰ��� ��ġ�� ���ͷ� �̾��ش�.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'o') {
				coin.push_back(make_pair(i, j));
			}
		}
	}

	//�Լ��� �ѱ� �� ������ ��ġ�� �Ű����� ������ �Ѱܼ�
	//�������� ����ϴ� �ͺ��� ȿ�������� �ҽ��� © �� �ִ�.
	bruteforce(0, coin[0].first, coin[0].second, coin[1].first, coin[1].second);
	
	//���� �������� 10���� ũ�ٴ� �Ҹ��ϱ� �� �ѵ����� ����߸� �� ����
	//10������ ���� �ؾ��ؼ�
	if (ret == 11) cout << "-1";
	else
		cout << ret;
	return 0;
}
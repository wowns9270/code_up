#include<bits/stdc++.h>
#pragma warning(disable:4996)
using namespace std;

//���� �߿��Ѻκ� ���⸶�� �ſ��� ������
//�� 1���ſ����� 2���ſ����� �Ǵ��Ŀ�
//�׹��⿡�� ��� �Ǵ��� 
//2���ſ￡�� ������ 2 ��� d[2][2] = 0 
//  2(��) -> 0 (��)���� �̵��� ���� 
//##################################################
int dx[] = { 1,-1,0,0 }; //���ϵ���
int dy[] = { 0,0,1,-1 };

int d[3][4] = { //���� �迭
	{}, {3,2,1,0} , {2,3,0,1}
};
//##################################################
int test, t_n = 1, ret, n;
bool check[1001][1001];
int arr[1001][1001];

int main() {
	cin >> test;
	while (test--) {
		ret = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%1d", &arr[i][j]);
			}
		}
		//memory.h �ȵǳ�?
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				check[i][j] = false;
			}
		}
		int dir = 2;
		int x = 0;
		int y = 0;
		while (1) {
			if (x < 0 || y < 0 || x >= n || y >= n) break;

			if (arr[x][y] == 1) {

				dir = d[arr[x][y]][dir];

				if (check[x][y] == false) {
					check[x][y] = true;
					ret++;
				}

			}
			else if (arr[x][y] == 2) { // �ſ��� �ֵ�.

				dir = d[arr[x][y]][dir]; //������ �ٲ��ְ�

				if (check[x][y] == false) {
					check[x][y] = true;
					ret++;
				}
			}
			else {
			}
			x += dx[dir];
			y += dy[dir];
		}
		cout << "Case #" << t_n++ << "\n";
		cout << ret << "\n";
	}
}
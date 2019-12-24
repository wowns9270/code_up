#include<iostream>
#include<memory.h>
#include<algorithm>
using namespace std;

int arr[500][500];
bool check_arr[500][500];
int n, m;
int ret;

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

void bruteforce(int x, int y, int cnt, int sum) {
	if (cnt == 4) {
		ret = max(ret, sum);
		return;
	}
	if (x < 0 || y < 0 || x >= n || y >= m) return;
	for (int i = 0; i < 4; i++) {
		if (check_arr[x + dx[i]][y + dy[i]] == false) {
			check_arr[x + dx[i]][y + dy[i]] = true;
			bruteforce(x + dx[i], y + dy[i], cnt + 1, sum + arr[x][y]);
			check_arr[x + dx[i]][y + dy[i]] = false;
		}
	}
}
int main() {
	cin >> n >> m;
	memset(check_arr, false, sizeof(check_arr));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			check_arr[i][j] = true;
			bruteforce(i, j, 0, 0);
			check_arr[i][j] = false;
			if (j + 2 < m) {
				int temp = arr[i][j] + arr[i][j + 1] + arr[i][j + 2];
				if (i - 1 >= 0) {
					int	temp2 = temp + arr[i - 1][j + 1];

					ret = max(ret, temp2);
				}
				if (i + 1 < n) {
					int	temp2 = temp + arr[i + 1][j + 1];

					ret = max(ret, temp2);
				}
			}
			if (i + 2 < n) {
				int temp = arr[i][j] + arr[i + 1][j] + arr[i + 2][j];

				if (j + 1 < m) {
					int temp2 = temp + arr[i + 1][j + 1];

					ret = max(ret, temp2);
				}
				if (j - 1 >= 0) {
					int	temp2 = temp + arr[i + 1][j - 1];

					ret = max(ret, temp2);
				}
			}
		}
	}
	cout << ret;
	return 0;
}
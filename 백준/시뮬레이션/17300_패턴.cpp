#include<bits/stdc++.h>
using namespace std;

int ret[10][10];
bool visit[10];
int arr[10];
int main() {
	int n; cin >> n;
	ret[1][3] = 1; ret[3][1] = 1;
	ret[1][7] = 1; ret[7][1] = 1;
	ret[1][9] = 1; ret[9][1] = 1;
	ret[2][8] = 1; ret[8][2] = 1;
	ret[3][7] = 1; ret[7][3] = 1;
	ret[3][9] = 1; ret[9][3] = 1;
	ret[4][6] = 1; ret[6][4] = 1;
	ret[7][9] = 1; ret[9][7] = 1;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	visit[arr[0]] = true;
	for (int i = 1; i < n; i++) {
		if (visit[arr[i]] == false) {

			if (ret[arr[i - 1]][arr[i]] == 1) {
				if (visit[(arr[i - 1] + arr[i]) / 2] == false) {
					cout << "NO";
					return 0;
				}
				else {
					visit[arr[i]] = true;
					continue;
				}
			}
			else {
				visit[arr[i]] = true;
				continue;
			}
		}
		else {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	return 0;
}
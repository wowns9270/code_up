#include<bits/stdc++.h>
using namespace std;
int pl, ze, mi, n;
int arr[2200][2200];
bool check(int size, int x, int y) {
	int k = arr[x][y];
	for (int i = x; i < x + size; i++) {
		for (int j = y; j < y + size; j++) {
			if (k != arr[i][j])
				return false;
		}
	}
	return true;
}
void gogo(int size, int x, int y) {
	if (check(size, x, y)) { // 현재 한가지 수로 되어있는지
		if (arr[x][y] == -1) mi++;
		else if (arr[x][y] == 0) ze++;
		else pl++;
		return;
	}

	//안되면 9부분으로 쪼개져서 다시
	int n_size = size / 3;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			gogo(n_size, x + n_size * i, y + n_size * j);
		}
	}
}

//분할정복 
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	gogo(n, 0, 0);
	cout << mi << "\n" << ze << "\n" << pl;
	return 0;
}
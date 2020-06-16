//2621 매우 구체적 구현을 하는 문제
// 하라는 대로하면 된다. 그게 어려운거지만

//색깔은 4가지 그리고 1~ 9까지 수

#include<bits/stdc++.h>
using namespace std;

int arr[4];//r b y g
int num[10];
int ret;

int main() {
	int a = 5;
	while (a--) {
		char b;
		int c;
		cin >> b >> c;

		if (b == 'R') arr[0]++;
		if (b == 'B') arr[1]++;
		if (b == 'Y') arr[2]++;
		if (b == 'G') arr[3]++;
		num[c]++;
	}
	
	if (arr[0] == 5 || arr[1] == 5 || arr[2] == 5 || arr[3] == 5) {

		bool check = false;
		int idx = -1;
		for (int i = 0; i <= 5; i++) {

			if (num[i] == 1 && num[i + 1] == 1 && num[i + 2] == 1 &&
				num[i + 3] == 1 && num[i + 4] == 1) {
				check = true;
				idx = i + 4;
			}
		}

		if (check == true) {
			ret = 900 + idx;
		}
	}
	
	bool check = false;
	int idx = -1;
	for (int i = 0; i <= 9; i++) {
		if (num[i] == 4) {
			check = true;
			idx = i;
		}
	}
	if (check == true) ret = max(ret, 800 + idx);

	check = false;
	idx = -1;

	for (int i = 0; i <= 9; i++) {
		for (int j = 0; j <= 9; j++) {
			if (i != j) {
				if (num[i] == 3 && num[j] == 2) {
					ret = max(ret, 700 + i * 10 + j);
				}
			}
		}
	}

	for (int i = 0; i < 5; i++) {
		if (arr[i] == 5) {

			for (int j = 9; j >= 0; j--) {
				if (num[j] > 0) {
					ret = max(ret, 600 + j);
					break;
				}
			}

		}
	}

	for (int i = 0; i <= 5; i++) {
		if (num[i] == 1 && num[i + 1] == 1 && num[i + 2] == 1 &&
			num[i + 3] == 1 && num[i + 4] == 1) {
			ret = max(ret, 500 + i + 4);
		}
	}

	for (int i = 0; i <= 9; i++) {
		if (num[i] == 3) {
			ret = max(ret, 400 + i);
		}
	}

	for (int i = 0; i <= 9; i++) {
		for (int j = 0; j <= 9; j++) {
			if (i != j) {
				if (num[i] == 2 && num[j] == 2) {

					ret = max(ret, 300 + max(i,j) * 10 + min(i,j));
				}
			}
		}
	}

	for (int i = 0; i <= 9; i++) {
		if (num[i] == 2) {
			ret = max(ret, 200 + i);
		}
	}

	for (int i = 0; i <= 9; i++) {
		if (num[i] > 0) {
			ret = max(ret, 100 + i);
		}
	}

	cout << ret;
}
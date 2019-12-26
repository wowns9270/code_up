#include<iostream>
#include<vector>
using namespace std;

int n;
int ret;

vector<pair<int, int>> queen;

bool check(int n_low, int n_col) {

	for (int i = 0; i < queen.size(); i++) {
		if (queen[i].second == n_col) {
			return false;
		}
		else if (abs(n_low - queen[i].first) == abs(n_col - queen[i].second)) {
			return false;
		}
	}

	return true;
}

void back(int low) {

	if (low == n ) {
		ret++;
		return;
	}

	for (int i = 0; i < n; i++) {
		if (check(low, i)) {
			queen.push_back(make_pair(low, i));
			back(low + 1);
			queen.pop_back();
		}
	}
}

//백트래킹
int main() {

	cin >> n;
	back(0);


	cout << ret;
	return 0;
}
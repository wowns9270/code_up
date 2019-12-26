#include<iostream>
#include<vector>
using namespace std;

int k, n, f;
bool arr[901][901];
vector<int> select_student;
bool select_arr[901];
pair<int, bool> check_friend[901];

bool check(int x, int cnt) {
	bool check_st = true;
	for (int i = 0; i < cnt; i++) {
		if (arr[select_student[i]][x] == false) {
			return false;
		}
	}
	return true;
}
void bruteforce(int cnt, int idx) {
	if (cnt == k) {
		for (int i = 0; i < select_student.size(); i++) {
			cout << select_student[i] << "\n";
		}
		exit(0);
	}
	for (int i = 1; i <= n; i++) {
		if (select_arr[i] == false && check_friend[i].second == true) {
			if (check(i, cnt)) {
				select_arr[i] = true;
				select_student.push_back(i);
				bruteforce(cnt + 1, i);
				select_student.pop_back();
				select_arr[i] = false;
			}
		}
	}
	return;
}
int main() {
	cin >> k >> n >> f;
	for (int i = 0; i < f; i++) {
		int a, b; cin >> a >> b;
		arr[a][b] = true;
		arr[b][a] = true;
		check_friend[a].first++;
		check_friend[b].first++;
	}

	for (int i = 1; i <= n; i++) {
		if (check_friend[i].first < k - 1) {
			check_friend[i].second = false;
		}
		else check_friend[i].second = true;
	}
	bruteforce(0, 1);
	cout << "-1";
	return 0;
}
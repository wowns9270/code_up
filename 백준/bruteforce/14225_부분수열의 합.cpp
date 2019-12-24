#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;

vector<int> arr;
set<int> result;
int n;
void bruteforce(int idx, int sum) {
	if (idx == n) {
		result.insert(sum);
		return;
	}
	bruteforce(idx + 1, sum + arr[idx]);
	bruteforce(idx + 1, sum);
}
int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		int a; cin >> a; arr.push_back(a);
	}
	bruteforce(0, 0);
	set<int>::iterator it;
	for (int i = 1; ; i++) {
		it = result.find(i);
		if (it == result.end()) {
			cout << i;
			break;
		}
	}
	return 0;
}
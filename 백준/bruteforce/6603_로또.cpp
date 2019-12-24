#include<iostream>
#include<vector>
using namespace std;

vector<int>rotto;
vector<int>result;
int n;
void bruteforce(int cnt, int idx) {
	if (cnt == 6) {

		for (int i = 0; i < result.size(); i++) {
			cout << result[i] << " ";
		}
		cout << "\n";
		return;
	}

	if (idx == n) return;

	result.push_back(rotto[idx]);
	bruteforce(cnt + 1, idx + 1);
	result.pop_back();
	bruteforce(cnt, idx + 1);
	return;
}

int main() {

	while (1) {
		rotto.clear();
		cin >> n;
		if (n == 0) break;

		for (int i = 0; i < n; i++) {
			int k; cin >> k;
			rotto.push_back(k);
		}

		bruteforce(0, 0);
		cout << "\n";
	}
	return 0;
}
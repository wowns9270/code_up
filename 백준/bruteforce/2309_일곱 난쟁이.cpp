#include<bits/stdc++.h>
using namespace std;
vector<int>nine;
vector<int> ret;
int summ() {
	int k = 0;
	for (int a : ret) {
		k += a;
	}
	return k;
}
void gogo(int idx, int cnt, int sum) {
	if (idx == 9) {
		if (cnt == 7 && sum == 100) {
			for (int a : ret) cout << a << "\n";
			exit(0);
		}
		return;
	}
	ret.push_back(nine[idx]);
	gogo(idx + 1, cnt + 1, sum + nine[idx]);
	ret.pop_back();
	gogo(idx + 1, cnt, sum);
}
int main() {
	for (int i = 0; i < 9; i++) {
		int a; cin >> a;
		nine.push_back(a);
	}
	sort(nine.begin(), nine.end());
	gogo(0, 0, 0);
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
int n, m;
set<string> ret;
string k;
int arr[9];
void gogo(int idx, int cnt, string kk) {
	if (cnt == m) {
		if (ret.find(kk) == ret.end()) {
			ret.insert(kk);
			for (int i = 0; i < kk.size(); i++) {
				if (kk[i] == ' ')cout << " ";
				else cout << kk[i];
			}
			cout << "\n";
			return;
		}
		return;
	}
	if (idx == n) return;
	string temp = to_string(arr[idx]) + " ";
	gogo(idx + 1, cnt + 1, kk + temp);
	gogo(idx + 1, cnt, kk);
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	gogo(0, 0, k);
	return 0;
}
#include<bits/stdc++.h>
using namespace std;

int arr[100001];
vector<char> ret;
int main() {
	int n; cin >> n;
	stack<int> st;
	for (int i = 0; i < n; i++) cin >> arr[i];
	int cnt = 1;
	int idx = 0;
	while (1) {
		if (cnt > n) break;
		if (idx == n) break;

		if (st.empty() || st.top() != arr[idx]) {
			ret.push_back('+');
			st.push(cnt++);
		}
		else if (st.top() == arr[idx]) {
			ret.push_back('-');

			st.pop();
			idx++;
		}
	}
	for (int i = idx; ; i++) {
		if (st.empty()) break;

		if (st.top() == arr[idx++]) {
			ret.push_back('-');
			st.pop();
		}
		else break;
	}
	if (st.size() == 0) {
		for (char c : ret) {
			cout << c << "\n";
		}
	}
	else cout << "NO";
	return 0;
}
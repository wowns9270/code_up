#include<bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	stack<int> st;
	while (n--) {
		string n; cin >> n;
		if (n == "push") {
			int a; cin >> a;
			st.push(a);
		}
		else if (n == "top") {
			if (st.empty()) cout << "-1\n";
			else cout << st.top() << "\n";
		}
		else if (n == "size") cout << st.size() << "\n";
		else if (n == "empty") {
			if (st.empty()) cout << "1\n";
			else cout << "0\n";
		}
		else if (n == "pop") {
			if (st.empty())cout << "-1\n";
			else {
				cout << st.top() << "\n";
				st.pop();
			}
		}
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
int n;
int arr[1000001];
int ret[1000001];
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) { cin >> arr[i]; }
	stack<int> st;
	for (int i = n - 1; i >= 0; i--) {
		if (st.empty()) {
			st.push(arr[i]);
			ret[i] = -1;
		}
		else {
			if (arr[i] < st.top()) {
				ret[i] = st.top();
				st.push(arr[i]);
			}
			else {
				while (!st.empty()) {
					if (st.top() <= arr[i]) st.pop();
					else break;
				}
				if (!st.empty()) {
					ret[i] = st.top();
					st.push(arr[i]);
				}
				else {
					st.push(arr[i]);
					ret[i] = -1;
				}
			}
		}
	}
	for (int i = 0; i < n; i++) cout << ret[i] << " ";
	return 0;
}
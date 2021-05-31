#include<bits/stdc++.h>
using namespace std;


ifstream in("transform.inp");
ofstream out("transform.out");

int test, n, p;

vector<int> arr;

string ret;

void gogo(int s, int e, int k) {

	if (s > e) return;
	ret += '(';


	int idx = -1;
	int max_k = -1;
	for (int i = s; i <= e; i++) {
		max_k = max(max_k, arr[i]);
		if (arr[i] == k) {
			idx = i;
			break;
		}
	}

	if (s == idx) {
		ret += ')';
		gogo(s + 1, e, k + 1);
	}
	else {

		gogo(s, idx - 1, k + 1);
		ret += ')';
		gogo(idx + 1, e, max_k + 1);
	}



}

int main() {
	in >> test;

	while (test--) {

		in >> n >> p;

		out << n << " ";

		if (p == 0) {
			arr.clear();

			for (int i = 0; i < n; i++) {
				int a; in >> a;
				arr.push_back(a);
			}
			ret = "";
			gogo(0, arr.size() - 1, 1);

			out << ret << "\n";
		}
		else if (p == 1) {

			string r; in >> r;


			vector<int> ans;
			int get = 1;
			stack<int> st;

			for (int i = 0; i < r.size(); i++) {

				if (r[i] == '(') {
					st.push(get++);
				}
				else if (r[i] == ')') {
					int e = st.top();
					st.pop();
					ans.push_back(e);
				}
			}

			for (int i = 0; i < ans.size(); i++) {
				out << ans[i] << " ";
			}
			out << "\n";




		}
	}

	return 0;
}
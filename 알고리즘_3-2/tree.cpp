#include<bits/stdc++.h>
using namespace std;
ifstream in("tree.inp");
ofstream out("tree.out");
int n; string a;
int main() {
	in >> n;
	in.ignore();
	while (n--) {
		getline(in, a);
		int r = 0, state = 0;
		string b;
		out << a << "\n" << "Preorder\n";
		for (int i = 0; i < a.size(); i++) {
			if (a[i] == '(') out << "r" << r++ << "\n";
			else if (a[i] == ' ') {
				if (state == 0) continue;
				else { out << b << "\n"; b = ""; state = 0; }
			}
			else if (a[i] >= 'A' && a[i] <= 'Z') { b += a[i]; state = 1; }
			else if (state == 1 && a[i] >= '0' && a[i] <= '9') { b += a[i]; }
		}
		out << "Inorder\n";
		r = 0; state = 0; int right = 0;
		stack<int> st;
		for (int i = 0; i < a.size(); i++) {
			if (a[i] == '(') {
				st.push(r++);
			}
			else if (a[i] == ' ') {
				if (state == 0) continue;
				else {
					if (right == 1) {
						out << b << "\n"; b = "";
						out << "r" << st.top() << "\n"; st.pop();
						state = 0;
					}
					else {
						out << b << "\n"; b = "";
						state = 0;
						if (!st.empty()) {
							out << "r" << st.top() << "\n";
							st.pop();
						}
					}
				}
			}
			else if (a[i] >= 'A' && a[i] <= 'Z') {
				b += a[i]; state = 1;
				if (a[i - 2] == '(') right = 1;
				else  right = 0;
			}
			else if (state == 1 && a[i] >= '0' && a[i] <= '9') { b += a[i]; }
		}
	}
	return 0;
}
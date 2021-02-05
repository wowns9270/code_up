#include<bits/stdc++.h>
using namespace std;


int solution(string S) {
	// write your code in C++14 (g++ 6.2.0)

	stack<char> st;

	for (int i = 0; i < S.size(); i++) {
		
		char k = S[i];


		if (st.empty()) {
			st.push(k);
		}
		else {

			int top = st.top();

			if (k == '}') {
				if (top == '{') st.pop();
			}
			else if (k == ']') {
				if (top == '[') st.pop();
			}
			else if (k == ')') {
				if (top == '(') st.pop();
			}
			else {
				st.push(k);
			}
		}
	}

	if (!st.empty()) return 0;
	else return 1;


}



int main() {
	cout << solution("{[()()]}");
}
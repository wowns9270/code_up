#include<bits/stdc++.h>
using namespace std;

int solution(string S) {
    
    stack<char> st;

    for (int i = 0; i < S.size(); i++) {

        if (S[i] == '(') st.push('(');
        else {

            char k = st.top();

            if (k == '(') st.pop();
        }
    }

    if (st.empty()) return 1;
    else {
        return 0;
    }

}

int main() {
    cout << solution("(()(())())");
}
#include<bits/stdc++.h>
using namespace std;


stack<char> st;

int solution(string s)
{
    int answer = 0;

    for (int i = 0; i< s.size(); i++) {

        char a = s[i];


        if (st.empty()) st.push(a);
        else if (st.top() == a) {
            st.pop();
        }
        else {
            st.push(a);
        }
    }

    if (st.empty()) return 1;
    else return 0;




   
}




int main() {


    solution("baabaa");

}
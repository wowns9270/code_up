#include<bits/stdc++.h>
using namespace std;


int solution(vector<int> H) {
    // write your code in C++14 (g++ 6.2.0)
    
    stack <int> st;
    int ret = 0;

    for (int i = 0; i < H.size(); i++) {


        int h = H[i];


        if (st.empty()) {
            st.push(h);
        }
        else {

            int top = st.top();

            if (top < h) {
                st.push(h);
            }
            else if (top == h) {
                continue;
            }
            else {
                int cnt = 0;
                while (!st.empty()) {

                    int r = st.top();

                    if (r > h) {
                        cnt++;
                        st.pop();

                        if (st.empty()) {
                            st.push(h);
                            break;
                        }
                    }
                    else if (r < h) {
                        st.push(h);
                        break;
                    }
                    else {
                        break;
                    }
                }
                ret += cnt;
            }
        }
    }

    ret += st.size();

    return ret;
}

int main() {

    cout << solution({ 8,8,5,7,9,8,7,4,8 });


}

#include<bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> A, int K) {
    // write your code in C++14 (g++ 6.2.0)

    if (A.size() == 0) return A;

    deque<int> q;

    for (int i = 0; i < A.size(); i++) {
        q.push_back(A[i]);
    }



    for (int i = 0; i < K; i++) {

        int r = q.back();

        q.pop_back();

        q.push_front(r);
    }

    A.clear();

    while (!q.empty()) {

        A.push_back(q.front());

        q.pop_front();
   }
    return A;

}

int main() {
    solution({ }, 3);
}
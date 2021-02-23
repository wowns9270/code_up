#include<bits/stdc++.h>

using namespace std;


set<int> ret;


int solution(vector<int> A) {
    

    for (int i = 0; i < A.size(); i++) {

        int k = A[i];

        k = abs(k - 0);

        if (ret.find(k) == ret.end()) {
            ret.insert(k);
        }
    }

    cout << ret.size();
    return ret.size();
}

int main() {
    solution({ -5,-3,-1,0,3,6 });
}
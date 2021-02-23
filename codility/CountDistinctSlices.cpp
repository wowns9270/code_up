#include<bits/stdc++.h>
using namespace std;

int check[100004];

int solution(int M, vector<int> A) {
    
    int lo = 0;
    int hi = 0;
    
    long long cnt = 0;

    while (hi < A.size()) {

        if (check[A[hi]] == 0) {

            int k = hi - lo; // 원소의개수
            cnt += k + 1;
            check[A[hi]]++;
            hi++;
        }
        else {
            check[A[lo]]--;
            lo++;
        }
    }

    if (cnt > 1000000000) return 1000000000;

    return cnt;


}

int main() {
    cout << solution(7 , { 0,1,2,3,1,4 });
}

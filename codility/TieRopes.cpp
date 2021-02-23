#include<bits/stdc++.h>
using namespace std;


int solution(int K, vector<int> A) {
    
    int cnt = 0;

    int sum = 0;
    int ret = 0;
    for (int i = 0; i < A.size(); i++) {

        if (sum + A[i] < K) {
            cnt++;
            sum += A[i];
        }
        else {
            sum = 0;
            ret++;
        }
    }


    return ret;

}

int main() {
    cout << solution(4, { 1,2,3,4,1,1,3 });
}

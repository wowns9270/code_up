#include<bits/stdc++.h>
using namespace std;

int solution(int K, int M, vector<int> A) {
    

    int sum = M * A.size();
    int lo = -1;
    int hi = sum;


    for (int i = 0; i < A.size(); i++) {
        lo = max(lo, A[i]);
    }


    while (lo <= hi) {


        int mid = (lo + hi) / 2; //내가 찾는 최소 수

        int cnt = 0;
        int ex_sum = 0;

        for (int i = 0; i < A.size(); i++) {

            if (ex_sum + A[i] > mid) {
                ex_sum = A[i];
                cnt++;
            }
            else {
                ex_sum += A[i];
            }
        }

        if (cnt > K-1) {
            lo = mid + 1;
        }
        else {
            hi = mid - 1;
        }
    }
    return lo;
}


int main() {
    cout << solution(3 , 5, { 5,3 });
}
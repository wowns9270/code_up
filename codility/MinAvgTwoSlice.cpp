#include<bits/stdc++.h>
using namespace std;


int solution(vector<int> A) {
    // write your code in C++14 (g++ 6.2.0)

    double ret = (A[0] + A[1]) / 2.0;
    int idx = 0;

    for (int i = 2; i < A.size(); i++) {


        if ((A[i - 2] + A[i - 1] + A[i]) / 3.0 < ret) {

            ret = (A[i - 2] + A[i - 1] + A[i]) / 3.0;
            idx = i - 2;
        }

        if ((A[i - 1] + A[i]) / 2.0 < ret) {

            ret = (A[i - 1] + A[i]) / 2.0;
            idx = i - 1;
        }
    }

    return idx;

}

int main() {
    cout << solution({ 4,2,2,5,1,5,8 });
}
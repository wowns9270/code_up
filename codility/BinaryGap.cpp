#include<bits/stdc++.h>
using namespace std;



int solution(int N) {
    // write your code in C++14 (g++ 6.2.0)

    int k = 1;
    int cnt = 0;
    int max_cnt = 0;
    bool check = false;
    while (k <= N && k > 0) {

        if (k & N) {
            max_cnt = max(max_cnt, cnt);
            cnt = 0;
            check = true;
        }
        else if( check == true && (k & N) == 0) {
            cnt++;
        }

        k <<= 1;
    }

    return max_cnt;
}

int main() {
    cout << solution(1376796946);
    return 0;
}
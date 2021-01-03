#include<bits/stdc++.h>
using namespace std;

int ret;

int solution(vector<int> stones, int k) {

    int lo = 1;
    int hi = 200000001;

    for (int i = 0;i < stones.size(); i++) {

        lo = min(lo, stones[i]);
        hi = max(hi, stones[i]);
    }

    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        int cnt = 0;
        bool check = false;
        for (int i = 0; i < stones.size(); i++) {

            if (stones[i] <= mid) {
                cnt++;

                if (cnt >= k) {
                    check = true;
                    break;
                }
            }
            else {
                cnt = 0;
            }
        }
        //통과할 수 있습니다.
        if (check == false) {
            lo = mid + 1;
        }
        else {  // 통과할 수 없습니다.
            hi = mid - 1;
        }
    }
    return lo;
}


//int main() {
//  cout << solution({ 2, 4, 5, 3, 2, 1, 4, 2, 5, 1 }, 3);
//   return 0;
//}
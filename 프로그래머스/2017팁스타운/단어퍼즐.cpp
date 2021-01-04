#include<bits/stdc++.h>
#define inf 99999999
using namespace std;
int dp[20001];
int solution(vector<string> strs, string t)
{
    for (int i = 0;i < t.size(); i++) dp[i] = inf;

    for (int i = 0; i < t.size(); i++) {

        char k = t[i];

        for (int j = 0; j < strs.size(); j++) {

            if (k == strs[j][strs[j].size() - 1]) {   // 끝 문자열이 같을 

                //strs에 맞게 t 부분을  골라준다.

                int i_idx = i - strs[j].size() + 1; // t의 시작 인덱스

                if (i_idx < 0) continue; // 앞쪽이라 뽑기 불가능

                string k2 = t.substr(i_idx, strs[j].size()); // i_i 부터 사이즈에 맞게

                if (k2 == strs[j]) { // 문자열이 같으면
                    dp[i] = min(dp[i], dp[i_idx - 1] + 1);
                }
            }
        }
    }
    return dp[t.size() - 1] == inf ? -1 : dp[t.size() - 1];
}
//
//int main() {
//    cout <<solution({ "ba", "na", "n", "a" }, "banana");
//}
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

            if (k == strs[j][strs[j].size() - 1]) {   // �� ���ڿ��� ���� 

                //strs�� �°� t �κ���  ����ش�.

                int i_idx = i - strs[j].size() + 1; // t�� ���� �ε���

                if (i_idx < 0) continue; // �����̶� �̱� �Ұ���

                string k2 = t.substr(i_idx, strs[j].size()); // i_i ���� ����� �°�

                if (k2 == strs[j]) { // ���ڿ��� ������
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
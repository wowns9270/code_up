#include<bits/stdc++.h>
#pragma warning(disable:4996)
using namespace std;

int arr[1001][1001];
int dp[1001][1001];


int main() {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%1d", &arr[i][j]);
        }
    }
    int ret = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (arr[i][j] == 0) {
                continue;
            }
            dp[i][j] = min({ dp[i - 1][j - 1], dp[i - 1][j],
                dp[i][j - 1] }) + 1;


            ret = max(ret, dp[i][j]);
        }
    }
    cout << ret * ret;
    return 0;
}
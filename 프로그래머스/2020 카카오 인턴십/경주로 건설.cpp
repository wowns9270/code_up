#include<bits/stdc++.h>
using namespace std;


int dx[] = { 0,0,1,-1 }; //동서남북
int dy[] = { 1,-1,0,0 };

struct pp {

    int x;
    int y;
    int dir;
    int cost;
};
int dp[26][26][5];
queue<pp> q;

int solution(vector<vector<int>> board) {
    int answer = 0;
    int n = board.size();
    memset(dp,0x3f, sizeof(dp));
    q.push({ 0,0,4,0}); //

    while (!q.empty()) {

        int x = q.front().x;
        int y = q.front().y;
        int dir = q.front().dir;  // 온방향
        int cost = q.front().cost;

        q.pop();

        for (int i = 0; i < 4; i++) {

            int ux = x + dx[i];
            int uy = y + dy[i];

            if (ux < 0 || uy < 0 || ux >= n || uy >= n) continue;

            if (board[ux][uy] == 1) continue;

            if (dir == i) {  // 그대로 전진
             
                if (dp[ux][uy][i] > cost + 100) {
                    dp[ux][uy][i] = cost + 100;
                    q.push({ ux,uy,i , cost+ 100 });
                }

            }
            else {  // 방향이 바뀜
                if (dp[ux][uy][i] > cost + 600) {
                    dp[ux][uy][i] = cost + 600;
                    q.push({ ux,uy,i ,cost + 600});
                }

            }
        }
    }

    return min(dp[n-1][n-1][0] , dp[n-1][n-1][2]) - 500;
}

int main() {
    cout << solution({ {0,0,1,0},{0,0,0,0},{0,1,0,1},{1,0,0,0 } });
}
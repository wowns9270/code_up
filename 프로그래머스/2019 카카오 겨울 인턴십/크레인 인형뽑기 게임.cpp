#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;

    stack<int> arr;

    for (int i = 0; i < moves.size(); i++) {

        int c = moves[i];

        for (int j = 0; j < board.size(); j++) {

            if (board[j][c - 1] == 0) continue;
            else {
                if (!arr.empty()) {
                    if (board[j][c - 1] == arr.top()) {
                        answer += 2;
                        arr.pop();
                        board[j][c - 1] = 0;
                        break;
                    }
                    else {
                        arr.push(board[j][c - 1]);
                        board[j][c - 1] = 0;
                        break;
                    }
                }
                else {
                    arr.push(board[j][c - 1]);
                    board[j][c - 1] = 0;
                    break;
                }
            }
        }
    }

    return answer;
}
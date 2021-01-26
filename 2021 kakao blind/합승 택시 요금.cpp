#include <string>
#include <vector>

using namespace std;

int arr[201][201];


int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) {
                arr[i][j] = 0;
                continue;
            }
            arr[i][j] = 1e7;
        }
    }

    for (int i = 0; i < fares.size(); i++) {
        int a = fares[i][0];
        int b = fares[i][1];
        int c = fares[i][2];

        arr[a][b] = c;
        arr[b][a] = c;
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {  
                if (i == j) continue;

                if (arr[i][j] > arr[i][k] + arr[k][j]) {
                    arr[i][j] = arr[i][k] + arr[k][j];
                }
            }
        }
    }

    int ret = arr[s][a] + arr[s][b];

    for (int i = 1; i <= n; i++) {

        if (i == s) continue;

        if (ret > arr[s][i] + arr[i][a] + arr[i][b]) {
            ret = arr[s][i] + arr[i][a] + arr[i][b];
        }
    }

    return ret;
}

int main() {
    solution(7, 3, 4, 1, { {5, 7, 9 }, { 4, 6, 4 }, { 3, 6, 1 }, { 3, 2, 3 }, { 2, 1, 6 }});
    return 0;
}
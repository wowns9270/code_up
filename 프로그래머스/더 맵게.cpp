#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;

    priority_queue<int> arr;

    for (int i = 0; i < scoville.size(); i++) {

        arr.push(-scoville[i]);
    }

    while (1) {
        int a = -arr.top();
        if (a >= K) break;
        if (-arr.top() < K && arr.size() == 1) {
            answer = -1;
            break;
        }
        arr.pop();
        int b = -arr.top();
        arr.pop();
        arr.push(-(a + 2 * b));
        answer++;
    }
    return answer;
}

int main() {
    solution({ 1,2,3,9,10,12 }, 7);
}
#include <string>
#include<iostream>
#include <vector>
#include<queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int timm = 0;
    int sum = 0;
    queue<int> q;
    for (int i = 0; i < bridge_length; i++) {
        q.push(0);
    }

    for (int i = 0; i < truck_weights.size(); i++) {
        while (1) {
            sum -= q.front();
            q.pop();

            if (sum + truck_weights[i] > weight) {
                q.push(0);
                timm++;
                continue;
            }
            else {
                q.push(truck_weights[i]);
                sum += truck_weights[i];
                timm++;
                break;
            }
        }
    }
 
    answer = timm + bridge_length;

    return answer;
}

int main() {
    cout << solution(2, 10, {7,4,5,6});
}
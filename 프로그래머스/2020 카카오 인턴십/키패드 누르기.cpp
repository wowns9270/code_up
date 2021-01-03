#include<bits/stdc++.h>
using namespace std;


vector<pair<int, int> > arr = {
    {3,1},
    {0,0},
    {0,1},
    {0,2},
    {1,0},
    {1,1},
    {1,2},
    {2,0},
    {2,1},
    {2,2}
};

string solution(vector<int> numbers, string hand) {
    string answer = "";

    pair<int, int > l = { 3,0 };
    pair<int, int > r = { 3,2 };

    for (int i = 0; i < numbers.size(); i++) {


        if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7) {
            answer += 'L';
            l = arr[numbers[i]];
        }
        else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9) {
            answer += 'R';
            r = arr[numbers[i]];
        }
        else {

            int ld = abs(l.first - arr[numbers[i]].first) + abs(l.second - arr[numbers[i]].second);
            int rd = abs(r.first - arr[numbers[i]].first) + abs(r.second - arr[numbers[i]].second);

            if (ld < rd) {
                answer += 'L';
                l = arr[numbers[i]];
            }
            else if (rd < ld) {
                answer += 'R';
                r = arr[numbers[i]];
            }
            else {
                if (hand == "right") {
                    answer += 'R';
                    r = arr[numbers[i]];
                }
                else {
                    answer += 'L';
                    l = arr[numbers[i]];
                }
            }
        }
    }
    return answer;
}

//
//int main() {
//    cout << solution({ 1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5 }, "right");
//    return 0;
//}
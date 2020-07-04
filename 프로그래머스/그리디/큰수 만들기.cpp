#include <string>
#include <vector>
#include<algorithm>
using namespace std;
string solution(string number, int k) {
    string answer = "";

    int len = number.size() - k;

    vector<int> ret;
    int qq = 0;

    for (int i = 0; i < len; i++) {
        int max_idx = -1;
        char k = 0;
        for (int j = qq; j <= number.size() - len + i ; j++) {

            if (k < number[j]) {
                k = number[j];
                max_idx = j;
            }
        }
        ret.push_back(max_idx);
        qq = max_idx + 1;
    }
    for (int i = 0; i < ret.size(); i++) {
        answer += number[ret[i]];
    }

    return answer;
}

int main() {
    solution("4177252841", 4);
}
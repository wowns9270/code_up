#include<bits/stdc++.h>
using namespace std;


pair<int, int> ret;
map<string, int> q;
int min_ret = 9999999;

vector<int> solution(vector<string> gems) {

    vector<string> arr = gems;

    sort(gems.begin(), gems.end());
    gems.erase(unique(gems.begin(), gems.end()), gems.end());

    int kinds = gems.size();



    int i = 0;
    int j = 0;

    q.insert(pair<string, int>(arr[i], 1));


    while (1) {
        if (j == arr.size()) break;


        if (kinds > q.size()) {

            if (q.find(arr[j + 1]) != q.end()) {
                q[arr[j + 1]]++;
            }
            else {
                q.insert(pair<string, int>(arr[j + 1], 1));
            }
            j++;
            continue;
        }
        else { //만족

            int k = j - i;

            if (min_ret > k) {
                min_ret = k;
                ret = { i,j };
            }

            //i를 땡길 수 있나요?
            if (q[arr[i]] == 1) {
                //땡기면 안될걸요/

                if (j != arr.size() - 1)
                    q[arr[j + 1]]++;
                j++;
            }
            else {
                // 떙겨도 되네
                q[arr[i]]--;
                i++;
            }
        }
    }
    return { ret.first + 1, ret.second + 1 };
}

//
//
//int main() {
//   vector<int> k = solution({ "ZZZ", "YYY", "NNNN", "YYY", "BBB" });
//   return 0;
//}
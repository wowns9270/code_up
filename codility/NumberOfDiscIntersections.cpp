#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<long long, long long> x, pair<long long, long long> y) {

    if (x.first < y.first) return true;
    return false;
    
}

int solution(vector<int> A) {

    vector<pair<long long, long long>> arr;

    for (int i = 0; i < A.size(); i++) {

        arr.push_back({ (long long)i - A[i] , (long long)i + A[i] });

    }
    sort(arr.begin(), arr.end() , cmp);

    int ret = 0;
    for (int i = 0; i < A.size(); i++) {

        int cnt = 0;
        for (int j = i + 1; j < A.size(); j++) {
            if (ret > 10000000) return -1;
            if (arr[i].second >= arr[j].first) {
                cnt++;
            }
            else {
                break;
            }
        }
        ret += cnt;
    }

    return ret;



}

int main() {
    cout << solution({ 1, 2147483647, 0 });
}
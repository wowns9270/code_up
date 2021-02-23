#include<bits/stdc++.h>
using namespace std;


int solution(vector<int> A, vector<int> B, vector<int> C) {
    
    int lo = 0;
    int hi = A.size();


    vector<pair<int, int> > ret;

    for (int i = 0; i < A.size(); i++) {
        ret.push_back({ A[i] , B[i] });
    }

    sort(ret.begin(), ret.end());


    while (lo <= hi) {

        int mid = (lo + hi) / 2;
       
        vector<int> root;
        for (int i = 0; i < mid; i++) {
            int k = C[i];
            root.push_back(k);
        }
        sort(root.begin(), root.end());

        int j = 0;
        for (int i = 0; i < root.size(); i++) {
            int k = root[i];

            if (j == A.size()) break;

            if (ret[j].first > k) continue;
            else if (ret[j].second < k) {
                break;
            }
           
            while (1) {

                if (j == A.size()) break;

                if (ret[j].first <= k && ret[j].second >= k) {
                    j++;
                }
                else break;
            }
            
        }
        

        if (j == A.size()) {
            hi = mid - 1;
        }
        else {
            lo = mid + 1;
        }
    }

    if (lo > A.size()) return -1;

    return lo;
}

int main() {

    cout << solution({ 1,4,5,8}, { 4,5,9,10 }, { 4,6,7,10,2 });


}

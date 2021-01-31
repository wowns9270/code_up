#include<bits/stdc++.h>
using namespace std;

struct pp {
    vector<int > arr;
};

pp ret[100001];


vector<int> solution(string S, vector<int>P, vector<int> Q) {
    
    for (int i = 0; i <= S.size(); i++) {
        
        if (i == 0) {
            ret[i].arr = { 0,0,0,0,0 };
            continue;
        }

        int r = 0;

        if (S[i-1] == 'A')r = 1;
        else if (S[i-1] == 'C')r = 2;
        else if (S[i-1] == 'G')r = 3;
        else if (S[i-1] == 'T')r = 4; 
        
        
        ret[i].arr = ret[i-1].arr;
        ret[i].arr[r]++;
        
    }
    vector<int> ans;
    for (int i = 0; i < Q.size(); i++) {

        int hi = Q[i]+1;
        int lo = P[i];

        for (int j= 1; j <= 4; j++) {

           int rr = ret[hi].arr[j] - ret[lo].arr[j];

            if (rr > 0) {
                ans.push_back(j);
                break;
            }
        }
    }
    return ans;
}

int main() {
    vector<int> k = solution("CAGCCTA", { 2,5,0 }, { 4,5,6 });
}
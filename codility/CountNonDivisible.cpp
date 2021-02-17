#include<bits/stdc++.h>
using namespace std;


int arr[50001];
int cnt[50001];

vector<int> solution(vector<int> A) {
   
    vector<int> b = A;

    for (int i = 0; i < A.size(); i++) {

        cnt[A[i]]++;
    }

    vector<int> ret;
    for (int i = 0; i < A.size(); i++) {


        int cur = 0;
        for (int j = 1; j* j < A[i]; j++) {

            if (j * j == A[i]) {
                cur += cnt[j];
            }
            else if (A[i] % j == 0) {
                cur += cnt[j];
                cur += cnt[A[i] / j];
            }
        }

        ret.push_back(A.size() - cur);
    }


    
    return ret;

}

int main() {
    solution({ 3,1,2,3,6 });
    return 0;
}

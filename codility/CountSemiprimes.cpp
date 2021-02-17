#include<bits/stdc++.h>
using namespace std;;

int prime[50001];
int semiprime[50001];


bool checking(int idx) {

    bool cc = true;

    for (int i = 2; i * i <= idx; i++) {

        if (i * i == idx) {
            if (prime[i] == 1) {
                cc = false;
                break;
            }
        }
        else if (idx % i == 0) {

            if (prime[i] == 1 || prime[idx / i] == 1) {
                cc = false;
                break;
            }

        }
     }

    return cc;


}


vector<int> solution(int N, vector<int> P, vector<int> Q) {
    
    for (int i = 2; i <= sqrt(N); i++) {

        for (int j = i * i; j <= N; j += i) {

            prime[j] = 1;
        }
    }

    // 0 은 소수 1 은 합성수

    int cnt = 0;

    for (int i = 4; i <= N; i++) {

        if (prime[i] == 0) {
            semiprime[i] = cnt;
            continue;
        }

        bool check = checking(i);


        if (check) { //semi
            semiprime[i] = ++cnt;
        }
        else {
            semiprime[i] = cnt;
        }
    }
    vector<int> ret;

    for (int i = 0; i < Q.size(); i++) {

        int k1 = P[i] - 1;
        int k2 = Q[i];

        ret.push_back(semiprime[k2] - semiprime[k1]);


    }
       
    return ret;
}

int main() {
    solution(26, { 1,4,16 }, { 26,10,20 });
}
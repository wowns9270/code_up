#include<bits/stdc++.h>

using namespace std;

string ret = "";

string gogo(int jinsu, int num) {

    string k = "";

    while (num) {

        int k_m = num / jinsu;

        int k_r = num % jinsu;

        if (k_r >= 10) {
            k += 'A' + k_r - 10;
        }
        else {
            k += '0' + k_r;
        }
        num = num / jinsu;
    }

    reverse(k.begin(), k.end());

    return k;
}

string solution(int n, int t, int m, int p) {
    string answer = "0";


    for (int i = 1; ; i++) {
        string ret = gogo(n, i);
        answer += ret;

        if (answer.size() > 100001) {
            break;
        }
    }
    string answer2 = "";
    while (t--) {
        answer2 += answer[p - 1];
        p += m;
    }


    return answer2;
}
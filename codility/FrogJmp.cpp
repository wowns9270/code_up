#include<bits/stdc++.h>
using namespace std;

int solution(int X, int Y, int D) {
    
    int k = Y - X;

    int ret = 0;

    if (k % D == 0) {
        ret = k / D;
    }
    else {
        ret = k / D + 1;
    }
    return ret;
}

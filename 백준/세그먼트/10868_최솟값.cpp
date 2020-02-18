//쿼리 문제 즉  구간에 대한 쿼리를 구하는 문젠데
//100000개의 정수 m이 100000 개라면
//최소를 찾는다.
#include<bits/stdc++.h>
#define inf 987987654321
using namespace std;

long long arr[100001];
long long sege[300001];
int n, m;

long long init(int idx, int st, int ed) {

    if (st == ed) {
        return  sege[idx] = arr[st];
    }
    long long mid = (st + ed) / 2;

    long long a = init(idx * 2, st, mid);
    long long b = init(idx * 2 + 1, mid + 1, ed);

    return sege[idx] = min(a, b);
}

long long gogo(int lo, int hi, int idx, int x, int y) {

    if (hi < x || lo > y) return inf; //범위를 벗어난다.

    if (x <= lo && y >= hi) return sege[idx];

    long long mid = (lo + hi) / 2;

    long long a = gogo(lo, mid, idx * 2, x, y);
    long long b = gogo(mid + 1, hi, idx * 2 + 1, x, y);

    return min(a, b);
}


int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;


    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    init(1, 0, n - 1);
    while (m--) {
        int a, b; cin >> a >> b;
        a -= 1, b -= 1;
        cout << gogo(0, n - 1, 1, a, b) << "\n";
    }
    return 0;
}
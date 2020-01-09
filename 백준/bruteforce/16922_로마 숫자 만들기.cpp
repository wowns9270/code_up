#include<bits/stdc++.h>
using namespace std;
int arr[] = { 1,5,10,50 };
int n, ret;
bool visit[1001];

//중복을 피하면서 찾는 조합
void bruteforce(int cnt, int idx, int sum) {

	if (cnt == n) {
		if (visit[sum] == false) {
			visit[sum] = true;
			ret++;
		}
		return;
	}

	for (int i = idx; i < 4; i++) {
		bruteforce(cnt + 1, i, sum + arr[i]);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;

	bruteforce(0, 0, 0);
	cout << ret;
	return 0;
}
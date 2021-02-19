#include<bits/stdc++.h>
#define INF 10000000
using namespace std;


int dp[100000];
int cnt[100000];

int solution(vector<int>& A) {
	
	A.push_back(1);
	dp[0] = 0;
	dp[1] = 1;

	for (int i = 2; ; i++) {

		dp[i] = dp[i - 1] + dp[i - 2];
		if (dp[i] > 100000) break;
	}

	queue<pair<int, int>> q;

	q.push({ -1, 0 });

	while (!q.empty()) {

		int a = q.front().first;
		int b = q.front().second;

		q.pop();

		for (int i = 2; ; i++) {

			if (a + dp[i] > A.size()-1 ) {
				break;
			}

			if (A[a + dp[i]] == 1) {
				if (cnt[a + dp[i]] == 0) {
					cnt[a + dp[i]] = b + 1;
					q.push({ a + dp[i] , b + 1 });
				}
			}
		}
	}

	//cout << cnt[A.size() - 1];


	return cnt[A.size() - 1] == 0 ? -1 : cnt[A.size() - 1];
	
}


int main() {
	cout << solution({0,0,0,1,1,0,1,0,0,0,0});
}
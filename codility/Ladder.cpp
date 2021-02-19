#include<bits/stdc++.h>
#define INF 10000000
using namespace std;


long long dp[50006];


vector<int> solution(vector<int> A, vector<int> B) {

	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i <= 50004; i++) {
		dp[i] = dp[i - 1] + dp[i - 2] % (1 << 30);
	}


	vector<int> ret;

	for (int i = 0; i < A.size(); i++) {
		ret.push_back(dp[A[i]] % (1 << B[i]));
	}
	return ret;

}

int main() {
	solution({ 4,4,5,5,1 }, {3,2,4,3,1});%
}
#include<bits/stdc++.h>
using namespace std;

int min_pre[400001];

int min_ret = 300000;

int solution(vector<int> A) {

	for (int i = 0; i < A.size(); i++) {
		if (min_ret > A[i]) {

			min_pre[i] = A[i];
			min_ret = A[i];
		}
		else {
			min_pre[i] = min_ret;
		}
	}
	int ret = 0;
	for (int i = A.size() - 1; i >= 1; i--) {

		int k = A[i] - min_pre[i - 1];

		ret = max(k, ret);
	}
	return ret;
}

int main() {
	cout << solution({ 23171,21011,21123,21366,21013,21367 });
	return 0;
}
#include<bits/stdc++.h>
using namespace std;

int max_arr[1000001];

int solution(vector<int>& A) {

	max_arr[0] = A[0];

	for (int i = 1; i < A.size(); i++) {

		max_arr[i] = max(max_arr[i - 1] + A[i], A[i]);

	}

	int ret = -999999999;
	for (int i = 0; i < A.size(); i++) {

		ret = max(ret, max_arr[i]);
	}

	return ret;
}



int main() {
	cout << solution({ 3,2,-6,4,0 });
}
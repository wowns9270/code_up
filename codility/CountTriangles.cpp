#include<bits/stdc++.h>
using namespace std;




int solution(vector<int> A) {

	if (A.size() < 3) return 0;

	sort(A.begin(), A.end());

	int cnt = 0;
	for (int i = 0; i < A.size()-2 ; i++) {

		for (int j = i+1; j < A.size()-1 ; j++) {

			int k = A[i] + A[j];

			int idx = lower_bound(A.begin(), A.end(), k) - A.begin();

			cnt += idx - j-1;
		}
	}

	return cnt;
}

int main() {
	cout << solution({ 10,2,5,1,8,12 });
}

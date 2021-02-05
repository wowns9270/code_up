#include<bits/stdc++.h>
using namespace std;

int solution(vector<int> A) {

	sort(A.begin(), A.end());

	if (A.size() < 3) return 0;

	for (int i = 0; i < A.size()-2; i++) {

		if ((long long)A[i] + A[i + 1] > (long long)A[i + 2]) {
			return 1;
		}
	}
	return 0;

}


int main() {
	cout << solution({ 10, 2,5,1,8,20 });
}
#include<bits/stdc++.h>
using namespace std;


int check[1000005];

int solution(vector<int> A) {
	for (int i = 0; i < A.size(); i++) {

		if (A[i] <= 0) {
			continue;
		}
		else {
			check[A[i]] = 1;
		}
	}

	for (int i = 1; i < 100002; i++) {

		if (check[i] == 0) {
			return i;
		}

	}
}

int main() {
	cout << solution({ -1000000, 1000000 });
}
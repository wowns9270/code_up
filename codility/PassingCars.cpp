#include<bits/stdc++.h>
using namespace std;

int solution(vector<int> A) {

	vector<int> a;
	vector<int>b;

	for (int i = 0; i < A.size(); i++) {

		if (A[i] == 0) {
			a.push_back(i);
		}
		else {
			b.push_back(i);
		}
	}
	long long sum = 0;

	for (int i = 0; i < a.size(); i++) {

		int k = a[i];

		int r = upper_bound(b.begin(), b.end(), k) - b.begin();


		sum += b.size() - r;

	}

	if (1000000000 < sum) {
		return -1;
	}
	else {
		return (int)sum;
	}
}

int main() {
	cout << solution({ 0,1,0,1,1 });
}

#include<bits/stdc++.h>
using namespace std;
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int ret = 1e7;

int solution(vector<int> A) {

	int sum = 0;

	for (int i = 0; i < A.size(); i++) {
		sum += A[i];
	}

	int part_a = 0;

	for (int i = 0; i < A.size()-1; i++) {

		part_a += A[i];

		int part_b = sum - part_a;

		ret = min(ret, abs(part_b - part_a));
	}
	return ret;
}

int main() {
	cout << solution({ 3,-3 });
}
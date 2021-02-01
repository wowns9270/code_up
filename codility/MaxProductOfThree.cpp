#include<bits/stdc++.h>
using namespace std;


int solution(vector<int> A) {


	if (A.size() < 6) {
		int ret = -1000000004;
		for (int i = 0; i < A.size()-2; i++) {
			for (int j = i+1; j < A.size() - 1; j++) {
				for (int k = j+1; k < A.size(); k++) {
					ret = max(ret, A[i] * A[j] * A[k]);
				}
			}
		}
		return ret;
	}
	else {
		sort(A.begin(), A.end());

		vector<int> b;
		b.push_back(A[0]);
		b.push_back(A[1]);
		b.push_back(A[2]);
		b.push_back(A[A.size()-1]);
		b.push_back(A[A.size() - 2]);
		b.push_back(A[A.size() - 3]);

		int ret = -1000000004;
		for (int i = 0; i < b.size() - 2; i++) {
			for (int j = i+1; j < b.size() - 1; j++) {
				for (int k = j+1; k <b.size(); k++) {
					ret = max(ret, b[i] * b[j] * b[k]);
				}
			}
		}
		return ret;
	}
}

int main() {
	cout << solution({ 4,5,1,0 });
}

#include<bits/stdc++.h>
using namespace std;


int solution(vector<int> A) {

	vector<int> idx;
	if (A.size() < 3) return 0;

	for (int i = 1; i < A.size() - 1; i++) {
		if (A[i - 1] <A[i] && A[i] > A[i + 1]) {
			idx.push_back(i);
		}
	}

	if (idx.size() < 1) return 0;


	int ret = 1;



	for (int i = 1; i<=A.size(); i++) {
		if (A.size() % i == 0) {
			int k = A.size() / i;

			int cnt = 0; 
			for (int j = 0; j < idx.size(); j++) {
				int start = cnt * k;
				int end = (cnt + 1) * k;
				if (idx[j] >= start && idx[j] < end) {
					cnt++;
				}
			}

			if (cnt == i) {
				ret = max(ret, i);
			}
		}
	}
	return ret;
}


int main() {
	cout << solution({1,5,3,6,1});
}
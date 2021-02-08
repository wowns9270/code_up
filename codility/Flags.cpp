#include<bits/stdc++.h>
using namespace std;

int solution(vector<int> A) {

	vector<int> idx;

	for (int i = 1; i < A.size()-1; i++) {
		if (A[i - 1] < A[i] && A[i] > A[i + 1]) {
			idx.push_back(i);
		}
	}

	if (idx.size() < 1) return 0;

	int ret = 1;
	for (int i = 2; ; i++) {

		bool check = false;

		int pre_d = idx[0];
		int cur_cnt = 1;
		for (int j = 1; j < idx.size(); j++) {
			if (abs(pre_d - idx[j]) >= i) {
				cur_cnt++;
				pre_d = idx[j];
			}

			if (cur_cnt == i) {
				check = true;
				ret = i;
				break;
			}
		}
		
		if (check == false) {
			return ret;
		};
	}
}

int main() {
	cout << solution({ 2 , 3 , 1 });
}
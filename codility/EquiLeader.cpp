#include<bits/stdc++.h>
using namespace std;


int solution(vector<int> A) {
   
	map<int, int> arr;

	for (int i = 0; i < A.size(); i++) {

		int k = A[i];
		if (arr.find(k) == arr.end()) {
			arr[k] = 1;
		}
		else {
			arr[k]++;
		}
	}

	int r = 0;
	int ret = 0;

	for (auto it = arr.begin(); it != arr.end(); it++) {
		if (r < it->second) {
			r = it->second;
			ret = it->first;
		}
	}

	int cnt = 0;
	int ans = 0;
	for (int i = 0; i < A.size()-1; i++) {

		if (A[i] == ret) {
			cnt++;
		}

		int half_1 = (i + 1) / 2;
		int half_2 = (A.size() - i - 1)/2;

		if (half_1 < cnt && half_2 < r - cnt) ans++;
	}

	return ans;
}


int main() {
	cout << solution({ 4,3,4,4,4,2 });
	return 0;
}
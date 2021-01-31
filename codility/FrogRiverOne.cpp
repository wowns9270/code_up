#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> x, pair<int, int> y) {

	if (x.first < y.first) {
		return true;
	}
	else if (x.first == y.first) {

		if (x.second < y.second) {
			return true;
		}
	}
	return false;
}


int solution(int X, vector<int> A) {

	vector<pair<int, int>> arr;

	for (int i = 0; i < A.size(); i++) {

		arr.push_back({ A[i], i });
	}

	sort(arr.begin(), arr.end(), cmp);


	int cnt = 0; 
	int seconds = -1;

	for (int i = 0; i < arr.size(); i++) {

		int k = arr[i].first; 
		int k2 = arr[i].second; 

		if (cnt == k) {
			continue;
		}
		else if (cnt + 1 == k) {
			seconds = max(seconds, k2);
			cnt++;
		}
		else {
			seconds = -1;
			break;
		}

		if (cnt == X) break;
	}

	if (cnt != X) seconds = -1;


	return seconds;
}

int main() {
	cout << solution(2, { 1,1,1,1 });
}
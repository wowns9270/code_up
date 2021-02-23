#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> x, pair<int, int > y) {

	if (x.second < y.second) return true;

	return false;


}

int solution(vector<int> A, vector<int> B) {
	
	vector<pair<int, int>>ret;
	for (int i = 0; i < A.size(); i++) {

		ret.push_back({ A[i] , B[i] });
	}

	sort(ret.begin(), ret.end(), cmp);


	int lo = -1;
	int cnt = 0;

	for (int i = 0; i < ret.size(); i++) {

		if (ret[i].first > lo) {
			cnt++;

			lo = ret[i].second;
		}
	}

	return cnt;
}

int main(){
	cout << solution({ 1,3,7,9,9 }, { 5,6,8,9,10 });
	return 0;
}
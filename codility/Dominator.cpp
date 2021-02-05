#include<bits/stdc++.h>
using namespace std;

map<int, int> llist;

int solution(vector<int> A) {

	for (int i = 0; i < A.size(); i++) {

		int k = A[i];

		if (llist.find(k) == llist.end()) {

			llist.insert(pair<int, int>(k, 1));
		}
		else {
			llist[k]++;
		}
	}

	map<int, int> ::iterator it;
	int max_cnt = 0;
	int rr = 0;

	for (it = llist.begin(); it != llist.end(); ++it){

		if (max_cnt < it->second) {
			max_cnt = it->second;
			rr = it->first;
		}
	}

	if ( max_cnt > A.size() / 2) {


		for (int i = 0; i < A.size(); i++) {
			if (rr == A[i]) return i;
		}
	}
	else return -1;
	
}

int main() {

	cout << solution({ 3,4,3,2,3,-1,3,3 });
	return 0;
}
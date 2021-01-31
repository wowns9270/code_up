#include<bits/stdc++.h>
using namespace std;


int check[100001];

int solution(vector<int>& A) {


	for (int i = 0; i < A.size(); i++) {

		if (A.size() < A[i]) continue;
		else {
			check[A[i]] = 1;
		}
	}

	int ret = 1;
	for (int i = 1; i <= A.size(); i++) {

		if (check[i] == 0) {
			ret = 0;
		}

	}

	return ret;


}

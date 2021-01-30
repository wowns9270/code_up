#include<bits/stdc++.h>
using namespace std;

bool check[100001];

int solution(vector<int>& A) {

	int ret = -1;

	for (int i = 0; i < A.size(); i++) {
		check[A[i]] = true;
	}

	for (int i = 1; i <= A.size() + 1; i++) {

		if (check[i] == false) {
			ret = i;
			break;
		}

	}

	return ret;

}

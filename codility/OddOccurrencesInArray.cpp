#include<bits/stdc++.h>
using namespace std;


int solution(vector<int>& A) {
		
	int k = 0;

	for (int i = 0; i < A.size(); i++) {

		k ^= A[i];
	}

	return k;

}



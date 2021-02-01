#include<bits/stdc++.h>
using namespace std;

int check[2000003];

int solution(vector<int>& A) {
   

	for (int i = 0; i < A.size(); i++) {

		int a = A[i];

		if (check[1000000 + a] == 0) {
			check[1000000 + a] = 1;
		}
	}

	int cnt = 0;
	for (int i = 0; i <= 2000000; i++) {

		if (check[i] == 1) cnt++;

	}
	return cnt;

}

#include<bits/stdc++.h>
using namespace std;

int solution(int A, int B, int K) {
   
	int k = B / K + 1;

	int k2 = 0;
	if (A  > 0 ) {
		k2 = (A - 1) / K + 1;
	}

	return k - k2;
}

int main() {
	cout << solution(0, 0,22);
}
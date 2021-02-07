#include<bits/stdc++.h>
using namespace std;

int max_arr[1000001];

int solution(int N) {

	vector<int>list;
	
	if (N == 1) return 1;

	
	for (int i = 1; i <= sqrt(N); i++) {

		if (i == sqrt(N)) {
			list.push_back(i);
			continue;
		}
		else if (N % i == 0) {
			list.push_back(i);
			list.push_back(N / i);
		}


	}

	return list.size();
}



int main() {
	cout << solution(4);
}
#include<bits/stdc++.h>
using namespace std;

int solution(int N) {
	int ret = 1e10 + 100;
	for (int i = 1; i <= sqrt(N); i++) {
		if (N % i == 0) {
			ret = min(ret, 2 * (i + N / i));
		}
	}


	return ret;

}

int main() {
	cout << solution(30);
}
#include<bits/stdc++.h>
using namespace std;

int gcd(int x, int y) {

	if (y == 0) return x;

	return gcd(y, x % y);
}

int solution(int N, int M) {

	int r = gcd(N, M);

	return N / r ;



}

int main() {
	cout<< solution(10 , 4);
}
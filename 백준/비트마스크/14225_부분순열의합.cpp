#include<iostream>
using namespace std;

bool check[20 * 100000 + 10];

int arr[24];

int main() {
	int n; cin >> n;

	//입력
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	//n이 3이면 1<<3 하면 8 그러면
	//000 001 010 011  100 101 110 111 이렇게 8가지 경우가 생기고
	//1로 각 자리를 확인

	for (int i = 0; i < (1 << n); i++) {
		int sum = 0;
		//1로 각자리 확인해서 더해준다.
		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) {
				sum += arr[j];
			}
		}
		check[sum] = true;
	}


	for (int i = 1; ; i++) {
		if (check[i] == false) {
			cout << i;
			break;
		}
	}
	return 0;
}
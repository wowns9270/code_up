#include<iostream>
using namespace std;

bool check[20 * 100000 + 10];

int arr[24];

int main() {
	int n; cin >> n;

	//�Է�
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	//n�� 3�̸� 1<<3 �ϸ� 8 �׷���
	//000 001 010 011  100 101 110 111 �̷��� 8���� ��찡 �����
	//1�� �� �ڸ��� Ȯ��

	for (int i = 0; i < (1 << n); i++) {
		int sum = 0;
		//1�� ���ڸ� Ȯ���ؼ� �����ش�.
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
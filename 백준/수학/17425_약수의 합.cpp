#include<bits/stdc++.h>
using namespace std;

long long arr[1000000]; //����� ��
long long sum[1000000]; // 1���� �� ������ ����� ���� ��


//���μ������ض� ����?


int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	
	for (int i = 1; i <= 1000000; i++) {
		arr[i] = 1;
	}

	for (int i= 2; i <= 1000000; i++) {

		for (int j = 1; i * j <= 1000000; j++) {
			arr[i * j] += i;
		}
	}

	sum[0] = 0;
	for (int i = 1; i <= 1000000; i++) {
		sum[i] = sum[i - 1] + arr[i];
	}



	int test; cin >> test;
	while (test--) {
		int a; cin >> a;
		cout << sum[a] <<"\n";
	}
	return 0;
}
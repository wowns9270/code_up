#include<bits/stdc++.h>
using namespace std;
int arr[16];
//���� �ݾ��� �ִ�� �ҷ��� ���Ⱑ ���ϴ°����� ��ų� �ȸ�ȴ�.
//������ ��θ� �Ȱ�
//�θ� ������ �� ��°��� �ݺ��Ѵ�
//state �� �߿� ����ϴ��� �ϰ��ϴ���
int main() {
	long long n, money; cin >> n >> money;

	long long coin = 0;
	long long state = 0;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	if (arr[0] < arr[1]) {
		coin += money / arr[0];
		money = money % arr[0];
		state = 1;
	}
	for (int i = 0; i < n; i++) {

		if (state == 1) {
			if (arr[i] <= arr[i + 1]) continue;
			else {
				state = 0;
				money += arr[i] * coin;
				coin = 0;
			}
		}
		else {
			if (arr[i] >= arr[i + 1]) continue;
			else {
				state = 1;
				coin += money / arr[i];
				money = money % arr[i];
			}
		}
	}
	cout << money;
	return 0;
}
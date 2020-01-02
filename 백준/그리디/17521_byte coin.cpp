#include<bits/stdc++.h>
using namespace std;
int arr[16];
//보유 금액을 최대로 할려면 기울기가 변하는곳에서 사거나 팔면된다.
//가격이 비싸면 팔고
//싸면 코인을 다 사는것을 반복한다
//state 가 중요 상승하는지 하강하는지
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
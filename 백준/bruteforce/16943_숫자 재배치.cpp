#include<bits/stdc++.h>
using namespace std;
string a;
int b,ret;
vector<int> arr;
void  check() {
	int sum = arr[0];
	for (int i = 1; i < arr.size(); i++) {
		sum *= 10;
		sum += arr[i];
	}
	if (sum <= b) {
		ret = max(ret, sum);
	}
	return;
}
//���� ���ġ ����
//10^9 �̸� �ִ�9!���� ��찡 ������ �׶� �����ϴ� ������ �ִ븦 ã��
//�����̴� �̷� ������ next_permutation �̳� pre_permutation���� �ذ��Ѥ�,
int main() {
	cin >> a >> b;
	for (int i = 0; i < a.size(); i++) {
		arr.push_back(a[i] - '0');
	}
	sort(arr.begin(), arr.end());
	do {
		if (arr[0] == 0) continue;
		check();
	} while (next_permutation(arr.begin(), arr.end()));
	if (ret == 0)cout << "-1";
	else cout << ret;
	return 0;
}
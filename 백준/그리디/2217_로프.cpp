#include<bits/stdc++.h>
using namespace std;

vector<int> arr;
int ret;
//�ּ� ���̺��� Ȯ���Ͽ� ���� �ִ밪�� ã�� ����
int main() {
	int n; cin >> n;

	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		arr.push_back(a);
	}
	sort(arr.begin(), arr.end());

	for (int i = 0; i < n; i++) {
		int sum = arr[i] * (n - i);
		ret = max(ret, sum);
	}
	cout << ret;
	return 0;

}
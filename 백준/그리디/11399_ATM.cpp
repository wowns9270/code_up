#include<bits/stdc++.h>
using namespace std;

int main() {
	//��ٸ��»�� �� �ð��� �����Ϸ���
	//�տ��� ���� ���� ������ �ִ� ����� ���� 
	//������ �۾����� �׸���
	vector<int> arr;
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		arr.push_back(a);
	}
	sort(arr.begin(), arr.end());

	int sum = 0;
	int ret = 0;
	for (int i = 0; i < n; i++) {
		ret += arr[i];
		sum += ret;
	}
	cout << sum;
	return 0;
}
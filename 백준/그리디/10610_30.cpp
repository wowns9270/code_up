#include<bits/stdc++.h>
using namespace std;

vector<int> arr;

bool cmp(int x, int y) {
	if (x > y) return true;
	return false;
}
int check;

//30�� ����Ϸ��� 1�� �ڸ��� 0���� ������
//�� �ڸ� ���� 3�� ����� �Ǿ��Ѵ�
int main() {
	string n; cin >> n;

	for (int i = 0; i < n.size(); i++) {
		char c = n[i];
		int  k = c - 48;
		check += k;
		arr.push_back(k);
	}
	sort(arr.begin(), arr.end(), cmp);

	if (check % 3 == 0 && arr[arr.size() - 1] == 0) {
		for (int i = 0; i < arr.size(); i++) {
			cout << arr[i];
		}
	}
	else cout << "-1";
	return 0;
}
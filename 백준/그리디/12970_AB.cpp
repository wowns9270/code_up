#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, k; cin >> n >> k;

	string temp = "";
	for (int i = 0; i <= n; i++) {
		int b = n - i; // b�� ����
		int a = n - b; //a�� ����

		if (a * b < k) continue; //�� ������ ������ ���� �� ����.
		else {
			int k_max = a * b;

			for (int j = 1; j <= a; j++) {
				temp += "A";
			}
			for (int j = 1; j <= b; j++) {
				temp += "B";
			}
			for (int j = 0; j < k_max - k; j++) {
				next_permutation(temp.begin(), temp.end());
			}
			break;
		}
	}
	if (temp == "")cout << "-1";
	else cout << temp;
	return 0;
}
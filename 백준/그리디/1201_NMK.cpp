#include<bits/stdc++.h>
using namespace std;

vector<int> arr;
vector<int> line;


// �̰���¥ �ù� �ƴ°� ���̴�. ���� �𸥴�
// �׷����� ������ �׷��� ũ�Ⱑ �ִ� ���Ҽ����̰�
// �׷��� ������ �ִ� �������� �����̴�...
int main() {
	int n, m, k;
	cin >> n >> m >> k;
	   
	if (m + k - 1 <= n && n <= m * k) {
		for (int i = 1; i <= n; i++) {
			arr.push_back(i);
		}
		line.push_back(0); //ó�����
		line.push_back(k); // ù k�� �ִ� ���Ҽ��� ����
		n -= k; //��ü �������� n�� ������
		m -= 1; // �׷� ���� �ϳ� ����

		int gs = m == 0 ? 1 : n / m;
		int r = m == 0 ? 0 : n % m;
		for (int i = 0; i < m; i++) {
			line.push_back(line.back() + gs + (r > 0 ? 1 : 0));
			if (r > 0) {
				r -= 1;
			}
		}

		for (int i = 0; i < line.size()-1; i++) {
			reverse(arr.begin() + line[i], arr.begin() + line[i + 1]);
		}

		for (int i = 0; i < arr.size(); i++) {
			cout << arr[i] <<" ";
		}
	}
	else {
		cout << -1;
	}
	return 0;
}
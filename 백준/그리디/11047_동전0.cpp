#include<bits/stdc++.h>
using namespace std;

int main() {
	//�׸��� ���� ���� ���� ���� �����ּҰ���
	//ū ������ ������ �����ϸ�ȴ�
	//�̰� �������� ����
	int n, m; cin >> n >> m;

	priority_queue<int>pq;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		pq.push(a);
	}
	int sum = 0;
	while (!pq.empty()) {
		int x = pq.top();
		sum += m / x;

		m = m % x;

		if (m == 0) break;
		pq.pop();
	}
	cout << sum;
	return 0;
}
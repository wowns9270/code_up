#include<bits/stdc++.h>
using namespace std;

int main() {
	//그리디 시작 가장 적은 동전 개수최소값은
	//큰 값으로 나누기 시작하면된다
	//이건 직관적인 느낌
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
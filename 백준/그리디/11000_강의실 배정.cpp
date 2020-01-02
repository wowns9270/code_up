#include<bits/stdc++.h>
using namespace std;
int n;
vector<pair<int, int>> arr;

int main() {
	//�켱���� ť�� ���� �ؾ� �ϴ� �����̴�.
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		arr.push_back(make_pair(a, b));
	}
	//���������� ������ �Ѵ�
	sort(arr.begin(), arr.end());
	priority_queue<int> pq;
	for (int i = 0; i < arr.size(); i++) {
		//����ð��� �켱���� ť�� �����Ѵ�.
		//�켱���� ť�� ž�� ���� ���� ������ �ð��� ���� ������
		if (pq.empty()) pq.push(-arr[i].second);
		else {
			//ž���� �ʰ� �����ϸ� ���ְ� �־��ָ�ȴ�.
			if (-pq.top() > arr[i].first) {
				pq.push(-arr[i].second);
			}
			else {
				pq.pop();
				pq.push(-arr[i].second);
			}
		}
	}
	cout << pq.size();
	return 0;
}
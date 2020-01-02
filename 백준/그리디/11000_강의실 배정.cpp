#include<bits/stdc++.h>
using namespace std;
int n;
vector<pair<int, int>> arr;

int main() {
	//우선순위 큐를 생각 해야 하는 문제이다.
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		arr.push_back(make_pair(a, b));
	}
	//시작점으로 정렬을 한다
	sort(arr.begin(), arr.end());
	priority_queue<int> pq;
	for (int i = 0; i < arr.size(); i++) {
		//종료시간을 우선순위 큐에 저장한다.
		//우선순위 큐는 탑에 가장 빨리 끝나는 시간이 오기 때문에
		if (pq.empty()) pq.push(-arr[i].second);
		else {
			//탑보다 늦게 시작하면 빼주고 넣어주면된다.
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
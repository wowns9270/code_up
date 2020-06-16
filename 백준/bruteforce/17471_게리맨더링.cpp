#include<bits/stdc++.h>
#define inf 999999999
using namespace std;


int n;
int arr[11], ret = inf;
bool visit[11];
vector<vector<int>> llist;
vector<int> type;

bool check() {

	vector<int> v1;
	vector<int> v2;

	for (int i = 1; i <= n; i++) {
		if (type[i] == 1) {
			v1.push_back(i);
		}
		else if (type[i] == 2) {
			v2.push_back(i);
		}
	}

	memset(visit, false, sizeof(visit));

	int first = v1[0]; // 첫마을
	visit[first] = true;

	queue<int> q;
	q.push(first);

	while (!q.empty()) {
		int x = q.front(); // 마을
		q.pop();

		for (int i = 0; i < llist[x].size(); i++) { //그마을과 연결된 마을
			int ux = llist[x][i]; // 그 마을의 타입을 알아야한다

			if (visit[ux] == true) continue;

			if (type[ux] != type[x]) continue; // 다른 선거구역
			else {
				visit[ux] = true;
				q.push(ux);
			}
		}
	}
	int second = v2[0];
	visit[second] = true;
	q.push(second); // 두번째 선거구역

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int i = 0; i < llist[x].size(); i++) {
			int ux = llist[x][i];

			if (visit[ux] == true) continue;
			if (type[ux] != type[x]) continue;
			else {
				visit[ux] = true;
				q.push(ux);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (visit[i] == false) {
			return false;
		}
	}
	return true;
}


void gogo(int idx, int x1, int x2) {

	if (idx == n + 1) { //n개의 구역을 선택했다.
		if (x1 == 0 || x2 == 0) return;

		if (check() == true) {//구역이 서로 연결되어있는지

			int t1 = 0, t2 = 0;
			for (int i = 1; i <= n; i++) {
				if (type[i] == 1) {
					t1 += arr[i];
				}
				else if (type[i] == 2) {
					t2 += arr[i];
				}
			}
			ret = min(ret, abs(t1 - t2));
			return;
		}
		else return;
	}

	type[idx] = 1;
	gogo(idx + 1, x1 + 1, x2);
	type[idx] = 2;
	gogo(idx + 1, x1, x2 + 1);
	return;
}


int main() {
	cin >> n;
	llist.resize(n + 1);
	type.resize(n + 1);
	for (int i = 1; i <= n; i++) { // 각인구수
		cin >> arr[i];
	}

	for (int i = 1; i <= n; i++) { // 연결 리스트
		int k; cin >> k;

		for (int j = 0; j < k; j++) {
			int kk; cin >> kk;
			llist[i].push_back(kk);
		}
	}

	gogo(1, 0, 0);

	if (ret >= inf)  cout << -1;
	else cout << ret;
	return 0;

}
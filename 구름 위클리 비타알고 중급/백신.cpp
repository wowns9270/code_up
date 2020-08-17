#include<bits/stdc++.h>
using namespace std;

int n, m;


int max_num = 0;
int first_cnt = 0;
bool check[200001];

int grup = 1;
int cnt;

vector<vector<int> > arr;

void bfs(int x) {


	check[x] = true;

	queue<int> q;
	q.push(x);

	while (!q.empty()) {


		int ux = q.front();
		q.pop();

		for (int i = 0; i < arr[ux].size(); i++) {


			int nx = arr[ux][i];

			if (check[nx] == false) {
				check[nx] = true;
				q.push(nx);
				cnt++;
			}


		}

	}

}


int main() {

	cin >> n >> m;

	arr.resize(n + 1);

	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;

		arr[a].push_back(b);
		arr[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		cnt = 1;
		if (check[i] == false) {
			bfs(i);
			if (max_num < cnt) {
				first_cnt = i;
			}
			max_num = max(cnt, max_num);
		}
	}

	cout << first_cnt << " " << max_num;
	return 0;

}
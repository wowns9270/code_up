#include<bits/stdc++.h>
using namespace std;
int test,n,m;
int visit[20001];
vector<vector<int>> arr;
bool check2() {

	//1부터 연결된 간선을 통해서
	//자신과 같은 색깔이 있는지 확인해 
	// 이분그래프인지 판별한다.
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j< arr[i].size(); j++) {
			
			int x = arr[i][j];

			if (visit[i] == visit[x]) {
				return false;
			}
		}
	}
	return true;
}
void bfs(int x) {
	visit[x] = 1;
	queue<int > q;
	q.push(x);
	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int i = 0; i < arr[x].size(); i++) {
			int ux = arr[x][i];

			//방문하지 않은곳에 자신과 다른 색을 칠한다.
			if (visit[ux] == 0) {
				visit[ux] = 3 - visit[x];
				q.push(ux);
			}
			else continue;
		}
	}
	return;
}
int main() {
	cin >> test;
	while (test--) {
		memset(visit, 0, sizeof(visit));
		cin >> n >> m;
		
		//clear 하지 않으면 않의 내용은 사라지지 않아서
		// 엉뚱한 값이 나 올 수 있다.
		arr.clear();
		arr.resize(n + 1);
		for (int i = 0; i < m; i++) {
			int a, b; cin >> a >> b;
			arr[a].push_back(b);
			arr[b].push_back(a);
		}
		//그래프를 연결시켜준다.
		

		//연결되어있지 않는 그래프도 그래프다 
		//이부분을 조심해야한다
		for (int i = 1; i <= n; i++) {

			//bfs를 통해서 연결된 점을 자신과 다른 색깔로
			//칠한다.
			if (visit[i] == 0) {
				bfs(i);
			}

		}

		if (check2() == true ) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}
	return 0;
}
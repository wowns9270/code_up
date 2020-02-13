#include<bits/stdc++.h>
#define inf 500000
using namespace std;

int check[500001][2];


int main() {
	int n, m; cin >> n >> m;

	memset(check, -1, sizeof(check));
	queue<pair<int, int>> q;
	check[n][0] = 0; //Ω√¿€ 0√ 
	q.push({ n,0 });
	while (!q.empty()) {
		int x = q.front().first;
		int timee = q.front().second;
		q.pop();

		for (int y : {x - 1, x + 1, x * 2}) {

			if (y < 0 || y > inf) continue;

			if (check[y][1 - timee] == -1) {
				check[y][1 - timee] = check[x][timee] + 1;
				q.push({ y,1 - timee });
			}
		}
	}

	int ret = -1;
	for (int i = 0; ; i++) {
		m += i;

		if (m > inf) break;

		if (check[m][i % 2] <= i) {
			ret = i;
			break;
		}
	}
	cout << ret;
	return 0;
}
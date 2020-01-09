#include<bits/stdc++.h>
using namespace std;

int n, m;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
char arr[102][102];
int visit[102][102];
vector < pair<int, int>> star;
struct star_ret {int x;int y;int cnt;};
vector<star_ret> ret;
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == '*')star.push_back(make_pair(i, j));
		}
	}
	for (int i = 0; i < star.size(); i++) {
		int x = star[i].first;
		int y = star[i].second;
		int cnt = 1;
		while (1) {
			bool check = false;
			for (int i = 0; i < 4; i++) {
				int ux = x + dx[i] * cnt;
				int uy = y + dy[i] * cnt;
				if (ux<1 || uy<1 || ux>n || uy>m) {
					check = true;
					break;
				}
				if (arr[ux][uy] == '*') { continue; }
				else {check = true;break;}
			}
			if (check == false) {
				visit[x][y] = 1;
				for (int i = 0; i < 4; i++) {
					visit[x + dx[i] * cnt][y + dy[i] * cnt] = 1;
				}
				ret.push_back({ x,y,cnt });
				cnt++;
				continue;
			}
			else break;
		}
	}
	bool check2 = false;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (arr[i][j] == '*') {
				if (visit[i][j] == 0) {
					check2 = true;
					break;
				}
			}
		}
	}
	if (check2 == true) {
		cout << "-1";
		return 0;
	}
	cout << ret.size() << "\n";
	for (int i = 0; i < ret.size(); i++) {
		cout << ret[i].x << " " << ret[i].y << " " << ret[i].cnt << "\n";
	}
	return 0;
}
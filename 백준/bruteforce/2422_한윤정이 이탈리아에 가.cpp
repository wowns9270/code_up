#include<bits/stdc++.h>
using namespace std;

int n, m, ret;
int check[201][201];
vector<int>ssel;
bool gogo(int x) {
	for (int i = 0; i < ssel.size(); i++) {
		if (check[x][ssel[i]] == 1)
			return false;
	}
	return true;
}
void bruteforce(int idx, int cnt) {
	if (cnt == 3) {
		ret++;
		return;
	}
	if (idx == n + 1) return;	//°ñ¶ú´ø ¼ö¿Í Áö±Ý°í¸¦ ¼ö
	if (gogo(idx)) {
		ssel.push_back(idx);
		bruteforce(idx + 1, cnt + 1);
		ssel.pop_back();
		bruteforce(idx + 1, cnt);
	}
	else {
		bruteforce(idx + 1, cnt);
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		check[a][b] = 1;
		check[b][a] = 1;
	}
	bruteforce(1, 0);
	cout << ret;
	return 0;
}
#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;
char arr[5][5];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int ret;
unordered_set<string> llist;
void gogo(int x, int y, int cnt, string k) {
	if (cnt == 6) {
		if (llist.count(k) == 0) {
			llist.insert(k);
			ret++;
		}
		return;
	}
	for (int i = 0; i < 4; i++) {
		int ux = x + dx[i];
		int uy = y + dy[i];

		if (ux < 0 || uy < 0 || ux >= 5 || uy >= 5) continue;

		gogo(ux, uy, cnt + 1, k + arr[ux][uy]);
	}
}
//이문제는 그냥 다~해보면 된다 시간에 대한 걱정은
//각 칸당 4^6 이므로 4096가지 거기에 칸이 25개이므로 102400 정도 나온다
// 아주 충분하다~
int main() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			string a = "";
			a += arr[i][j];
			gogo(i, j, 1, a);
		}
	}
	cout << llist.size();
	return 0;
}
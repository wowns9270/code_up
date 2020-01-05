#include<bits/stdc++.h>
using namespace std;

ifstream in("ladder.inp");
ofstream out("ladder.out");

struct loop {
	int x;
	int y;
	int go_x;
	int go_y;
};
vector<loop> arr[51];
int n, ret[51], info[51][10001];
bool cmp(loop x, loop y) {
	if (x.y > y.y) return true;
	return false;
}
int main() {
	in >> n;
	while(1) {
		int a, b, c, d; in >> a >> b >> c >> d;
		if (a == 0 && b == 0 && c == 0 && d == 0) break;
		arr[a].push_back({ a,b,c,d });
		arr[c].push_back({c, d, a, b});
	}
	for (int i = 0; i < n; i++) {
		sort(arr[i].begin(), arr[i].end(), cmp);
		for (int j = 0; j < arr[i].size(); j++) {
			info[arr[i][j].go_x][arr[i][j].go_y] = j;
		}
		arr[i].push_back({ i,0,-1,-1 });
	}
	for (int i = 0; i < n; i++) {
		loop st = arr[i][0];
		while (1) {
			int go = info[st.x][st.y];
			go = go + 1;
			if (arr[st.go_x][go].y == 0) break;		
			st = arr[st.go_x][go];
		}
		ret[st.go_x] = i;
	}
	for (int i = 0; i < n; i++) {
		out << ret[i] << " ";
	}
	return 0;
}
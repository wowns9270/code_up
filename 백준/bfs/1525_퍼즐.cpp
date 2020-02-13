#include<bits/stdc++.h>
using namespace std;
map<string,int> llist;

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };


int main() {
	string n;
	int idx = -1;
	for (int i = 0; i < 9; i++) {
		int a; cin >> a;
		if (a == 0) {
			a = 9;
			idx = i;
		}
		n += to_string(a);
	}
	llist[n] = 0;
	queue<pair<string,int>> q;
	q.push({ n,idx });

	while (!q.empty()) {
		string k = q.front().first;
		int x = q.front().second / 3;
		int y = q.front().second % 3;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ux = x + dx[i];
			int uy = y + dy[i];

			if (ux < 0 || uy < 0 || ux >= 3 || uy >= 3) continue;

			string temp = k;
			swap(temp[x * 3 + y], temp[ux * 3 + uy]);
			if (llist.find(temp) == llist.end()) {
				llist[temp] = llist[k] + 1;
				q.push({ temp,ux * 3 + uy });
			}
		}
	}
	if (llist.count("123456789") == 0) {
		cout << -1;
	}
	else cout << llist["123456789"];
	return 0;
}
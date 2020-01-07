#include<bits/stdc++.h>
using namespace std;
int pre[10001], ino[10001], post[10001], n, a, b;
map<int,int> position;
ifstream in("tree.inp");
ofstream out("tree.out");
void gogo(int in_l, int in_r, int pre_l, int pre_r) {
	if (in_l > in_r || pre_l > pre_r) return;
	int root = pre[pre_l]; // 7s
	int idx = position[root]; //1
	int cnt = idx - in_l; //1
	gogo(in_l, idx - 1, pre_l + 1, pre_l + cnt);
	gogo(idx + 1, in_r, pre_l + cnt + 1, pre_r);
	out << root <<"\n";
}
void gogo2(int in_l, int in_r, int post_l, int post_r) {
	if (in_l > in_r || post_l > post_r) return;
	int root = post[post_r]; // 7
	int idx = position[root]; //1
	int cnt = idx - in_l; //1
	out << root << "\n";
	gogo2(in_l, idx - 1, post_l, post_l + cnt-1);
	gogo2(idx + 1, in_r, post_l + cnt, post_r-1);
}
int main() {
	in >> n >> a;
	for (int i = 0; i < n; i++) {
		if (a == 0) in >> ino[i];
		else if (a == -1) in >> pre[i];
		else in >> post[i];
	}
	in >> b;
	for (int i = 0; i < n; i++) {
		if (b == 0) in >> ino[i];
		else if (b == -1) in >> pre[i];
		else in >> post[i];
	}
	for (int i = 0; i < n; i++) { 
		position[ino[i]] = i; 
	}

	if ((a + b) == -1) {//post
		gogo(0, n - 1, 0, n - 1);
	}
	else {
		gogo2(0, n - 1, 0, n - 1);
	}
	return 0;
}
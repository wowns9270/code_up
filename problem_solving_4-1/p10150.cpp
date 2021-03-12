#include<bits/stdc++.h>
using namespace std;

ifstream in("p10150.inp");
ofstream out("p10150.out");
vector<string> arr;
string r , k1 , k2;

int check[30000];
int pre[30000];

bool search(string a, string b) {
	int cnt = 0;
	if (a.size() != b.size()) return false;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] != b[i]) cnt++;
	}
	if (cnt == 1) return true;
	return false;
}

void bfs(string k , int idx) {

	check[idx] = 0;
	queue<pair<string , int> > q;
	q.push({ k, idx });
	while (!q.empty()) {

		string r = q.front().first;	
		int cur = q.front().second; //이전 인덱스
		q.pop();

		for (int i = 0; i < arr.size(); i++) {
			if (check[i] == -1 && search(r, arr[i])) {
				check[i] = 0;
				pre[i] = cur;
				q.push({ arr[i], i });

			}
		}
	}
}
int main() {

	while (getline(in ,r)) {

		bool inp_check = false;
		int idx = -1;
		for (int i = 0; i < r.size(); i++) {
			if (r[i] == ' ' && r[i + 1] != ' ') {
				inp_check = true;
				idx = i;
			}
		}

		if (r == "") continue;
		else if (inp_check == false) {
			arr.push_back(r);
			continue;
		}

		k1 = r.substr(0,idx);
		k2 = r.substr(idx + 1);

		memset(check, -1, sizeof(check));
		memset(pre, -1, sizeof(pre));

		int r1, r2;
		for (int i = 0; i < arr.size(); i++) {
			if (k1 == arr[i]) r1 = i;
			if (k2 == arr[i]) r2 = i;
		}

		bfs(k1 , r1);

		vector<string> ret;


		if (pre[r2] == -1) {
			out << "No solution.\n\n";
			continue;
		}

		while (1) {	
			if (pre[r2] == -1)break;
			ret.push_back(arr[r2]);
			r2 = pre[r2];
		}

		ret.push_back(k1);
		reverse(ret.begin(), ret.end());

		for (int i = 0; i < ret.size(); i++) {
			out << ret[i] << "\n";
		}
		out << "\n";
	}
	return 0;
}
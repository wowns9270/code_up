#include<bits/stdc++.h>
using namespace std;
ifstream in("light.inp");
ofstream out("light.out");
int n,r,ret;
vector<pair<int, int>> light;
int main() {
	in >> n;
	for (int i = 0; i < n; i++) {
		int a, b; in >> a >> b;
		light.push_back(make_pair(a, b));
	}
	sort(light.begin(), light.end());
	in >> r;
	while (r--) {
		int st, ed; in >> st >> ed;
		int i = 0, state = 0;
		int max_ed = 0;ret = 0;
		while (st < ed && i < n) {
			state = 0;
			for (int j = i; j < n; j++) {
				if (st < light[j].first) break;
				if (max_ed < light[j].second) {
					max_ed = light[j].second;
					i = j;
					state = 1;
				}
			}
			if (state == 0) break;
			else {
				st = max_ed;
				ret++;
			}
		}
		if (state == 0) out << "-1\n";
		else out << ret << "\n";
	}
	return 0;
}
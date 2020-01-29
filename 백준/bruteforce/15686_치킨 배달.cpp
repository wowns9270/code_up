#include<bits/stdc++.h>
using namespace std;
#define INF 199999999

int n,m,arr[51][51],ret=INF;
vector<pair<int, int>> llist;
vector<pair<int, int>>home;
vector<int> sell;
int gogo2() {
	int sum = 0;
	for (int i = 0; i < home.size(); i++) {
		int home_ret = INF;
		for (int j = 0; j < sell.size(); j++) {
			int k = abs(home[i].first - llist[sell[j]].first);
			int k2 = abs(home[i].second - llist[sell[j]].second);
			home_ret = min(home_ret, (k + k2));
		}
		sum += home_ret;
	}
	return sum;
}
void gogo(int idx , int cnt) {
	if (idx == llist.size()) {
		if (cnt == m) {
			int k = gogo2();
			ret = min(ret, k);
		}
		return;
	}
	sell.push_back(idx);
	gogo(idx + 1, cnt + 1);
	sell.pop_back();
	gogo(idx + 1, cnt);
}

// ㅎㅎ 다시푸니까 너무 쉬웠다 
//각각의 치킨집을 llist에 넣어주고 각 집에서 가장 가까운 치킨거리를 구해서
//더해주고 가장 작은 합의 값을 뽑아내주면 된다~~~
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) {
				llist.push_back({ i,j });
			}
			if (arr[i][j] == 1) {
				home.push_back({ i,j });
			}
		}
	}
	gogo(0,0);
	cout << ret;
	return 0;
}
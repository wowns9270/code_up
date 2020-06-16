#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> arr;
int r, c, k, x, y;
bool cmp(pair<int, int> x, pair<int, int> y) {
	if (x.second < y.second) {
		return true;
	}
	else if (x.second == y.second) {
		if (x.first < y.first) {
			return true;
		}
	}
	return false;
}
void gogo() { //행변환
	int max_y = 0;
	for (int i = 0; i < x; i++) {
		map<int, int> llist;
		for (int j = 0; j < y; j++) {
			int kx = arr[i][j];

			if (kx == 0)	 continue;
			llist[kx] ++;
		}
		vector<pair<int, int>> temp2;
		for (auto it = llist.begin(); it != llist.end(); it++) {

			int kx = it->first;
			int cost = it->second;

			temp2.push_back({ kx,cost });
		}
		sort(temp2.begin(), temp2.end(), cmp);
		vector<int>temp(201, 0);
		int idx = 0;
		for (int i = 0; i < temp2.size(); i++) {
			int kx = temp2[i].first;
			int cost = temp2[i].second;

			temp[idx++] = kx;
			temp[idx++] = cost;
		}
		int size = idx;
		temp.erase(temp.begin() + 100, temp.end());

		max_y = max(max_y, size);
		arr[i] = temp;
	}
	y = max_y;
	return;
}
void gogo2() {
	int max_x = 0;
	for (int i = 0; i < y; i++) { // 열 
		map<int, int> llist;
		for (int j = 0; j < x; j++) { //형
			int kx = arr[j][i];
			if (kx == 0)	 continue;
			llist[kx] ++;
		}
		vector<pair<int, int>> temp2;
		for (auto it = llist.begin(); it != llist.end(); it++) {
			int kx = it->first;
			int cost = it->second;
			temp2.push_back({ kx,cost });
		}
		sort(temp2.begin(), temp2.end(), cmp);
		vector<int> temp(201, 0);
		int idx = 0;
		for (int i = 0; i < temp2.size(); i++) {
			int kx = temp2[i].first;
			int cost = temp2[i].second;

			temp[idx++] = kx;
			temp[idx++] = cost;
		}
		int size = idx;
		temp.erase(temp.begin() + 100, temp.end());
		max_x = max(max_x, size);
		for (int e = 0; e < 100; e++) arr[e][i] = 0;
		for (int w = 0; w < size; w++) {
			arr[w][i] = temp[w];
		}
	}
	x = max_x;
	return;
}
int main() {
	cin >> r >> c >> k;
	arr.resize(100, vector<int>(100));
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			int q; cin >> q;
			arr[i][j] = q;
		}
	}
	int a = 0;
	x = 3, y = 3;
	while (1) {
		if (a >= 101) break;
		if (arr[r - 1][c - 1] == k) {
			cout << a;
			return 0;
		}
		if (x >= y) {
			gogo();
		}
		else {
			gogo2();
		}
		a++;
	}
	cout << -1;
	return 0;
}
#include<bits/stdc++.h>	
using namespace std;
vector<pair<int, int>> arr;
int n;
int cnt;
void gogo(int n, int from, int by, int to) {
	if (n == 0) return;
	cnt++;
	gogo(n - 1, from, to, by);
	/*cout << from << " " << to<<"\n";*/
	arr.push_back(make_pair(from, to));
	gogo(n - 1, by, from, to);
}
int main() {
	cin >> n;
	gogo(n, 1, 2, 3);
	cout << arr.size() << "\n";
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i].first << " " << arr[i].second << "\n";
	}
	return 0;
}
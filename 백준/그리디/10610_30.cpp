#include<bits/stdc++.h>
using namespace std;

vector<int> arr;

bool cmp(int x, int y) {
	if (x > y) return true;
	return false;
}
int check;

//30의 배수일려면 1의 자리가 0으로 끝나고
//각 자리 합이 3의 배수가 되야한다
int main() {
	string n; cin >> n;

	for (int i = 0; i < n.size(); i++) {
		char c = n[i];
		int  k = c - 48;
		check += k;
		arr.push_back(k);
	}
	sort(arr.begin(), arr.end(), cmp);

	if (check % 3 == 0 && arr[arr.size() - 1] == 0) {
		for (int i = 0; i < arr.size(); i++) {
			cout << arr[i];
		}
	}
	else cout << "-1";
	return 0;
}
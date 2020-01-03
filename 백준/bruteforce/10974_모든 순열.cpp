#include<bits/stdc++.h>
using namespace std;
int n;
int visit[9];
vector<int> arr;

void bruteforce(int idx) {
	if (idx == n + 1) {
		for (int a : arr) {
			cout << a << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (visit[i] == false) {
			visit[i] = true;
			arr.push_back(i);
			bruteforce(idx + 1);
			arr.pop_back();
			visit[i] = false;
		}
	}


}

int main() {
	cin >> n;

	bruteforce(1);

}
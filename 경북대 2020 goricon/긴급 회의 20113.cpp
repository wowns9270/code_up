#include<bits/stdc++.h>
using namespace std;

int arr[101] ,n;

int main() {
		
	cin >> n;

	for (int i = 0; i < n; i++) {

		int a; cin >> a;

		arr[a]++;
	}

	int cnt = 0;
	int max_n = -1;
	int max_idx = -1;


	for (int i = 0; i <= n; i++) {

		if (max_n < arr[i]) {
			max_n = arr[i];
			max_idx = i;
			cnt = 1;
		}
		else if (max_n == arr[i]) {
			max_idx = i;
			cnt++;
			continue;
		}
	}

	if (cnt == 1) {
		
		if (max_idx == 0){
			cout<<"skipped";
		}
		else
		cout << max_idx;
	}
	else if (cnt == 2) {

		if (max_n == arr[0]) cout << max_idx;
		else {
			cout << "skipped";
		}
	}
	else {
		cout << "skipped";
	}
	return 0;
}
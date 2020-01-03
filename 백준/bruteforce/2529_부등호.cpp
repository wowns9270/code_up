#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<char> compare;
vector<int> big;
vector<int> small;

bool check_cc(vector<int>& arr) {
	for (int i = 0; i < compare.size(); i++) {
		if (compare[i] == '<') {
			if (arr[i] >= arr[i + 1]) return true;
		}
		else if (compare[i] == '>') {
			if (arr[i] <= arr[i + 1]) return true;
		}
	}

	return false;
}

void small_brouteforce() {

	while (1) {
		if (check_cc(small) == true)
			next_permutation(small.begin(), small.end());
		else {
			for (int i = 0; i < big.size(); i++) {
				cout << small[i];
			}
			cout << "\n";
			break;
		}

	}
}

void big_brouteforce() {

	while (1) {
		if (check_cc(big) == true)
			prev_permutation(big.begin(), big.end());
		else {
			for (int i = 0; i < big.size(); i++) {
				cout << big[i];
			}
			cout << "\n";
			break;
		}

	}
}

int main() {
	int n; cin >> n;

	for (int i = 0; i < n; i++) {
		char c; cin >> c;
		compare.push_back(c);
	}

	for (int i = 0; i < n + 1; i++) {
		big.push_back(9 - i);
		small.push_back(i);
	}

	big_brouteforce();
	small_brouteforce();
	return 0;

}